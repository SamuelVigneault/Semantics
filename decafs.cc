//#define Tokens


#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include "parsetree.h"
#include "semantics.h"  // for variable scopes and semantics objects

extern FILE* yyin;
extern Token *myTok;
extern int yylineno;
extern ParseTree *top;
extern int yydebug;

using namespace std;

int yylex();
int yyparse();

extern vector<string> usertypes;

extern Symtab *topSS;
extern Symtab *currentSS;

extern S_class* currentClass;
extern S_function * currentFunc;
 
int looper = 0;
int LN = 0;
// ALL ERROR MESSAGES
string func1 = "Variable redefined in the function's arguments";
string print1 = "Arguments passed to print statements cannot be arrays";
string print2 = "Arguments passed to print statements must be ints, bools, or strings";
string while1 = "Type of expression of 'while' loop is not 'boolean'";
string for1 = "Type of middle expression of 'for' loop is not of boolean type";
string return1 = "Type of return statement does not match function return type";
string stmtblock1 = "Variable redefined in statement block";
string classcope1 = "Identifier redefined in the class scope";
string classscope2 = " redefined in the class scope";
string interface1 = " redefined in the interface scope";
string aref1 = "Cannot access object in a non-array object";
string new1 = "Argument of 'New' must be the name of a defined class";
string newarray1 = "Identifier redefined in the class scope";
string typeerror1 = "Parsing error revealed in basetype";
string global1 = " redefined in the global scope";
string par1 = " is not a class type object";
string par2 = " is not defined in this scope";
string subclass1 = " cannot be a subclass of itself";

ParseTree * parse_decaf(FILE *);

S_type* basetype(ParseTree *type_tree, int arr = 0) {
  if (type_tree->description=="arraytype")
    return basetype(type_tree->children[0], arr + 1);
  else if (type_tree->description=="primtype" || type_tree->description=="usertype") {
    S_type * typer = new S_type();
    typer->name = type_tree->children[0]->token->text;
    LN = type_tree->children[0]->token->line;
    typer->array = arr;
    return typer;}
  else { semantic_error(typeerror1, LN); return nullptr; }
}

S_function * functions_signature(ParseTree * tree){
  	S_function * F;
	F = new S_function();
  	F->name = tree->children[1]->token->text;
  	LN = tree->children[1]->token->line;
  	F->line = LN;
  	if (tree->children[0]->token) { F->returnType = NULL; }
  	else { F->returnType = basetype(tree->children[0]); }
  	openscope();
 	tree->symtab = currentSS;
  	for (size_t i=0; i < tree->children[2]->children.size(); i++) {
   		S_variable * V = new S_variable;
    	V->name = tree->children[2]->children[i]->children[1]->token->text;
    	V->type = basetype(tree->children[2]->children[i]->children[0]);
    	LN = tree->children[2]->children[i]->children[1]->token->line;
    	V->line = LN;
    	if (currentSS->dict.count(V->name) == 1) { semantic_error(func1, LN); }
    F->formals.push_back(V);
    currentSS->insert(V->name, V); }
  closescope();
  return F;
}

S_class * class_read(ParseTree * tree) {
  S_class* C = new S_class();
  C->name = tree->children[0]->token->text;
  LN = tree->children[0]->token->line;
  C->line = LN;
  if (tree->children[1]) { C->parentClass = tree->children[1]->children[0]->token->text; }
  else { C->parentClass = ""; }
  if (tree->children[2]) {
  	for (size_t i=0; i < tree->children[2]->children.size(); i++)
    C->interfaces.push_back(tree->children[2]->children[i]->token->text);
  }
  // Storing all the fields into our class *************************************
  openscope();
  tree->symtab = currentSS;
  ParseTree * fields = tree->children[3];
  for (size_t i=0; i < fields->children.size(); i++) {
    ParseTree * field = fields->children[i];
    if (field->description == "functiondecl") {
      S_function * F = functions_signature(field);
      if (currentSS->dict.count(F->name) == 1) { semantic_error("Identifier " + F->name + classscope2, F->line); }
      currentSS->insert(F->name, F);
      C->functions.push_back(F);
    }
    else if (field->description == "variable") {
      S_variable * V = new S_variable();
      V->name = field->children[1]->token->text;
      LN =  field->children[1]->token->line;
      V->line = LN;
      V->type = basetype(field->children[0]);
      if (currentSS->dict.count(V->name) == 1) { semantic_error("Identifier " + V->name + classscope2, V->line); }
      currentSS->insert(V->name, V);
      C->variables.push_back(V);
    }
  }
  closescope();
  return C;
}
  
void traversing1(ParseTree * tree) {
  if (tree->description == "interface") {
    S_interface* I = new S_interface();
    I->name = tree->children[0]->token->text;
    I->line = tree->children[0]->token->line;
    openscope();
    tree->symtab = currentSS;
    for (size_t i=1; i < tree->children.size(); i++) {
      S_function * F = functions_signature(tree->children[i]);
      if (currentSS->dict.count(F->name) == 1) { semantic_error("Identifier " + F->name + interface1, F->line); }
      currentSS->insert(F->name, F);
      I->functions.push_back(F);
    }
    closescope();
    LN = tree->children[0]->token->line;
    if (currentSS->dict.count(I->name) == 1) { semantic_error("Identifier " + I->name + global1, I->line); }
    currentSS->insert(I->name, I);
    usertypes.push_back(I->name);
  }
  if (tree->description == "class") {
    S_class* C = class_read(tree);
    if (currentSS->dict.count(C->name) == 1) { semantic_error("Identifier " + C->name + global1, C->line); }
    currentSS->insert(C->name, C);
    usertypes.push_back(C->name);
  }
  if (tree->description == "variable"){
    S_variable * V = new S_variable();
    V->name = tree->children[1]->token->text;
    V->type = basetype(tree->children[0]);
    LN = tree->children[1]->token->line;
    if (currentSS->dict.count(V->name) == 1) { semantic_error("Identifier " + V->name + global1, V->line); }
    currentSS->insert(V->name, V);
  }
  if (tree->description == "functiondecl"){
    S_function * F = functions_signature(tree);
    if (currentSS->dict.count(F->name) == 1) { semantic_error("Identifier " + F->name + global1, C->line); }
    currentSS->insert(F->name, F);
  }
}

void check_parents() {
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)){
      S_class * A = dynamic_cast<S_class *>(it->second);
      if (A->parentClass != "") {
			if (topSS->local_lookup(A->parentClass)) {
	  			if (topSS->local_lookup(A->parentClass)->kind() != "S_class") { semantic_error("Parent of class "+A->name+par1, A->line); }}
			else { semantic_error("Parent of class "+ A->name +par2, A->line); }}}}}

void check_loops() {
  for (map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)) {
      S_class * A = dynamic_cast<S_class *>(it->second);
      S_class * B = dynamic_cast<S_class *>(it->second);
      while (true) {
        	if (B->parentClass == A->name) semantic_error("Class "+A->name+ subclass1, A->line);
        	if (B->parentClass == "") break;
			for (std::map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  			if (dynamic_cast<S_class *>(it1->second) && dynamic_cast<S_class*>(it1->second)->name == B->parentClass) {
	    			B = dynamic_cast<S_class *>(it1->second); }}}}}}

void check_implements() {
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)) {
      S_class * A = dynamic_cast<S_class *>(it->second);
      for (unsigned int i=0; i < A->interfaces.size(); i++) {
	if (topSS->local_lookup(A->interfaces[i])) {
	  if (topSS->local_lookup(A->interfaces[i])->kind()!= "S_interface")
	    semantic_error(A->interfaces[i]+" implemented by class "+A->name+ " is not an interface", yylineno);
	}
	else
	  semantic_error("Interface "+A->interfaces[i]+" implemented by class "+A->name+ " is not defined", yylineno);
      }}}}

bool check_type_signature(S_function * father, S_function * son) {
  bool AA = (father->returnType->name == son->returnType->name);
  bool BB = (father->returnType->array == son->returnType->array);
  bool CC = (father->formals.size() == son->formals.size());
  if (AA && BB && CC) {
    for (unsigned int y=0; y < son->formals.size(); y++) {
      if (son->formals[y]->type->name != father->formals[y]->type->name) return false;
      if (son->formals[y]->type->array != father->formals[y]->type->array) return false;
    }}
  else return false;
  return true;
}

void check_implements2(ParseTree * tree) {
  for (map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)){
      S_class * C = dynamic_cast<S_class *>(it->second);
      for (unsigned int i=0; i < C->interfaces.size(); i++) {
	S_interface* inter1;
	for (map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  if (dynamic_cast<S_interface *>(it1->second) && it1->first == C->interfaces[i])
	    inter1 = dynamic_cast<S_interface*>(it1->second);
	}
    Symtab * currenttab;
	for (size_t j=0; j < tree->children.size(); j++) {
	  if (tree->children[j]->description == "class") {
	    if (tree->children[j]->children[0]->token->text == C->name) {
		currenttab = tree->children[j]->symtab;
		break;
	      }}}
	for (unsigned int k=0; k <  inter1->functions.size(); k++) {
	  bool found1 = false;
	  S_function * FI =  inter1->functions[k];
	  for (map<string, semantics *>::iterator it1=currenttab->dict.begin(); it1!=currenttab->dict.end(); ++it1) {
	    if (dynamic_cast<S_function *>(it1->second)) {
	      if(dynamic_cast<S_function *>(it1->second)->name == FI->name) {
	        S_function * FUNC = dynamic_cast<S_function *>(it1->second);
	        if (check_type_signature(FUNC, FI)) { found1 = true; }
	        break;
	      }}}
	  if (!found1)
	    semantic_error("Class "+C->name+" does not implement all methods of the '"+inter1->name+ "' interface", yylineno);
	}}}}}

void check_parents2(ParseTree * tree) {
  vector<string> done;
  for (map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    if (dynamic_cast<S_class *>(it->second)) {
      S_class * A = dynamic_cast<S_class *>(it->second);
      S_class * B = dynamic_cast<S_class *>(it->second);
      Symtab * currenttab;
      Symtab * othertab;
      for (size_t i=0; i < tree->children.size(); i++) { // looping through the children of top (topscope)
		if (tree->children[i]->description == "class") { 
	 		if (tree->children[i]->children[0]->token->text == A->name) {
	    		currenttab = tree->children[i]->symtab;
	    		break;
	  		}}}
      while (true) {
	if (A != B) {
	  for (std::map<string, semantics *>::iterator it2=othertab->dict.begin(); it2!=othertab->dict.end(); ++it2) {
	  	// looping through the non completed parent class scope
	    if (currenttab->dict.count(it2->first) == 1) {
	      if (dynamic_cast<S_function*>(currenttab->dict[it2->first]) && dynamic_cast<S_function*>(it2->second)) {
				S_function * FUNC1 = dynamic_cast<S_function*>(currenttab->dict[it2->first]);
				S_function * FUNC2 = dynamic_cast<S_function*>(it2->second);
				if (!check_type_signature(FUNC1, FUNC2)) {semantic_error("Subclass "+A->name+" cannot overwrite a function from the '"+B->name+"' class", yylineno); }}
	      	else { semantic_error("Subclass "+A->name+" cannot overwrite a variable from the '"+B->name+"' class", yylineno); }}
	    else currenttab->insert(it2->first, it2->second); }}
	if (B->parentClass == "") { done.push_back(A->name); break; }
	bool found = false;
	for (unsigned int i = 0; i < done.size(); i++) { if (B->name == done[i]) { done.push_back(A->name); found = true; }}
	if (found) { break; }
	for (std::map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  if (dynamic_cast<S_class *>(it1->second) && dynamic_cast<S_class*>(it1->second)->name == B->parentClass)
	    B = dynamic_cast<S_class*>(it1->second); }
	for (size_t i=0; i < tree->children.size(); i++) {
	  if (tree->children[i]->description == "class") {
	    if (tree->children[i]->children[0]->token->text == B->name) {
	      othertab = tree->children[i]->symtab;
	      break;
	    }}}
      }}}}
  
  
S_type * type_creator(string AAA) {
	S_type * one = new S_type;
	one->name == AAA;
	return one;
}
  
S_type * expressionhandler(ParseTree * tree) {
	S_type * one = new S_type;
	if (tree->description == "binop") {
		int type = tree->children[1]->token->type;
		if (type == 38) { cout << "HEYY THERE" << endl; }
		else if (type == 41 || type == 42) { 
			S_type * L = expressionhandler(tree->children[0]);
			S_type * R = expressionhandler(tree->children[2]);
			if (L->name == "bool" && R->name == "bool" && L->array == 0 && R->array == 0) { return L; }
			else { semantic_error("To be written", LN); }
		}
		else if (type == 39 || type == 40) { 
			S_type * L = expressionhandler(tree->children[0]);
			S_type * R = expressionhandler(tree->children[2]); 
			if (L->name == R->name && L->array == R->array) { return type_creator("bool"); } //TYPECOMPAT
			else { semantic_error("To be written", LN); }
		}
		else if (type > 33 && type < 38) { 
			S_type * L = expressionhandler(tree->children[0]);
			S_type * R = expressionhandler(tree->children[2]); 
			if (L->name == R->name && (L->name == "int" || L->name == "double") && L->array == 0 && R->array == 0) { return type_creator("bool"); }
			else { semantic_error("To be written", LN); }
		}
		else if (type > 28 && type < 34) { 
			S_type * L = expressionhandler(tree->children[0]);
			S_type * R = expressionhandler(tree->children[2]); 
			if (L->name == R->name && (L->name == "int" || L->name == "double") && L->array == 0 && R->array == 0) { return L; }
			else { semantic_error("To be written", LN); }
		 }
	}
	else if (tree->description == "uop") {
		
	}
	else if (tree->description == "aref"){
		S_type * L = expressionhandler(tree->children[0]);
		S_type * R = expressionhandler(tree->children[2]); 
		if (!(R->name == "int" && R->array == 0)) { semantic_error("To be written", LN); }
		else if (!(L->array > 0)) { semantic_error(aref1, LN); }
		else { L->array--; return L; }
	} 
	else if (tree->description == "call"){
		if (tree->children[0]->token) {
			bool found = false;
			for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    			if (dynamic_cast<S_function *>(it->second) && it->first == tree->children[0]->token->text) {
    				found = true; }}
    	LN = tree->children[0]->token->line;
    	if (! found) { semantic_error("To be written", LN); }
    	for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
			S_type * T = expressionhandler(tree->children[0]); 
			if (!(T->array == 0)) { semantic_error(print1, LN); } 
			if (!(T->name == "int" || T->name == "bool" || T->name == "string")) { semantic_error(print2, LN); } 
		}
		else  
		S_type * L = expressionhandler(tree->children[0]);
		S_type * R = expressionhandler(tree->children[2]); 
		if (!(R->name == "int" && R->array == 0)) { semantic_error("To be written", LN); }
		else if (!(L->array > 0)) { semantic_error("To be written", LN); }
		else { L->array--; return L; }
	} 
	
	else if (tree->description == "new") {
		bool found = false;
		for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    		if (dynamic_cast<S_class *>(it->second) && it->first == tree->children[0]->token->text) {
    			found = true;}}
    	LN = tree->children[0]->token->line;
    	if (! found) { semantic_error(new1, LN); }
    	else {return type_creator(tree->children[0]->token->text); }
	}
	else if (tree->description == "newarray") {
		S_type * L = expressionhandler(tree->children[0]);
		if (!(L->name == "int" &&  L->array == 0)) { semantic_error("New", LN); }
		S_type * R = basetype(tree->children[1]); 
		R->array++;
		return R;
	}
	else if (tree->description == "readline") { return type_creator("string"); }
	else if (tree->description == "readinteger") { return type_creator("int"); }
	else if (tree->token) {
		if (tree->token->type == 25) { return type_creator("int"); }
		if (tree->token->type == 26) { return type_creator("bool"); }
		if (tree->token->type == 27) { return type_creator("double"); }
		if (tree->token->type == 28) { return type_creator("string"); }
		if (tree->token->type == 9) {
			if (currentClass) { return type_creator(currentClass->name); }
			else { semantic_error("To be written", LN);}
			}
		
	}
return one;
}
  
void stmthandler(ParseTree * tree) {
	if (tree->description == "print") {
		LN = tree->children[0]->token->line;
		for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
			S_type * T = expressionhandler(tree->children[0]); 
			if (!(T->array == 0)) { semantic_error(print1, LN); } 
			if (!(T->name == "int" || T->name == "bool" || T->name == "string")) { semantic_error(print2, LN); } 
		}}
	else if (tree->description == "while") {
		looper++;
		S_type * mustbool = expressionhandler(tree->children[0]); 
		if (!(mustbool->name == "bool" && mustbool->array == 0)) {semantic_error(while1, LN); } 
		stmthandler(tree->children[1]);
		looper--;
	}
	else if (tree->description == "for") {
		looper++;
		cout <<"TROLLL"<<endl;
		expressionhandler(tree->children[0]); 
		S_type * mustbool = expressionhandler(tree->children[1]); 
		if (!(mustbool->name == "bool" && mustbool->array == 0)) {
			semantic_error(for1, LN); }
		expressionhandler(tree->children[2]); 
		stmthandler(tree->children[3]); 
		looper--;
	}
	else if (tree->description == "break") {
		LN = tree->children[0]->token->line;
		if (looper == 0){ semantic_error("Break statement outside a loop", LN); }}
	else if (tree->description == "return") {
		LN = tree->children[0]->token->line;
		if (tree->children.size() == 1) {
			if (!(currentFunc->returnType == NULL)) { semantic_error(return1, LN); }}
		else { 
		S_type * returnT = expressionhandler(tree->children[1]);
		if (returnT->array != currentFunc->returnType->array || returnT->name != currentFunc->returnType->name)  {
			LN = tree->children[0]->token->line;
			semantic_error(return1, LN); }}}
	else if (tree->description == "if") {}
	else if (tree->description == "stmtblock") { 
		openscope();
		tree->symtab = currentSS;
		for (size_t i=0; i < tree->children[0]->children.size(); i++) {
			S_variable * V;
      		V = new S_variable();
      		V->name = tree->children[0]->children[i]->children[1]->token->text;
      		LN = tree->children[0]->children[i]->children[1]->token->line;
      		V->type = basetype(tree->children[0]->children[i]->children[0]);
      		if (currentSS->dict.count(V->name) == 1) { semantic_error(stmtblock1, LN);  }
      		currentSS->insert(V->name, V); }
      	for (size_t i=0; i < tree->children[1]->children.size(); i++) { stmthandler(tree->children[1]->children[i]); }
      	closescope(); }
	else  { expressionhandler(tree); }
}

void traversing2(ParseTree * tree) {
if (tree->description == "interface" || tree->description == "variable") {return;}
else if (tree->description == "functiondecl") {
	currentFunc = dynamic_cast<S_function *>(topSS->local_lookup(tree->children[1]->token->text));
	LN = tree->children[1]->token->line;
	currentSS = tree->symtab;
	stmthandler(tree->children[3]);}
else if (tree->description == "class") {
	for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    	if (dynamic_cast<S_class *>(it->second) && it->first == tree->children[0]->token->text) {
    		LN = tree->children[0]->token->line;
    		currentClass = dynamic_cast<S_class *>(it->second); 
    		currentSS = tree->symtab; }}
    for (size_t i=0; i < tree->children[3]->children.size(); i++) {
    	if (tree->children[3]->children[i]->description == "functiondecl") {
    			currentFunc = dynamic_cast<S_function *>(currentSS->local_lookup(tree->children[3]->children[i]->children[1]->token->text));
				currentSS = tree->children[i]->symtab;
				stmthandler(tree->children[3]->children[i]->children[3]);}}}}
    		
int main(int argc, char **argv) { 
  /* Make sure there's a given file name */
  if (argc != 2) {
    cout << "USAGE: " << argv[0] << " FILE" << endl;
    exit(1);
  }       
  yyin = fopen(argv[1], "r");
  /* and that it exists and can be read */
  if (!yyin) {
    cout << argv[1] << ": No such file or file can't be opened for reading." 
	 << endl;
    exit(1);
  }

  //yydebug = 0;
#ifdef Tokens
  int tok;
  while ((tok=yylex()) != -1) {
    cout << tok << ' ';
    myTok->print();
  } 
  return 0; 
#else
  openscope();  // create original scope
  topSS = currentSS;
  top = parse_decaf(yyin);
  top->symtab = topSS;
  for (size_t i=0; i < top->children.size(); i++)
    traversing1(top->children[i]);
  check_parents(); 							// makes sure every class' parent is declared
  check_loops(); 								// makes sure no class is a subclass of itself
  check_parents2(top); 				// modifies each class scope to include its parents' objects
  check_implements(); 					// makes sure every class' interfaces are declared
  check_implements2(top);			// makes sure every class' interfaces' functions are defined in the class scope
  for (size_t i=0; i < top->children.size(); i++) {
  	currentClass = nullptr;
  	currentFunc = nullptr;
  	cout << "LOLOLOL" << endl;
  	traversing2(top->children[i]);
  }
  traverseTree(top, 0, 1);
  return 0;
#endif
}

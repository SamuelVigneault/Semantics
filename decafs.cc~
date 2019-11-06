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
extern vector<S_function *> global_funcs;

extern Symtab *topSS;
extern Symtab *currentSS;

extern S_class* currentClass;
extern S_function * currentFunc;

ParseTree * parse_decaf(FILE *);


S_type* basetype(ParseTree *type_tree, int arr = 0) {
  if (type_tree->description=="arraytype")
    return basetype(type_tree->children[0], arr + 1);
  else if (type_tree->description=="primtype" || type_tree->description=="usertype") {
    S_type * typer;
    typer = new S_type();
    typer->name = type_tree->children[0]->token->text;
    typer->array = arr;
    return typer;
  }
  else
    cout << "SHITTTT" << endl;
    return nullptr;
}

S_function * functions_signature(ParseTree * tree){
  S_function * func;
  func = new S_function();
  func->name = tree->children[1]->token->text;
  if (tree->children[0]->token) func->returnType = NULL;
  else func->returnType = basetype(tree->children[0]);
  openscope();
  tree->symtab = currentSS;
  for (size_t i=0; i < tree->children[2]->children.size(); i++) {
    S_variable * vari;
    vari = new S_variable;
    vari->name = tree->children[2]->children[i]->children[1]->token->text;
    vari->type = basetype(tree->children[2]->children[i]->children[0]);
    if (currentSS->dict.count(vari->name) == 1)
      semantic_error("Identifier redefined in the scope", yylineno);
    func->formals.push_back(vari);
    currentSS->insert(vari->name, vari);
  }
  closescope();
  return func;
}

S_class * class_read(ParseTree * tree) {
  S_class* class1;
  class1 = new S_class();
  class1->name = tree->children[0]->token->text;
  if (tree->children[1])
    class1->parentClass = tree->children[1]->children[0]->token->text;
  else
    class1->parentClass = "";
  if (tree->children[2]) {
  for (size_t i=0; i < tree->children[2]->children.size(); i++)
    class1->interfaces.push_back(tree->children[2]->children[i]->token->text);
  }
  // Storing all the fields into our class *************************************
  openscope();
  tree->symtab = currentSS;
  ParseTree * fields = tree->children[3];
  for (size_t i=0; i < fields->children.size(); i++) {
    ParseTree * field = fields->children[i];
    if (field->description == "functiondecl") {
      S_function * func;
      func = functions_signature(field);
      if (currentSS->dict.count(func->name) == 1)
	semantic_error("Identifier redefined in the scope", yylineno);
      currentSS->insert(func->name, func);
      class1->functions.push_back(func);
    }
    else if (field->description == "variable") {
      S_variable * vari;
      vari = new S_variable();
      vari->name = field->children[1]->token->text;
      vari->type = basetype(field->children[0]);
      if (currentSS->dict.count(vari->name) == 1)
	semantic_error("Identifier redefined in the scope", yylineno);
      currentSS->insert(vari->name, vari);
      class1->variables.push_back(vari);
    }
  }
  closescope();
  return class1;
}
  
void traversing1(ParseTree * tree) {
  if (tree->description == "interface") {
    S_interface* inter;
    inter = new S_interface();
    inter->name = tree->children[0]->token->text;
    openscope();
    tree->symtab = currentSS;
    for (size_t i=1; i < tree->children.size(); i++) {
      S_function * func;
      func = functions_signature(tree->children[i]);
      if (currentSS->dict.count(func->name) == 1)
	semantic_error("Identifier redefined in the scope", yylineno);
      currentSS->insert(func->name, func);
      inter->functions.push_back(func);
    }
    closescope();
    if (currentSS->dict.count(inter->name) == 1)
      semantic_error("Identifier "+inter->name+" redefined in the scope",yylineno);
    currentSS->insert(inter->name, inter);
    usertypes.push_back(inter->name);
  }
  if (tree->description == "class") {
    S_class* class1 = class_read(tree);
    // Checking availability in scope and storing *********************************
    if (currentSS->dict.count(class1->name) == 1)
      semantic_error("Identifier redefined in the scope", yylineno);
    currentSS->insert(class1->name, class1);
    usertypes.push_back(class1->name);
  }
  if (tree->description == "variable"){
    S_variable * vari;
    vari = new S_variable();
    vari->name = tree->children[1]->token->text;
    vari->type = basetype(tree->children[0]);
    if (currentSS->dict.count(vari->name) == 1)
      semantic_error("Identifier redefined in the scope", yylineno);
    currentSS->insert(vari->name, vari);
  }
  if (tree->description == "functiondecl"){
    S_function * func;
    func = functions_signature(tree);
    if (currentSS->dict.count(func->name) == 1)
      semantic_error("Identifier redefined in the scope", yylineno);
    currentSS->insert(func->name, func);
    global_funcs.push_back(func);
  }
}

void check_parents() {
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)){
      S_class * A = dynamic_cast<S_class *>(it->second);
      if (A->parentClass != "") {
	if (topSS->local_lookup(A->parentClass)) {
	  if (topSS->local_lookup(A->parentClass)->kind()!= "S_class")
	    semantic_error("Parent of class "+A->name+" is not a class type object", yylineno);
	}
	else
	  semantic_error("Parent of class "+ A->name + " is not defined in this scope", yylineno);
      }}}}

void check_loops() {
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)) {
      S_class * A = dynamic_cast<S_class *>(it->second);
      S_class * B = dynamic_cast<S_class *>(it->second);
      while (true) {
        if (B->parentClass == A->name)
	  semantic_error("Class "+A->name+" cannot be a subclass of itself", yylineno);
        if (B->parentClass == "")
	  break;
	for (std::map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  if (dynamic_cast<S_class *>(it1->second) && dynamic_cast<S_class*>(it1->second)->name == B->parentClass) {
	    B = dynamic_cast<S_class *>(it1->second);
	  }}
      }}}}

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
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    if (dynamic_cast<S_class *>(it->second)){
      S_class * C = dynamic_cast<S_class *>(it->second);
      for (unsigned int i=0; i < C->interfaces.size(); i++) {
	S_interface* inter1;
	for (std::map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
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
  for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
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
  
void functionhandler() { return;}

void traversing2(ParseTree * tree) {
if (tree->description == "interface" || tree->description == "variable") {return;}
if (tree->description == "functiondecl") {
	currentFunc = dynamic_cast<S_function *>(topSS->local_lookup(tree->children[1]->token->text));
	currentSS = tree->symtab;
	functionhandler();
}
if (tree->description == "class") {
	for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    	if (dynamic_cast<S_class *>(it->second) && it->first ==tree->children[0]->token->text) {
    		currentClass = dynamic_cast<S_class *>(it->second); 
    		currentSS = tree->symtab; }}
    for (size_t i=0; i < tree->children.size(); i++) {
    	if (tree->children[i]->description == "functiondecl") {
    		currentFunc = dynamic_cast<S_function *>(currentSS->local_lookup(tree->children[i]->children[1]->token->text));
			currentSS = tree->children[i]->symtab;
			functionhandler();}}}}
    		
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

  yydebug = 1;
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
  for (size_t i=0; i < top->children.size(); i++)
    traversing2(top->children[i]);
  //traverseTree(top, 0, 1);
  return 0;
#endif
}

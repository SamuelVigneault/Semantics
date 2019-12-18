//#define Tokens

#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <sstream>
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
 
vector < tuple <string, string>> compat;

bool ass = false;
int looper = 0;
int LN = 0;
int var0 = 0;
int TD2 = 30;
int label = 0;
string out = "";

// ALL ERROR MESSAGES
string func1 = "Variable redefined in the function's arguments";
string print1 = "Arguments passed to print statements cannot be arrays";
string print2 = "Arguments passed to print statements must be ints, bools, or strings";
string while1 = "Type of expression of 'while' loop is not 'boolean'";
string for1 = "Type of middle expression of 'for' loop is not of boolean type";
string return1 = "Type of return statement does not match function return type";
string stmtblock1 = "Variable redefined in statement block";
string classcope1 = "Identifier redefined in the class scope";
string aref1 = "Cannot access object in a non-array object";
string aref2 = "Array references' argument inside the brackets has to be of type 'int'";
string new1 = "Argument of 'New' must be the name of a defined class";
string newarray1 = "Identifier redefined in the class scope";
string typeerror1 = "Parsing error revealed in basetype";
string break1 = "Break statement outside a loop";
string ifstmt1 = "The epression of an 'if' statement must be of 'bool' type";
string typevar = "Type of variable is not defined";
string typefunc = "Return type of function/method is not defined";

string classscope2 = " redefined in the class scope";
string interface1 = " redefined in the interface scope";
string global1 = " redefined in the global scope";
string global2 = " is not defined in the global scope";
string par1 = " is not a class type object";
string par2 = " is not defined in this scope";
string subclass1 = " cannot be a subclass of itself";
string def1 = " does not match the definition";

ParseTree * parse_decaf(FILE *);


string ITOS ( int I ){
	std::ostringstream ss;
   ss << I;
   return ss.str();
}
  
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

S_type * type_creator(string AAA, int arr = 0) {
	S_type * one = new S_type;
	one->name = AAA;
	one->array = arr;
	return one;
}

bool ensure_type(S_type * T) {
	if (!T) return true;
	if (T->name == "int") return true;
	if (T->name == "bool") return true;
	if (T->name == "double") return true;
	if (T->name == "string") return true;
	if (T->name == "void") return true;
	if (T->name == "") return true;
	for (size_t i=0; i < usertypes.size(); i++) {
		if (T->name == usertypes[i]) { return true; }
	}
	return false;
}

S_function * functions_signature(ParseTree * tree){
  	S_function * F = new S_function();
  	F->name = tree->children[1]->token->text;
  	F->line = tree->children[1]->token->line;
  	if (tree->children[0]->token) { F->returnType = type_creator(""); }
  	else { F->returnType = basetype(tree->children[0]); }
  	openscope();
 	tree->symtab = currentSS;
  	for (size_t i=0; i < tree->children[2]->children.size(); i++) {
   		S_variable * V = new S_variable;
   		V->var = var0; var0++;
    	V->name = tree->children[2]->children[i]->children[1]->token->text;
    	V->type = basetype(tree->children[2]->children[i]->children[0]);
    	V->line = tree->children[2]->children[i]->children[1]->token->line;
    	if (currentSS->dict.count(V->name) == 1) { semantic_error(func1, V->line); }
		F->formals.push_back(V);
    	currentSS->insert(V->name, V); }
  closescope();
  return F;
}

S_class * class_read(ParseTree * tree) {
  S_class* C = new S_class();
  C->name = tree->children[0]->token->text;
  C->line = tree->children[0]->token->line;
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
      V->var = var0; var0++;
      V->name = field->children[1]->token->text;
      V->line = field->children[1]->token->line;
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
    V->var = var0; var0++;
    V->name = tree->children[1]->token->text;
    V->type = basetype(tree->children[0]);
    V->line = tree->children[1]->token->line;
    if (currentSS->dict.count(V->name) == 1) { semantic_error("Identifier " + V->name + global1, V->line); }
    currentSS->insert(V->name, V);
  }
  if (tree->description == "functiondecl"){
    S_function * F = functions_signature(tree);
    if (currentSS->dict.count(F->name) == 1) { semantic_error("Identifier " + F->name + global1, F->line); }
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
	  if (topSS->local_lookup(A->interfaces[i])->kind() != "S_interface")
	    semantic_error(A->interfaces[i]+" implemented by class "+A->name+ " is not an interface", A->line);
	}
	else
	  semantic_error("Interface "+A->interfaces[i]+" implemented by class "+A->name+ " is not defined", A->line);
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
	S_interface* I;
	for (map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  if (dynamic_cast<S_interface *>(it1->second) && it1->first == C->interfaces[i])
	    I = dynamic_cast<S_interface*>(it1->second);
	}
    Symtab * currenttab;
	for (size_t j=0; j < tree->children.size(); j++) {
	  if (tree->children[j]->description == "class") {
	    if (tree->children[j]->children[0]->token->text == C->name) {
		currenttab = tree->children[j]->symtab;
		break;
	      }}}
	for (unsigned int k=0; k < I->functions.size(); k++) {
	  bool found1 = false;
	  S_function * FI =  I->functions[k];
	  for (map<string, semantics *>::iterator it1=currenttab->dict.begin(); it1!=currenttab->dict.end(); ++it1) {
	    if (dynamic_cast<S_function *>(it1->second)) {
	      if(dynamic_cast<S_function *>(it1->second)->name == FI->name) {
	        S_function * FUNC = dynamic_cast<S_function *>(it1->second);
	        if (check_type_signature(FUNC, FI)) { found1 = true; }
	        break;
	      }}}
	  if (!found1)
	    semantic_error("Class "+C->name+" does not implement all methods of the '"+I->name+ "' interface", FI->line);
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
	    			othertab = currenttab;
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
							if (!check_type_signature(FUNC1, FUNC2)) {semantic_error("Subclass "+A->name+" cannot overwrite a function from the '"+B->name+"' class", FUNC1->line); }}
	      				else { semantic_error("Subclass "+A->name+" cannot overwrite a variable from the '"+B->name+"' class", A->line); }}
	    			else {
	    				currenttab->insert(it2->first, it2->second);
	    				if (dynamic_cast<S_function*>(it2->second)) A->functions.push_back(dynamic_cast<S_function*>(it2->second));
	    				else if (dynamic_cast<S_variable*>(it2->second)) A->variables.push_back(dynamic_cast<S_variable*>(it2->second));
	    				}}}
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
      }}}
      //for (size_t i=0; i < tree->children.size(); i++) {
	 			//if (tree->children[i]->description == "class") {
	      				//othertab = tree->children[i]->symtab;
	      				// othertab->outputer();}}
}
  
void compat1() {
  for (map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { // looping through top scope
    if (dynamic_cast<S_class *>(it->second)) {
      S_class * A = dynamic_cast<S_class *>(it->second);
      S_class * B = dynamic_cast<S_class *>(it->second);
      while (true) {
      	for (size_t i=0; i < B->interfaces.size(); i++) { compat.push_back(make_tuple(A->name, B->interfaces[i]));	}
		if (A != B) { compat.push_back(make_tuple(A->name, B->name)); }
		if (B->parentClass == "") { break; }
		for (std::map<string, semantics *>::iterator it1=topSS->dict.begin(); it1!=topSS->dict.end(); ++it1) {
	  		if (dynamic_cast<S_class *>(it1->second) && dynamic_cast<S_class*>(it1->second)->name == B->parentClass)
	    		B = dynamic_cast<S_class*>(it1->second); break; }
      }}}}

void type_definition() {
	for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) {
    	if (dynamic_cast<S_class *>(it->second)) {
    		S_class * C = dynamic_cast<S_class *>(it->second);
    		for (unsigned int k=0; k <  C->functions.size(); k++) {
    			if (!(ensure_type(C->functions[k]->returnType))) { semantic_error(typefunc, C->functions[k]->line); }
    			for (unsigned int i=0; i <  C->functions[k]->formals.size(); i++) {
    				if (!(ensure_type(C->functions[k]->formals[i]->type))) { semantic_error(typevar, C->functions[k]->formals[i]->line); }}}
    		for (unsigned int k=0; k <  C->variables.size(); k++) {
    			if (!(ensure_type(C->variables[k]->type))) { semantic_error(typevar, C->variables[k]->line); }}}
    			
    	else if (dynamic_cast<S_interface *>(it->second)) {
    		S_interface * I = dynamic_cast<S_interface *>(it->second);
    		for (unsigned int k=0; k <  I->functions.size(); k++) {
    			if (!(ensure_type(I->functions[k]->returnType))) { semantic_error(typefunc, I->functions[k]->line); }
    			for (unsigned int i=0; i <  I->functions[k]->formals.size(); i++) {
    				if (!(ensure_type(I->functions[k]->formals[i]->type))) { semantic_error(typevar, I->functions[k]->formals[i]->line); }}}}
    		
    	else if (dynamic_cast<S_function *>(it->second)) {
    		S_function * F = dynamic_cast<S_function *>(it->second);
    		if (!(ensure_type(F->returnType))) { semantic_error(typefunc, F->line); }
    		for (unsigned int i=0; i <  F->formals.size(); i++) {
    				if (!(ensure_type(F->formals[i]->type))) { semantic_error(typevar, F->formals[i]->line); }}}
    	else  { 
    		S_variable * V = dynamic_cast<S_variable *>(it->second); 
    		if (!(ensure_type(V->type))) { semantic_error(typevar, V->line); }}}}

bool prim(string S1) { return (S1 == "int" || S1 == "bool" ||S1 == "double"||S1 == "string" );}

bool equivalent(S_type * DAD, S_type * SON) { return (DAD->array == SON->array && DAD->name == SON->name); }

bool compatibles(S_type * DAD, S_type * SON) {
	if (!DAD || !SON) { return false; }
	if (SON->name == "" || DAD->name == "" || DAD->name == "null") { return false; }
	if (equivalent(DAD, SON)) {return true; }
	if (DAD->array != 0 || SON->array != 0 || prim(DAD->name) || prim(SON->name)) { return false; }
	if (SON->name == "null") { return true; }
	for (size_t i=0; i < compat.size(); i++) {
		if (get<0>(compat[i]) == SON->name && get<1>(compat[i]) == DAD->name) return true; }
	return false; }

S_type * EXPR(ParseTree * tree) {
	S_type * one = new S_type;
	if (tree->description == "binop") {
		int type = tree->children[1]->token->type;
		if (type == 38) {
			ass =true;
			S_type * L = EXPR(tree->children[0]);
			if (!ass) { semantic_error("Cannot have New or NewArray on left side of assignment", LN); }
			S_type * R = EXPR(tree->children[2]);
			if (compatibles(L, R)) { return L; }
			else { semantic_error("Assignment failed", LN); }
		}
		else if (type == 41 || type == 42) { 
			S_type * L = EXPR(tree->children[0]);
			S_type * R = EXPR(tree->children[2]);
			if (L->name == "bool" && R->name == "bool" && L->array == 0 && R->array == 0) { return L; }
			else { semantic_error("and and ors over here", LN); }
		}
		else if (type == 39 || type == 40) { 
			S_type * L = EXPR(tree->children[0]);
			S_type * R = EXPR(tree->children[2]);
			if (compatibles(L, R)) { return type_creator("bool"); }
			else if (compatibles(R, L)) { return type_creator("bool"); }
			else { semantic_error("comparaison == or !=", LN); }
		}
		else if (type > 33 && type < 38) { 
			S_type * L = EXPR(tree->children[0]);
			S_type * R = EXPR(tree->children[2]); 
			if (L->name == R->name && (L->name == "int" || L->name == "double") && L->array == 0 && R->array == 0) { return type_creator("bool"); }
			else { semantic_error("arithmetic comparaison", LN); }
		}
		else if (type > 28 && type < 34) { 
			S_type * L = EXPR(tree->children[0]);
			S_type * R = EXPR(tree->children[2]); 
			if (L->name == R->name && (L->name == "int" || L->name == "double") && L->array == 0 && R->array == 0) { return L; }
			else { semantic_error("math equations symbols", LN); }
		 }
	}
	else if (tree->description == "uop") {
		if (tree->children[0]->token->type == 30) {
			S_type * T = EXPR(tree->children[1]);
			if (!((T->name == "int" || T->name == "double") && T->array == 0)) { semantic_error("negation operator", LN); }
			return T;
		}
		if (tree->children[0]->token->type == 43) {
			S_type * T = EXPR(tree->children[1]);
			if (!((T->name == "bool") && T->array == 0)) { semantic_error("! - not unary", LN); }
			return T;
		}
	}
	else if (tree->description == "aref") {
		S_type * L = EXPR(tree->children[0]);
		S_type * R = EXPR(tree->children[1]); 
		if (!(R->name == "int" && R->array == 0)) { semantic_error(aref2, LN); }
		else if (!(L->array > 0)) { semantic_error(aref1, LN); }
		else { L->array--; return L; }} 	
	else if (tree->description == "call") {
		if (tree->children[0]->token) {
			string Fname = tree->children[0]->token->text;
			LN = tree->children[0]->token->line;
			S_function * F;
			bool found = false;
			if (currentClass) {
				for (size_t i=0; i < currentClass->functions.size(); i++) { 
					if (currentClass->functions[i]->name == Fname) { F = currentClass->functions[i]; found = true; }}
			}
			else if (! found) {
				if (topSS->local_lookup(Fname) && dynamic_cast<S_function *>(topSS->local_lookup(Fname))) {
					F = dynamic_cast<S_function *>(topSS->local_lookup(Fname)); }
				else { semantic_error("No method of the current class or function called" + Fname + " is defined", LN); }
			}
    		if (tree->children[1]->children.size() != F->formals.size()) { semantic_error("Num. of arguments in function " + Fname + def1, LN); }
    		for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
				S_type * T1 = EXPR(tree->children[1]->children[i]); 
				S_type * T2 = F->formals[i]->type;
				if (! compatibles(T2, T1)) { semantic_error("Type of the arguments of the function " + Fname + " don't match", LN); }}
			if (F->returnType) { return F->returnType; }
			else { return type_creator(""); }}
		else  {
			S_class * C1 = nullptr;
			S_interface * I1 = nullptr;
			S_type * T1 = EXPR(tree->children[0]->children[0]);
			string Fname = tree->children[0]->children[1]->token->text;
			LN = tree->children[0]->children[1]->token->line;
			
			if (T1->array > 0 && Fname == "length" && tree->children[1]->children.size() == 0) { return type_creator("int"); }
			else if (!(T1->array == 0)) { semantic_error("Arrays do not have methods ", LN); } 
			else if (topSS->local_lookup(T1->name) && dynamic_cast<S_class *>(topSS->local_lookup(T1->name))) {
				C1 = dynamic_cast<S_class *>(topSS->local_lookup(T1->name)); }
			else if (topSS->local_lookup(T1->name) && dynamic_cast<S_interface *>(topSS->local_lookup(T1->name))) {
				I1 = dynamic_cast<S_interface *>(topSS->local_lookup(T1->name)); }
			else { semantic_error("Objects of primitive types or objects with no types do not have methods", LN); }
			S_function * F;
			bool found = false;
			
			if (C1) { 
				for (size_t i=0; i < C1->functions.size(); i++) { 
					if (C1->functions[i]->name == Fname) { F = C1->functions[i]; found = true; }}}
			else if (I1) { 
				for (size_t i=0; i < I1->functions.size(); i++) { 
					if (I1->functions[i]->name == Fname) { F = I1->functions[i]; found = true; }}}
			
    		if (!found) { semantic_error("Method " + Fname + " is not defined in that user-defined object type", LN); }
    		if (tree->children[1]->children.size() != F->formals.size()) { semantic_error("Num. of arguments in method " + Fname + def1, LN); }
    		
    		for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
				S_type * T1 = EXPR(tree->children[1]->children[i]); 
				S_type * T2 = F->formals[i]->type;
				if (! compatibles(T2, T1)) { semantic_error("Type of the arguments of the method " + Fname + " don't match", LN); }
			}
			if (F->returnType) { return F->returnType; }
			else { return type_creator(""); }
		}}
	else if (tree->description == "new") {
		ass = false;
		string name = tree->children[0]->token->text;
		LN = tree->children[0]->token->line;
		if (topSS->local_lookup(name) && dynamic_cast<S_class *>(topSS->local_lookup(name))) { return type_creator(name); }
    	else { semantic_error(new1, LN); }
	}
	else if (tree->description == "newarray") {
		ass = false;
		S_type * L = EXPR(tree->children[0]);
		if (!(L->name == "int" &&  L->array == 0)) { semantic_error("Newarray's first argument must be of type int", LN); }
		S_type * R = basetype(tree->children[1]);
		if (!(ensure_type(R))) { semantic_error("Type undefined in new array", LN); }
		R->array++;
		return R;
	}
	else if (tree->description == "readline") { return type_creator("string"); }
	else if (tree->description == "readinteger") { return type_creator("int"); }
	else if (tree->description == "field_access") { 
		LN = tree->children[1]->token->line;
		if (!currentClass) {semantic_error("Cannot access class variables outside class scope", LN); }
		S_type * T = EXPR(tree->children[0]);
		if (T->array != 0) {semantic_error("Cannot access class variables of an array object", LN);}
		if (T->name != currentClass->name) {semantic_error("Cannot access class variables outside of class scope", LN);}
		string name1 = tree->children[1]->token->text;
		for (unsigned int k=0; k <  currentClass->variables.size(); k++) {
    		if (name1 == currentClass->variables[k]->name) { return currentClass->variables[k]->type; }}
	semantic_error("Variable undefined in the current class", LN);
	}
	else if (tree->token) {	
		if (tree->token->type == 8) { LN = tree->token->line; return type_creator("null"); }
		if (tree->token->type == 23) { 
			LN = tree->token->line; 
			if (currentSS->lookup(tree->token->text)){
				semantics * S = currentSS->lookup(tree->token->text);
				if (dynamic_cast<S_variable *>(S)) { S_type* temp = dynamic_cast<S_variable *>(S)->type; return type_creator(temp->name, temp->array); }
    			else  { semantic_error("Identifier is not a variable", LN);}}
			else { semantic_error("Identifier is not defined in this scope", LN);}}
		if (tree->token->type == 25) { LN = tree->token->line; return type_creator("int"); }
		if (tree->token->type == 26) { LN = tree->token->line; return type_creator("bool"); }
		if (tree->token->type == 27) { LN = tree->token->line; return type_creator("double"); }
		if (tree->token->type == 28) { LN = tree->token->line; return type_creator("string"); }
		if (tree->token->type == 9) {
			if (currentClass) { LN = tree->token->line; return type_creator(currentClass->name); }
			else { semantic_error("This cannot be used outside of a class scope", LN);}
			}
	}
	return one;
}
  
void STMT(ParseTree * tree) {
	if (tree->description == "print") {
		LN = tree->children[0]->token->line;
		for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
			S_type * T = EXPR(tree->children[1]->children[i]); 
			if (!(T->array == 0)) { semantic_error(print1, LN); } 
			if (!(T->name == "int" || T->name == "bool" || T->name == "string")) { semantic_error(print2, LN); } 
		}}
	else if (tree->description == "while") {
		looper++;
		S_type * mustbool = EXPR(tree->children[0]); 
		if (!(mustbool->name == "bool" && mustbool->array == 0)) {semantic_error(while1, LN); } 
		STMT(tree->children[1]);
		looper--;
	}
	else if (tree->description == "for") {
		looper++;
		EXPR(tree->children[0]); 
		S_type * mustbool = EXPR(tree->children[1]); 
		if (!(mustbool->name == "bool" && mustbool->array == 0)) {semantic_error(for1, LN); }
		EXPR(tree->children[2]); 
		STMT(tree->children[3]);
		looper--;
	}
	else if (tree->description == "break") {
		LN = tree->children[0]->token->line;
		if (looper == 0){ semantic_error(break1, LN); }}
	else if (tree->description == "return") {
		LN = tree->children[0]->token->line;
		if (tree->children.size() == 1 && currentFunc->returnType == NULL) { return; }
		else if (tree->children.size() == 1) { semantic_error(return1, LN); }
		else {
		S_type * returnT = EXPR(tree->children[1]);
		if (!currentFunc->returnType) {semantic_error(return1, LN); }
		else if (returnT->array == currentFunc->returnType->array && returnT->name == currentFunc->returnType->name)  { return; }
		else if (compatibles(currentFunc->returnType, returnT)) { return; }
		else { semantic_error(return1, LN); }}}
	else if (tree->description == "if") {
		S_type * mustbool = EXPR(tree->children[0]); 
		if (!(mustbool->name == "bool" && mustbool->array == 0)) { semantic_error(ifstmt1, LN); }
		if (tree->children.size() == 2) { STMT(tree->children[1]);}
		if (tree->children.size() == 3) { STMT(tree->children[1]); STMT(tree->children[2]); }}
	else if (tree->description == "stmtblock") { 
		openscope();
		tree->symtab = currentSS;
		for (size_t i=0; i < tree->children[0]->children.size(); i++) {
			S_variable * V = new S_variable();
			V->var = var0; var0++;
      		V->name = tree->children[0]->children[i]->children[1]->token->text;
      		V->type = basetype(tree->children[0]->children[i]->children[0]);
      		LN = tree->children[0]->children[i]->children[1]->token->line;
      		V->line = LN;
      		if (!(ensure_type(V->type))) { semantic_error(typevar, V->line); }
      		if (currentSS->dict.count(V->name) == 1) { semantic_error(stmtblock1, LN);  }
      		currentSS->insert(V->name, V); }
      	for (size_t i=0; i < tree->children[1]->children.size(); i++) { STMT(tree->children[1]->children[i]); }
      	closescope(); }
	else if (tree->description == "nullstmt") { return; }
	else { EXPR(tree); }
}

void traversing2(ParseTree * tree) {
if (tree->description == "interface" || tree->description == "variable") { return; }
else if (tree->description == "functiondecl") {
	currentFunc = dynamic_cast<S_function *>(topSS->local_lookup(tree->children[1]->token->text));
	LN = tree->children[1]->token->line;
	currentSS = tree->symtab;
	STMT(tree->children[3]);}
else if (tree->description == "class") {
	currentClass = dynamic_cast<S_class *>(topSS->local_lookup(tree->children[0]->token->text));
   LN = tree->children[0]->token->line;
   Symtab * classSS = tree->symtab;
    for (size_t i=0; i < tree->children[3]->children.size(); i++) {
    	if (tree->children[3]->children[i]->description == "functiondecl") {
    			currentFunc = dynamic_cast<S_function *>(classSS->local_lookup(tree->children[3]->children[i]->children[1]->token->text));
				currentSS = tree->children[3]->children[i]->symtab;
		        STMT(tree->children[3]->children[i]->children[3]);}}}}
		
void functions_mods(ParseTree * tree)  {
	for (size_t i=0; i < tree->children.size(); i++) {
  		currentClass = nullptr;
  		currentFunc = nullptr;
  		if (tree->children[i]->description == "functiondecl") {
			currentFunc = dynamic_cast<S_function *>(topSS->local_lookup(tree->children[i]->children[1]->token->text));
			for (size_t i=0; i < currentFunc->formals.size(); i++) {
				currentFunc->locals.push_back(currentFunc->formals[i]->name);
				currentFunc->nums.push_back(currentFunc->total);
				currentFunc->vars.push_back(currentFunc->formals[i]->var);
				if (currentFunc->formals[i]->type->name == "double" && currentFunc->formals[i]->type->array == 0) currentFunc->total += 2;
				else  currentFunc->total++;
			}}
		else if (tree->children[i]->description == "class") {
			ParseTree * C = tree->children[i];
			currentClass = dynamic_cast<S_class *>(topSS->local_lookup(C->children[0]->token->text));
  	 		Symtab * classSS = C->symtab;
    		for (size_t i=0; i < C->children[3]->children.size(); i++) {
    			if (C->children[3]->children[i]->description == "functiondecl") {
    				ParseTree * F = C->children[3]->children[i];
    				currentFunc = dynamic_cast<S_function *>(classSS->local_lookup(F->children[1]->token->text));
    				currentFunc->total++;
					for (size_t i=0; i < currentFunc->formals.size(); i++) {
						currentFunc->locals.push_back(currentFunc->formals[i]->name);
						currentFunc->nums.push_back(currentFunc->total);
						currentFunc->vars.push_back(currentFunc->formals[i]->var);
						if (currentFunc->formals[i]->type->name == "double" && currentFunc->formals[i]->type->array == 0) currentFunc->total += 2;
						else  currentFunc->total++;
				}}}}}}

void check_main() {
	if (topSS->local_lookup("main") && dynamic_cast<S_function *>(topSS->local_lookup("main"))) {
		S_function * M = dynamic_cast<S_function *>(topSS->local_lookup("main"));
		if (M->returnType->name != "" || M->formals.size() != 0) {
			semantic_error("Global function main must return void and have no arguments", 1); }
		return;
	}
	else semantic_error("No declaration for the global function main", 1); }
	
string f_name(string name1) {
	string real = "";
	for (size_t i=0; i < name1.length(); i++) { 
		if (name1[i] == '.') { break; }
		else { real = real + name1[i]; }
	}
	if (topSS->local_lookup(real) && dynamic_cast<S_class *>(topSS->local_lookup(real))) { semantic_error("Classes cannot have the same name as the file", 1); }
	return real;
}

void NL() { out += '\n'; }

string WS(size_t L) {
	string lol =  "";
	for (size_t i=0; i < L; i++) lol += " ";
	return lol;
}

string label_generator() {
	label++;
	return "LAB" + ITOS(label);
}

void EXPR1(ParseTree * tree) {
	if (tree->description == "binop") {
		int type = tree->children[1]->token->type;
		if (type == 41) {
			EXPR1(tree->children[0]);
			EXPR1(tree->children[2]);
			string l1 = label_generator();
			string l2 = label_generator();
			out += "   iconst_1"; NL();
			out += "   if_icmpne" + WS(13); out += l1; out += '\n';
			out += "   iconst_1"; NL();
			out += "   if_icmpne" + WS(13); out += l1; out += '\n';
			out += "   iconst_1"; NL();
			out += "   goto" + WS(18); out += l2; NL();
			out += l1 + ":"; out += '\n';
			out += "   iconst_0"; NL();
			out += l2 + ":"; out += '\n';
		}
		else if (type == 42) {
			EXPR1(tree->children[0]);
			EXPR1(tree->children[2]);
			string l1 = label_generator();
			string l2 = label_generator();
			out += "   iconst_1"; NL();
			out += "   if_icmpeq" + WS(13); out += l1; out += '\n';
			out += "   iconst_1"; NL();
			out += "   if_icmpeq" + WS(13); out += l1; out += '\n';
			out += "   iconst_0"; NL();
			out += "   goto" + WS(18); out += l2; NL();
			out += l1 + ":"; out += '\n';
			out += "   iconst_1"; NL();
			out += l2 + ":"; out += '\n';
		}
		else if (type == 39 || type == 40) { 
			EXPR1(tree->children[0]);
			EXPR1(tree->children[2]);
			string l1 = label_generator();
			string l2 = label_generator();
			if (type == 39) {out += "   if_icmpne" + WS(13); out += l1; NL();}
			else {out += "   if_icmpeq" + WS(13); out += l1; NL();}
			out += "   iconst_1"; NL();
			out += "   goto" + WS(18); out += l2; NL();
			out += l1 + ":"; NL();
			out += "   iconst_0"; NL();
			out += l2 + ":"; NL();
		}
	}
	else if (tree->token) {	
		if (tree->token->type == 8) { 
			out += "   aconst_null"; NL();
		}
		if (tree->token->type == 23) { 
			LN = tree->token->line;
			S_variable * V = dynamic_cast<S_variable *>(currentSS->lookup(tree->token->text));
			if ((V->type->name == "bool" || V->type->name == "int") && V->type->array == 0) { out += "   iload_"; }
			else if ( V->type->name == "double" && V->type->array == 0) { out += "   dload_"; }
			else { out += "   aload_"; }
			for (size_t i=0; i < currentFunc->vars.size(); i++) {
				if (V->var == currentFunc->vars[i] && V->name == currentFunc->locals[i])
					out += ITOS(currentFunc->nums[i]);
			}
			NL();}
  		if (tree->token->type == 25 ) { out += "   ldc" + WS(19) + tree->token->text; NL(); }
		if (tree->token->type == 26) { 
			if (tree->token->text == "true") { out += "   iconst_1"; NL(); }
			else {out += "   iconst_0"; NL(); }}
		if (tree->token->type == 27) { out += "   ldc2_w" + WS(16) + tree->token->text; NL(); }
		if (tree->token->type == 28) { out += "   ldc" + WS(19) + tree->token->text; NL();  }
		if (tree->token->type == 9) { out += "   aload_0"; NL();}
	}
}
	
void STMT1(ParseTree * tree) {
	string out = "";
	if (tree->description == "print") {
		out += "   .line" + WS(17) + ITOS(tree->children[0]->token->line); NL();
		for (size_t i=0; i < tree->children[1]->children.size(); i++) { 
			out += "   getstatic" + WS(12) + "java/lang/System/out Ljava/io/PrintStream;"; NL();
			EXPR1(tree->children[1]->children[i]);
			S_type * T = EXPR(tree->children[1]->children[i]);
			if (T->name == "string") { out += "   invokevirtual" + WS(9) + "java/io/PrintStream/println(Ljava/lang/String;)V"; NL(); }
			if (T->name == "int") { out += "   invokevirtual" + WS(9) + "java/io/PrintStream/println(I)V"; NL();}
			if (T->name == "bool") { out += "   invokevirtual" + WS(9) + "java/io/PrintStream/println(Z)V"; NL();}
		}
	}
	else if (tree->description == "stmtblock") { 
		currentSS = tree->symtab;
      	for (size_t i=0; i < tree->children[1]->children.size(); i++) { STMT1(tree->children[1]->children[i]); }
      	closescope();
   }
	else if (tree->description == "nullstmt") { return;}
	else { EXPR1(tree); }
}


string outputType(S_type * T) {
		string out = "";
		for (int i=0; i < T->array; i++) { out += "["; }
		if (T->name == "int") out += "I" ;
		else if (T->name == "bool") out += "Z";
		else if (T->name == "double")out +="D";
		else if (T->name == "string") out += "Ljava/lang/String;";
		else out += "L" + T->name + ";";
		return out;
}

void globalV(S_variable * V, string name) {
	out =  ".field" + WS(19) + "public static " + name  + " ";
	out += outputType(V->type); NL(); NL(); }

void globalF(S_function * F, string name, ParseTree * tree) {
	out += ".method" + WS(18) + "public static " + name + "(";
	for (size_t i=0; i < F->formals.size(); i++) { out += outputType(F->formals[i]->type); }
	out +=  ')';
	if (F->returnType->name == "") { out += 'V'; NL(); }
	else  { out += outputType(F->returnType); NL(); }
	out += WS(3) +  ".limit stack" + WS(10) + ITOS(TD2) + '\n';
   out += WS(3) + ".limit locals" + WS(9) + ITOS(F->total) + '\n';
   STMT1(tree->children[3]);
	out += ".end method";
	NL(); NL(); }

void code_gen_file(ParseTree * tree, string fname) {
	string real = f_name(fname);
	fstream FILE; 
	tree = tree;
   FILE.open(real + ".j", ios::out); 
   out += ".source" + WS(18) + fname + '\n';
   out += ".class" + WS(19) + "public " + real + '\n';
   out += ".super" + WS(19) + "java/lang/Object" + '\n' +'\n'+'\n';
   for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { 
   		if  (dynamic_cast<S_variable *>(it->second)) 
   			globalV(dynamic_cast<S_variable *>(it->second), it->first); }
   out += ".method" + WS(18) + "public <init>()V" + '\n';
   out += WS(3) +  ".limit stack" + WS(10) + "1" + '\n';
   out += WS(3) + ".limit locals" + WS(9) + "1" + '\n';
   out += WS(3) +  ".line" + WS(17) + "1" +'\n';
   out += WS(3) + "aload_0" + '\n';   
   out += WS(3) + "invokespecial" + WS(9) + "java/lang/Object/<init>()V" + '\n';
   out += WS(3) + "return";
   out += '\n';
	out += ".end method";
	out += '\n';
	out += '\n';
	for (std::map<string, semantics *>::iterator it=topSS->dict.begin(); it!=topSS->dict.end(); ++it) { 
	 	if  (dynamic_cast<S_function *>(it->second)) {
	 		currentFunc = dynamic_cast<S_function *>(it->second);
  			currentClass = nullptr;
  			ParseTree * F;
  			for (size_t i=0; i < tree->children.size(); i++) {
  				if (tree->children[i]->description == "functiondecl" && tree->children[i]->children[1]->token->text == it->first)
  					F = tree->children[i]; }
  			globalF(currentFunc, it->first, F); }}
  	FILE << out;
}

void code_gen(ParseTree * tree, string fname) {
	code_gen_file(tree, fname);

}

void check_semantics(ParseTree * top) {
	top->symtab = topSS;
	for (size_t i=0; i < top->children.size(); i++) traversing1(top->children[i]);
	cout << "TRAVERSE1" <<endl;
	type_definition();							// makes sure all user types are defined user types
  	cout << "TYPES DEFINED" <<endl;
  	compat1();		
  	cout << "COMPATIBLE TABLE" <<endl;
	check_parents(); 							// makes sure every class' parent is declared
  	check_loops(); 								// makes sure no class is a subclass of itself
  	check_parents2(top); 					// modifies each class scope to include its parents' objects
  	cout << "CLASSES" <<endl;									//
  	check_implements(); 					// makes sure every class' interfaces are declared
  	check_implements2(top);			// makes sure every class' interfaces' functions are defined in the class scope
  	cout << "IMPLEMENTS" <<endl;
 	functions_mods(top);					// fills in formals code generation numbers
 	cout << "FORMAL GENERATE" <<endl;
  	check_main();									// checks for main function
  	cout << "MAIN" <<endl;
  	LN = 0;
  	for (size_t i=0; i < top->children.size(); i++) {
  		currentClass = nullptr;
  		currentFunc = nullptr;
  		traversing2(top->children[i]);
  }
  cout << "TRAVERSE2" <<endl;
}

int main(int argc, char ** argv) { 
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
  cout << "PARSED" <<endl;
  check_semantics(top);
  cout << "SEMANTICS" <<endl;
  string filename = argv[1];
  code_gen(top, filename);
  cout << "GENERATED" <<endl;
  traverseTree(top, 0, 1);
  return 0;
#endif
}

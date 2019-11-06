
#ifndef SEMANTICS
#define SEMANTICS

#include <map>

void semantic_error(string msg, int line);

struct semantics {
  // pure virtual function:
  virtual string kind() = 0;
  // at least one pure virtual function makes the class abstract 
  // (not instantiable.)

};

struct S_type : public semantics {
  virtual string kind() { return "S_type"; }
  string name;
  int array = 0;
  vector<S_type *> compatible;// usually a decaf symbol, but sometimes 
  // a type.  name can't be void.
};

struct S_variable : public semantics {
  string name;
  S_type * type;
  virtual string kind() { return "S_variable"; }
};

struct S_function : public semantics {
  virtual string kind() { return "S_function"; }
  string name;
  vector<S_variable *> formals;
  S_type * returnType;  // NULL for a void function
};

struct S_interface : public S_type {
  virtual string kind() { return "S_interface"; }
  vector<S_function *> functions;
};

struct S_class : public S_type {
  virtual string kind() { return "S_class"; }
  string parentClass;  // extends 
  vector<string> interfaces; // implements
  vector<S_function *> functions;  // each has to be S_sfunction or S_variable
  vector<S_variable *> variables;
};

struct S_builtin : public semantics {
  virtual string kind() { return "S_builtin"; }
};

typedef map <string, semantics *> Dictionary;

struct Symtab {
  // A class to represent symbol tables
  // Chained togeher to represent nested scopes.
 public:
  Dictionary dict;
  Symtab(Symtab *p);
  semantics * lookup(string key);
  semantics * local_lookup(string key);
  
  void insert(string key, semantics * item);
  void replace(string key, semantics * item);
  void outputer();
  
  Symtab * parent;  // outer scope
};

void closescope();
void openscope();

extern Symtab *currentScope;
extern Symtab *topScope;

#endif

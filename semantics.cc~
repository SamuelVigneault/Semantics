#include <iostream>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

#include "semantics.h"
#include "parsetree.h"

vector<string> usertypes;

Symtab *topSS = nullptr;
Symtab *currentSS = nullptr;

S_function* currentFunc;
S_class* currentClass;

void semantic_error(string msg, int line)
{
  std::cerr << "Semantic error: " << msg << " on line " << line << std::endl;
  exit(1);
}

void internal_error(string msg)
{
  std::cerr << "internal error: " << msg << std::endl;
  exit(2);
}

int get_line(ParseTree *tree)
{
  // find a token with a line number.  For now just traverse children[0]
  if (tree->token)
    return tree->token->line;
  return get_line(tree->children[0]);
}

string base_type_name(ParseTree *type_tree)
{
  if (type_tree->description=="arraytype")
    return base_type_name(type_tree->children[0]);
  if (type_tree->description=="primtype" ||
      type_tree->description=="usertype")
    return type_tree->children[0]->token->text;
  internal_error("Type tree does not name a type" + type_tree->toString());
  return "";
}

bool is_primitive(string type_name)
{
  return type_name=="int" or
    type_name=="double" or
    type_name=="bool" or
    type_name=="string";
}

void ensure_type(ParseTree *type_tree, bool create_undefined=true)
{
  string base_name = base_type_name(type_tree);
  if (is_primitive(base_name))
    return;
  semantics *definition = topSS->local_lookup(base_name);
  if (definition and dynamic_cast<S_type *>(definition))  // dyn_cast is null on fail.
    return;
  if (definition) 
    semantic_error("Type " + base_name + " is not a type.", get_line(type_tree));
  if (create_undefined) {
    S_type *new_type = new S_type();
    new_type->name = base_name;
    topSS->insert(base_name, new_type);
  }
  else
    semantic_error("Type " + base_name + " undefined.", get_line(type_tree));
}


Symtab::Symtab(Symtab *p) : parent(p) {}

semantics * Symtab::lookup(string key) { 
  semantics *answer;
  return 
    (answer = local_lookup(key)) ? answer : 
    parent ? parent->lookup(key) : nullptr;

}
semantics * Symtab::local_lookup(string key) { 
  return dict[key];
}
void Symtab::insert(string key, semantics * item) {
  assert (dict[key] == nullptr);
  replace(key, item);
}
void Symtab::replace(string key, semantics * item) {
  dict[key] = item;
}
void Symtab::outputer() {
  for (std::map<string, semantics *>::iterator it=dict.begin(); it!=dict.end(); ++it)
    cout << it->first << " => " << it->second << '\n';
}
void openscope() {
  currentSS = new Symtab(currentSS);
}

void closescope() {
  currentSS = currentSS->parent;
}


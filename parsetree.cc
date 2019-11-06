/* parsetree.cc
   Alistair Campbell
   2015--2019
   
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "tokentype.h" 
#include "parsetree.h"

  /* prototype for yyerror, needed on my linux laptop */
int yyerror(const char * s);

using namespace std;


void adopt(ParseTree *treedest, ParseTree *treesource )
{
  for (ParseTree *child : treesource->children) {
    treedest->addChild(child);
  }    
}

ParseTree::ParseTree(string description, ParseTree* c1): description(description),
							 token(nullptr),
							 symtab(nullptr)
{
  addChild(c1);
}

ParseTree::ParseTree(string description, ParseTree* c1, ParseTree* c2):
  description(description), token(nullptr), symtab(nullptr)
{
  addChild(c1);
  addChild(c2);
}

ParseTree::ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3):
  description(description), token(nullptr), symtab(nullptr)
{
  addChild(c1);
  addChild(c2);
  addChild(c3);
}

ParseTree::ParseTree(string description, ParseTree* c1, ParseTree* c2, ParseTree *c3,
		     ParseTree *c4): 
  description(description), token(nullptr), symtab(nullptr)
{
  addChild(c1);
  addChild(c2);
  addChild(c3);
  addChild(c4);
}

ParseTree::ParseTree(string description) : description(description), token(nullptr),
					   symtab(nullptr) {}
ParseTree::ParseTree(Token * tokp) : token(tokp) {}

void ParseTree::addChild(ParseTree * tree) {
  children.push_back(tree);
}

void ParseTree::addChild(ParseTree * tree1, ParseTree * tree2) {
  children.push_back(tree1);
  children.push_back(tree2);
}

string ParseTree::toString() const {
  string answer = "";
  if (token)
    answer +=  token->toString();
  else {
    answer += "(" + description;
    for (vector<ParseTree *>::const_iterator i=children.begin(); 
	 i != children.end(); i++) {
      ParseTree *tree = *i;
      if (!tree) answer += " EMPTY";
      else answer += " " + tree->toString();
    }
    answer += ")";
  }
  return answer;
}

string base26(int x)
{
  char buf[2];
  buf[1] = 0;
  if (x<26) {
    buf[0] = string("abcdefghijklmnopqrstuvwxyz")[x];
    return string(buf);
  }
  return base26(x/26) + base26(x % 26);
}

string seq2str(int seq, int depth)
{
  // depth 1: A, B, C, D....
  // depth 2: 1, 2, 3, 4....
  // depth 3: a, b, c, d....
  // depth 4: 1, 2, 3, 4....
  char buf[100];
  int d = (depth - 1) % 4;
  if (d == 1 || d == 3) {
    sprintf(buf, "%d", seq);
    return string(buf);
  }
  string let = base26(seq-1);
  if (d==0) {
    string bob = "";
    for (string::iterator i = let.begin(); i!=let.end(); i++)
      bob += toupper(*i);
    let = bob;
  }
  return let; 
}

void traverseTree(ParseTree * tree, int depth, int seq) {
  // tree is a possibly null tree, but output always occurs
  for (int i=0;i<depth;i++)
    cout << "   ";
  if (seq) cout << seq2str(seq, depth) << " ";
  if (!tree) { 
    cout << "NULL" << endl; 
    return; 
  }
  if (tree->token) {
    cout << tree->token->toString() << endl; 
    return; 
  }
  cout << tree->description << endl;
  for (size_t i=0;i<tree->children.size();i++)
    traverseTree(tree->children[i], depth+1, i+1);
}


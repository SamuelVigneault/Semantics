%token T_Void 1
%token T_Int 2
%token T_Double 3
%token T_Bool 4
%token T_String 5
%token T_Class 6
%token T_Interface 7
%token T_Null 8
%token T_This 9
%token T_Extends 10
%token T_Implements 11
%token T_For 12
%token T_While 13
%token T_If 14
%token T_Else 15
%token T_Return 16
%token T_Break 17
%token T_New 18
%token T_NewArray 19
%token T_Print 20
%token T_ReadInteger 21
%token T_ReadLine 22
  /* 2 Identifiers */
%token T_Identifier 23
%token T_TypeIdentifier 24
  /* The 4 kinds of constants (literals) */
%token T_IntConstant 25
%token T_BoolConstant 26
%token T_DoubleConstant 27
%token T_StringConstant 28
  /* The 24 other tokens 
     + - * / % < <= > >= = == != && || ! ; , . [ ] ( ) { } */
%token T_Plus 29
%token T_Minus 30
%token T_Times 31
%token T_Div 32
%token T_Mod 33
%token T_Less 34
%token T_LessEqual 35
%token T_Greater 36       
%token T_GreaterEqual 37
%token T_Assign 38
%token T_Equal 39
%token T_NotEqual 40
%token T_And 41
%token T_Or 42
%token T_Not 43
%token T_Semicolon 44
%token T_Comma 45
%token T_Dot 46
%token T_LBracket 47
%token T_RBracket 48
%token T_LParen 49
%token T_RParen 50
%token T_LBrace 51
%token T_RBrace 52

    
%{
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include "tokentype.h" 
#include "parsetree.h"

#include "semantics.h"  // New: a series of semantics objects
  
  /* we are building parse trees */
#define YYSTYPE ParseTree *

using namespace std;

 extern Token *myTok;
 extern int yylineno;
 int yylex();

 ParseTree *top;


 
 
 /* stack<Token *> opstack;  // used this last time.  Might not need this time?
    Token *optok; */
 
 %}

%%


Program: Decls {top = $$; }

Decls: Decl { $$ = new ParseTree("program", $1); }
    |  Decls Decl { $1->addChild($2); } 

Decl: VariableDecl  | FunctionDecl 

VariableDecl: Variable T_Semicolon

Variable: TypeThenIdent {
             $$ = new ParseTree("variable", $1->children[0],
                                $1->children[1]);
	     Token *tok = $1->children[1]->token;
	     semantics *curr = currentScope->local_lookup(tok->text);
	     if (curr) semantic_error("Variable already defined",tok->line);
	     currentScope->insert(tok->text,new S_variable()); }

FunctionDecl: FunPref T_LParen nFormals T_RParen StmtBlock 
              { $$ = new ParseTree("functiondecl", $1->children[0], 
                                                   $1->children[1], $3, $5); }

FunPref: TypeThenIdent 
       | VoidThenIdent

nFormals: { $$ = new ParseTree("formals"); }
        | Formals { $$ = $1; }

Formals: Variable { $$ = new ParseTree("formals", $1); }
       |  Formals T_Comma Variable { $1->addChild($3); $$ = $1; }



TypeThenIdent: Type Y_Identifier { $$ = new ParseTree("temp", $1, $2); }
VoidThenIdent: Y_Void Y_Identifier { $$ = new ParseTree("temp", $1, $2); }

Type: Y_Int     { $$ = new ParseTree("primtype", $1); }
    | Y_Double  { $$ = new ParseTree("primtype", $1); }
    | Y_Bool    { $$ = new ParseTree("primtype", $1); }
    | Y_String  { $$ = new ParseTree("primtype", $1); }
    | Y_TypeIdentifier { $$ = new ParseTree("usertype", $1); }
    | Type T_LBracket T_RBracket { $$ = new ParseTree("arraytype", $1); }

nVarDecls: /* empty */ { $$ = new ParseTree("vardecls"); }
         |  nVarDecls VariableDecl  { $1->addChild($2);  }

nStmts: /* empty */  { $$ = new ParseTree("statements"); }
      |  nStmts Stmt  { $1->addChild($2); } 

 
StmtBlock: T_LBrace { openscope(); } nVarDecls nStmts T_RBrace
  { $$ = new ParseTree("stmtblock", $3, $4); $$->symtab = closescope(); }

/* 
StmtBlock: T_LBrace nVarDecls nStmts T_RBrace 
     { $$ = new ParseTree("stmtblock", $2, $3); }
*/

Stmt: UnmatchedStmt | MatchedStmt

MatchedStmt: ExprStmt
 | StmtBlock | MatchedIfStmt

UnmatchedStmt: OpenIfStmt

ExprStmt: T_Semicolon { $$ = new ParseTree("nullstmt"); }
 | Expr T_Semicolon

Expr: Y_Identifier | FunctionCall

FunctionCall: Y_Identifier T_LParen Args T_RParen
   { $$ = new ParseTree("call", $1, $3);
   }
Args: { $$ = new ParseTree("arguments"); }
 | Expr { $$ = new ParseTree("arguments", $1); }
 | Args T_Comma Expr { $1->addChild($3); }


OpenIfStmt: IfHeader Stmt { $1->addChild($2); }
  |         IfHeader MatchedStmt T_Else UnmatchedStmt { $1->addChild($2, $4); }

MatchedIfStmt: IfHeader MatchedStmt T_Else MatchedStmt
  { $1->addChild($2, $4); }

IfHeader: T_If T_LParen Expr T_RParen { $$ = new ParseTree("ifstmt", $3); }

Y_Identifier: T_Identifier { $$ = new ParseTree(myTok); }
Y_TypeIdentifier: T_TypeIdentifier { $$ = new ParseTree(myTok); }
Y_Int: T_Int { $$ = new ParseTree(myTok); }
Y_Double: T_Double { $$ = new ParseTree(myTok); }
Y_Bool: T_Bool { $$ = new ParseTree(myTok); }
Y_String: T_String { $$ = new ParseTree(myTok); }
Y_Void: T_Void { $$ = new ParseTree(myTok); }

%%

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}

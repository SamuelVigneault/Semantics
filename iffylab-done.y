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


Program: StmtBlock {top = $$ = $1; }

Stmts: { $$ = new ParseTree("STATEMENTS"); }
 |  Stmts Stmt  { $1->addChild($2); } 
StmtBlock: T_LBrace Stmts T_RBrace { $$ = $2; } 

Stmt: UnmatchedStmt | MatchedStmt

MatchedStmt: ExprStmt
 | StmtBlock | MatchedIfStmt

UnmatchedStmt: OpenIfStmt

ExprStmt: T_Semicolon { $$ = new ParseTree("NULLSTMT"); }
 | Expr T_Semicolon

Expr: Y_Identifier | PyList | FunctionCall

FunctionCall: Y_Identifier T_LParen Args T_RParen
   { $$ = new ParseTree("FNCALL",$1, $3);
   }
Args: { $$ = new ParseTree("ARGS"); }
 | Expr { $$ = new ParseTree("ARGS", $1); }
 | Args T_Comma Expr { $1->addChild($3); }


OpenIfStmt: IfHeader Stmt { $1->addChild($2); }
  |         IfHeader MatchedStmt T_Else UnmatchedStmt { $1->addChild($2, $4); }

MatchedIfStmt: IfHeader MatchedStmt T_Else MatchedStmt
  { $1->addChild($2, $4); }

IfHeader: T_If T_LParen Expr T_RParen { $$ = new ParseTree("IFSTMT", $3); }

Y_Identifier: T_Identifier { $$ = new ParseTree(myTok); }

%%

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}

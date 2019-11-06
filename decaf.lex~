  /* definitions */

%{

#include <iostream>

using namespace std;

#include "tokentype.h"

int counter;
string resultString;
Token* myTok;

int error(string msg, int line)
{
  cout << msg << " on line " << line << endl;
  return -1;
}

int error1(string msg, int line)
{
  cout <<"stray \'" <<  msg << "\' on line " << line << endl;
  return -1;
}

int errorid()
{
  cout << "identifier " << yytext << " too long on line " << yylineno << endl;
  return -1;
}
 
TokenType makeToken(TokenType type) {
    myTok = new Token(type, yytext, yylineno);
    return type;
}

 
%}

%option yylineno

%x STRING
%x MULTI
%x SINGLE

   /* regexp / {follow} */
follow [[:space:]]+[A-Za-z]|[[:space:]]*\[[[:space:]]*\]

%%
  /* the 22 keywords */   
string/{follow}?       { return makeToken(T_String); }
this/{follow}?      { return makeToken(T_This); }
while/{follow}?     { return makeToken(T_While); }
break/{follow}?        { return makeToken(T_Break); }
ReadInteger/{follow}?  { return makeToken(T_ReadInteger); }
ReadLine/{follow}?     { return makeToken(T_ReadLine); }
double/{follow}?       { return makeToken(T_Double); }
bool/{follow}?         { return makeToken(T_Bool); }
class/{follow}?        { return makeToken(T_Class); }
interface/{follow}?    { return makeToken(T_Interface); }
null/{follow}?         { return makeToken(T_Null); }
extends/{follow}?      { return makeToken(T_Extends); }
implements/{follow}?   { return makeToken(T_Implements); }
for/{follow}?          { return makeToken(T_For); }
if/{follow}?           { return makeToken(T_If); }
else/{follow}?         { return makeToken(T_Else); }
return/{follow}?       { return makeToken(T_Return); }
New/{follow}?          { return makeToken(T_New); }
NewArray/{follow}?     { return makeToken(T_NewArray); }
Print/{follow}?        { return makeToken(T_Print); }
void/{follow}?         { return makeToken(T_Void); }
int/{follow}?          { return makeToken(T_Int); }
  /* the BoolConstant */
true/{follow}?         { return makeToken(T_BoolConstant); }
false/{follow}?        { return makeToken(T_BoolConstant); }
  /* 24 punctuation */
\+  { return makeToken(T_Plus); } 
\-  { return makeToken(T_Minus); } 
\*  { return makeToken(T_Times); } 
\/  { return makeToken(T_Div); }
%  { return makeToken(T_Mod); } 
\<  { return makeToken(T_Less); } 
\<= { return makeToken(T_LessEqual); } 
\>  { return makeToken(T_Greater); } 
\>= { return makeToken(T_GreaterEqual); } 
=  { return makeToken(T_Assign); } 
== { return makeToken(T_Equal); } 
!= { return makeToken(T_NotEqual); }
&& { return makeToken(T_And); } 
\|\| { return makeToken(T_Or); } 
!  { return makeToken(T_Not); } 
;  { return makeToken(T_Semicolon); } 
,  { return makeToken(T_Comma); } 
\.  { return makeToken(T_Dot); } 
\[  { return makeToken(T_LBracket); } 
\]  { return makeToken(T_RBracket); } 
\(  { return makeToken(T_LParen); } 
\)  { return makeToken(T_RParen); } 
\{  { return makeToken(T_LBrace); } 
\}  { return makeToken(T_RBrace); } 

  /* the identifiers */
[A-Za-z][A-Za-z0-9_]*/{follow} { if (strlen(yytext) < 32) {return makeToken(T_TypeIdentifier); } else { return errorid();}}
[A-Za-z][A-Za-z0-9_]* { if (strlen(yytext) < 32) {return makeToken(T_Identifier); } else { return errorid();}}

  /* Int constants */
0[Xx][0-9a-fA-F]*  { return makeToken(T_IntConstant); }
[0-9]*  { return makeToken(T_IntConstant); }

  /* double constants */
[0-9]+\.[0-9]*|[0-9]+\.[0-9]*[Ee][\+\-]?[0-9]* { return makeToken(T_DoubleConstant); }

  /*single line comments */
\/\/ { BEGIN(SINGLE); }
<SINGLE>\n       { BEGIN(INITIAL); }
<SINGLE><<EOF>>  { return -1; }
<SINGLE>.        { }

  /* string constant */
\" { BEGIN(STRING); resultString = "\""; }
<STRING>[^\n"]*  { resultString += yytext; }
<STRING>\n       { return error("missing \" at end of string constant", yylineno-1); }
<STRING><<EOF>>  { return error("missing \" at end of string constant", yylineno); } 
<STRING>\"       { BEGIN(INITIAL); 
	           myTok = new Token(T_StringConstant,resultString + "\"", yylineno);
		   return T_StringConstant; }

\/\* { BEGIN(MULTI); counter = 0; }
<MULTI>\/\*     { return error("missing */ for block comment beginning", yylineno - counter);}
<MULTI>\n       { counter++; }
<MULTI><<EOF>>  { return error("missing */ for block comment beginning", yylineno - counter);}
<MULTI>.        { } 
<MULTI>\*\/     { BEGIN(INITIAL); }

[[:space:]]* {}

.  { return error1(yytext, yylineno); }
                  
<<EOF>> { return -1; }

%%

  /* subroutines */

int yywrap(void) {
    return 1;  // makes it stop at EOF.
    if (false) {yyunput(0,0);}
} 

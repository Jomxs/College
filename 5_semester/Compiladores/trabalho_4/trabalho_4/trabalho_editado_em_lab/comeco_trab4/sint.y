%{ 
#include "analex.c" 
#include "tipos.h"
void verifica_var_declarada(int pos);
void verifica_func_declarada(int pos);
void verifica_tipos_atrib(int tipo1, int tipo2);
%}

%union{
	struct ids{
		int ids[50];
		int tam;
	} id_list;
	struct simb{
		int posicao;
		char *lexema;
		int tipo;
	} simbolo;
	int val;
	float fval;
	char cval;
}

%token <val> NUM 
%token NUM_REAL
%token <simbolo> ID 
%token FOR
%token WHILE
%token IF 
%token ELSE
%token ENDIF
%token CHAR
%token INT
%token FLOAT
%token VOID
%token RETURN
%token OR
%token AND
%token NOT
%token GE
%token LE
%token EQ
%token NEQ
%token DO
%token STRING
%token CHARACTERE

%type <id_list> IDs ParamList ArgList
%type <simbolo> AtribuicaoD 
%type <val> Atribuicao Type FunctionCall TypeF
%type <val> Exp

%right '='

%left OR
%left AND

%nonassoc EQ NEQ

%left '>' '<' GE LE

%left '+' '-'
%left '*' '/' '%'

%right NOT

%right '(' '['


%start ProgL
%%
ProgL : Prog { printf("Compilação finalizada com sucesso."); }
    ;
    
Prog : Prog Function
	| Function
	;	

Function :
	TypeF ID '(' ParamList ')' '{' { entra_escopo(); } Decls Statement_Seq '}'   { set_type($2.posicao, $1); set_num_param($2.posicao, $4.tam); sai_escopo(); }
	| TypeF ID '(' ')' '{' { entra_escopo(); } Decls Statement_Seq '}'   { set_type($2.posicao, $1); set_num_param($2.posicao, 0); sai_escopo(); }
	;
	
FunctionCall :
    ID '(' ArgList ')' { verifica_func_declarada($1.posicao); if(param_args_diferentes($1.posicao, $3.tam)) yyerror("Numero de argumentos diferente do esperado!"); $$ = Tabela[$1.posicao].tipo; }
    | ID '('  ')' { verifica_func_declarada($1.posicao); if(param_args_diferentes($1.posicao, 0)) yyerror("Numero de argumentos diferente do esperado!"); $$ = Tabela[$1.posicao].tipo; }
    ;
    
ArgList:
    ArgList ',' Arg { $$.tam = $1.tam + 1; }
    | Arg { $$.tam = 1; }
    ;

Arg :
    ID
    | ID '[' Exp ']'
    | FunctionCall
    | NUM
    | STRING
	;
	
ParamList: 
    ParamList ',' Type ID { $$ = $1; set_type($4.posicao, $3); $$.ids[$$.tam] = $4.posicao; $$.tam++; }
    | Type ID { set_type($2.posicao, $1); $$.tam = 1; $$.ids[0] = $2.posicao; }
	; 
		
Decls:
	  Decl ';' Decls  
	| 
	;

Decl:
	Type IDs { int tipo_exp0 = Tabela[$2.ids[0]].tipo; Tabela[$2.ids[0]].tipo = $1;/* TODO: atribuir o tipo declarado a cada identificador e marcar que não se trata de função */
		int i; for(i=0; i<$2.tam; i++){ int tipo_exp = (i==0)? tipo_exp0 : Tabela[$2.ids[i]].tipo; verifica_tipos_atrib($1, tipo_exp); set_type($2.ids[i], $1); } }
	; 
	
IDs :
	  IDs ',' ID { $$ = $1; $$.ids[$$.tam] = $3.posicao; $$.tam++; }
	| IDs ',' ID '[' NUM ']' { $$ = $1; $$.ids[$$.tam] = $3.posicao; $$.tam++; }
	| ID { $$.ids[0] = $1.posicao; $$.tam = 1; }
	| ID '[' NUM ']' { $$.ids[0] = $1.posicao; $$.tam = 1; }
	| IDs ',' AtribuicaoD { $$ = $1; $$.ids[$$.tam] = $3.posicao; $$.tam++; }
	| AtribuicaoD { $$.ids[0] = $1.posicao; $$.tam = 1; }
	;
	
TypeF :
	  VOID { $$ = VOID; }
	| Type { $$ = $1; }
	;

Type :
	  INT { $$ = INT; }
	| CHAR { $$ = CHAR; }
	| FLOAT { $$ = FLOAT; }
	;
			
Statement_Seq :
	Statement Statement_Seq
	|
	;
		
Statement: 
	  Atribuicao ';' { /* TODO: verificar uso de variável declarada antes da atribuição */ }
	| If
	| While
	| DoWhile
	| FunctionCall ';'
	| RETURN ID ';'
	| RETURN NUM ';'
	| RETURN ';'
	;

Compound_Stt :
	  Statement
	| '{' { entra_escopo(); } Decls Statement_Seq '}' { sai_escopo(); }
	;
		
If :
	  IF '(' Exp ')' Compound_Stt ENDIF
	| IF '(' Exp ')' Compound_Stt ELSE Compound_Stt ENDIF
	;

While:
	WHILE '(' Exp ')' Compound_Stt
	;

DoWhile:
	DO Compound_Stt WHILE '(' Exp ')' ';'
	;
			
Atribuicao : ID '[' NUM ']' '=' Exp { verifica_var_declarada($1.posicao); verifica_tipos_atrib(Tabela[$1.posicao].tipo, $6); $$ = $1.posicao; }
    | ID '=' Exp { verifica_var_declarada($1.posicao); verifica_tipos_atrib(Tabela[$1.posicao].tipo, $3);/* TODO: garantir que o identificador foi declarado, validar tipos e devolver posição na tabela */ $$ = $1.posicao; }
	;
	
AtribuicaoD : ID '[' NUM ']' '=' Exp { Tabela[$1.posicao].tipo = $6; $$.posicao = $1.posicao; $$.tipo = $6;/* TODO: registrar posição do identificador e o tipo resultante da expressão */ }
    | ID '=' Exp { Tabela[$1.posicao].tipo = $3; $$.posicao = $1.posicao;if($3 == FLOAT) printf("Expressao e float\n"); if($3 == INT) printf("Expressao e int\n"); if($3 == CHAR) printf("Expressao e char\n");/* TODO: registrar posição do identificador e o tipo da expressão atribuída */ $$.tipo = $3; }
	;
				
Exp :
	  Exp '+' Exp { $$ = retorna_maior_tipo($1, $3); }
	| Exp '-' Exp { $$ = retorna_maior_tipo($1, $3); }
	| Exp '*' Exp { $$ = retorna_maior_tipo($1,$3);  }
	| Exp '/' Exp { $$ = retorna_maior_tipo($1, $3); }
	| Exp '>' Exp { $$ = INT; }
	| Exp '<' Exp { $$ = INT; }
	| Exp GE Exp { $$ = INT; }
	| Exp LE Exp { $$ = INT; }
	| Exp EQ Exp { $$ = INT; }
	| Exp NEQ Exp { $$ = INT; }
	| Exp OR Exp { $$ = INT; }
	| Exp AND Exp { $$ = INT; }
	| NOT Exp { $$ = INT; }
	| '(' Exp ')' { $$ = $2; }
	| NUM { $$ = INT; }
	| NUM_REAL { $$ = FLOAT;}
	| ID '[' Exp ']' { verifica_var_declarada($1.posicao); $$ = Tabela[$1.posicao].tipo; } 
	| ID  { verifica_var_declarada($1.posicao); $$ = Tabela[$1.posicao].tipo; } 	   
	| CHARACTERE { $$ = CHAR;/* TODO: definir tipo char para literal de caractere */ }
	| FunctionCall { $$ = $1; }
	;   
	
	
%%  
int main(int argc, char **argv) {     
  yyin = fopen(argv[1],"r");
  yyparse();      
} 


void verifica_var_declarada(int pos){
	if(Tabela[pos].tipo == -1)
		yyerror("Variavel nao declarada!");
}

void verifica_func_declarada(int pos){
	if(Tabela[pos].tipo == -1)
		yyerror("Funcao nao declarada!");
}
void verifica_tipos_atrib(int tipo1, int tipo2){
	if(tipos_inconsistentes_atrib(tipo1, tipo2))
		yyerror("Tipos incompativeis na atribuicao!");
}
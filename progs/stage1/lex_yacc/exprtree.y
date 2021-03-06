%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
	
%}

%union{
	struct tnode *node;
	
}
%type <node> expr 
%type <node>NUM 
%type <node>program
%type <node> END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				$$ = $2;
				printf("Answer : %d\n",evaluate($1));
				code_gen($1);
				prefix($1);
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
	fp = fopen("/home/shrey/xsm_expl/xsm_progs/generated.xsm","w");
	fprintf(fp,"0\n");
	fprintf(fp,"2056\n");
	fprintf(fp,"0\n");
	fprintf(fp,"0\n");
	fprintf(fp,"0\n");
	fprintf(fp,"0\n");
	fprintf(fp,"0\n");
	fprintf(fp,"0\n");
	fprintf(fp,"BRKP\n");
	yyparse();
	return 0;
}

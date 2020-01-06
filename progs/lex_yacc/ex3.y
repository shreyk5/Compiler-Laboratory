%{
	#include<stdio.h>
    char* add(char *a,char *b,char *c);
%}

%union
{
    char* str;
}

%token STRING NEWLINE
%left '+'
%left '-'
%left '*'

%type<str>STRING

%%
start : expr NEWLINE {printf("%s",$<str>$);};
expr : expr '+' expr {$<str>$ = add($<str>2,$<str>1,$<str>3);};
expr : expr '*' expr {$<str>$ = add($<str>2,$<str>1,$<str>3);};
expr : expr '-' expr {$<str>$ = add($<str>2,$<str>1,$<str>3);};
expr : '(' expr ')'  {};
expr : STRING		 {$<str>$ = $<str>1;};
%%

void yyerror(char *S)
{
	printf("%s",S);
}

char* add(char *a,char *b,char *c)
{
    //printf("%s %s %s\n",a,b,c);
    char* res;
    int cnt1= 0,cnt2 = 0,cnt3 = 0;

    int i = 0;
    while(a[i]!='\0')
    {
        cnt1++;
        i++;
    }

    i = 0;
    while(b[i]!='\0')
    {
        cnt2++;
        i++;
    }

    i = 0;
    while(c[i]!='\0')
    {
        cnt3++;
        i++;
    }

    res = (char*)malloc((sizeof(char)*(cnt1+cnt2+cnt3+2)));

    for(i=0;i<cnt1;i++)
        res[i] = a[i];

    res[cnt1] = ' ';
    for(i=0;i<cnt2;i++)
        res[i+cnt1+1] = b[i];

    res[cnt1+cnt2+1] = ' ';
    for(i=0;i<cnt3;i++)
        res[i+cnt1+cnt2+2] = c[i];

    //res[cnt1+cnt2+cnt3] = '\0';
    return res;
}

int main()
{
	yyparse();
	return 1;
}

lex task.l
yacc -d task.y
gcc y.tab.c lex.yy.c -o task.exe
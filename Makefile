a:
	clear
	gcc main.c -Wall -ansi -c
	gcc FirstParse.c -Wall -ansi -c
	gcc main.o FirstParse.o -lm -o parsing

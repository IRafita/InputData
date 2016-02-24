obj = Parser/parser.o Parser/readFile/read.o Libs/Array.o  Parser/control/cnt.o
a:
	gcc $(obj) main.c -o lola -g -ansi -Wall
#	gcc Parser/parser.o main.c -o lola -g -ansi

all:
	cd Libs; make array
	cd Parser; make all
	cd 
	gcc $(obj) main.c -o lola -g -ansi
	mv lola ../bin

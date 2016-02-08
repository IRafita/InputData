a:
	clear
	gcc Parser/parser.o Parser/readFile/read.o Libs/Array.o main.c -o lola -g -ansi
#	gcc Parser/parser.o main.c -o lola -g -ansi

all:
	cd Libs; make array
	cd Parser; make all
	gcc Parser/parser.o Parser/readFile/read.o Libs/Array.o main.c -o lola -g -ansi

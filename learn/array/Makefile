all: array

array:
	gcc Array.c -c -Wall -ansi -g
clear:
	clear
rm:
	rm *.o -f

t: clear array

m: array
	gcc main.c -c -Wall -g -ansi
	gcc *.o -o a

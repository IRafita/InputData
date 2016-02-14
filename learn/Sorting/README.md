Idea

M'agradaria fer un stil Quick Sort, pero ...


Exemple
p1, p2
v1, v2
max, min

0  1  2  3  4  5  6  7  8
2, 7, 5, 3, 1, 4, 6, 9, 8

p1 = 0
p2 = 8
v1 = 2
v2 = 8

max = v1 = 2
maxp = 0
min = v2 = 8
minp = 8

Com v1 < v2, tot correcte continuem

0  1  2  3  4  5  6  7  8
2, 7, 5, 3, 1, 4, 6, 9, 8

p1 = 1
p2 = 7
v1 = 7
v2 = 9

v1 < min ( 7 < 8 )
max < v2 ( 2 < 8 )

Significa que tot correcte
min = min ( min, v2 ) = min ( 8, 9 ) = 8
	No canvis, no canvia res
max = max ( max, v1 ) = max ( 2, 7 ) = 7
	Canvis
		-> maxp = 1

Continuem

0  1  2  3  4  5  6  7  8
2, 7, 5, 3, 1, 4, 6, 9, 8

p1 = 2
p2 = 6
v1 = 5
v2 = 6

Ara veig que te grans pegues

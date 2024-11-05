calcex: main.o calc.o
	gcc -o calcex main.o calc.o

main.o: main.c calc.h
	gcc -c main.c

calc.o: calc.c calc.h
	gcc -c calc.c
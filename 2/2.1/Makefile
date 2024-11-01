listpers: main.o person.o
	gcc -o listpers main.o person.o

main.o: main.c person.h
	gcc -c main.c

person.o: person.c person.h
	gcc -c person.c
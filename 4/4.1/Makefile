listpers: main.o personlinklist.o
	gcc -o listpers main.o personlinklist.o

main.o: main.c personlinklist.h
	gcc -c main.c

personlinklist.o: personlinklist.c personlinklist.h
	gcc -c personlinklist.c
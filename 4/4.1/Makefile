listpers: main.o userinterface.o personlinklist.o 
	gcc -o listpers main.o personlinklist.o userinterface.o

main.o: main.c userinterface.h 
	gcc -c main.c

userinterface.o: userinterface.c userinterface.h personlinklist.h
	gcc -c userinterface.c

personlinklist.o: personlinklist.c personlinklist.h
	gcc -c personlinklist.c

listpers: main.o userinterface.o persontreelist.o 
	gcc -o listpers main.o persontreelist.o userinterface.o

main.o: main.c userinterface.h 
	gcc -c main.c

userinterface.o: userinterface.c userinterface.h persontreelist.h
	gcc -c userinterface.c

persontreelist.o: persontreelist.c persontreelist.h
	gcc -c persontreelist.c
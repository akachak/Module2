queuelist: main.o userinterface.o queue.o 
	gcc -o queuelist main.o queue.o userinterface.o

main.o: main.c userinterface.h 
	gcc -c main.c

userinterface.o: userinterface.c userinterface.h queue.h
	gcc -c userinterface.c

queue.o: queue.c queue.h
	gcc -c queue.c
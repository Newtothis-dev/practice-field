

Node.o : Node.c Node.h CustomType.h
	gcc -c Node.c 

LinkedList.o : LinkedList.c LinkedList.h Node.o
	gcc -c LinkedList.c 

main.o : main.c Node.h LinkedList.h CustomType.h
	gcc -c Main.c

linked-list : main.o Node.o LinkedList.o
	gcc -o linked-list main.o Node.o LinkedList.o
	rm *.o



clean :
	rm linked-list *.o

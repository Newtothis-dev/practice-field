testlib.o : testlib.h testlib.c pch.h
	gcc -c testlib.c

all : testlibtests.c testlib.c testlib.o pch.h
	gcc -o tests testlibtests.c
	rm *.o



clean :
	rm tests *.o

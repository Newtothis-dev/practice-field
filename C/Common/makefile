testlib.o : testlib.c pch.h testlib.h
	gcc -c testlib.c 

testlibtests.o : testlibtests.c testlib.o
	gcc -c testlibtests.c

tests : testlibtests.o testlib.o pch.h
	gcc -o tests testlibtests.o
	rm *.o



clean :
	rm tests *.o

BASEDIR:=$(PWD)/..
COMMON:=$(PWD)/../Common
COMMONTESTS=$(PWD)/../Common/tests

INCLUDES := -I$(BASEDIR)
INCLUDES += -I$(BASEDIR)/Common
INCLUDES += -I$(BASEDIR)/Common/tests

vpath %.h $(BASEDIR)/Common:$(BASEDIR)/Common/tests

COMMON_DEPS = $(COMMON)/testlib.c $(COMMON)/testlib.h $(COMMON)/pch.h
TEST_DEPS = $(COMMONTESTS)/CommonTests.c $(COMMON)/testlib.h $(COMMON)/pch.h
ALL_OBJS = $(COMMON)/testlib.o $(COMMONTESTS)/commontests.o


$(COMMON)/testlib.o : $(COMMON_DEPS)
	gcc -c $(COMMON)/testlib.c -o $(COMMON)/testlib.o $(INCLUDES)

$(COMMONTESTS)/commontests.o : $(TEST_DEPS)
	gcc -c $(COMMONTESTS)/commontests.c -o $(COMMONTESTS)/commontests.o $(INCLUDES)

all: $(ALL_OBJS)
	gcc -o $(COMMONTESTS)/tests $(ALL_OBJS) $(INCLUDES)

postbuildcleanup: 
	find $(BASEDIR)/ -name "*.o" -type f -delete


clean :
	rm $(BASEDIR)/Common/*.o
	rm $(BASEDIR)/Common/tests/*.o
	rm $(BASEDIR)/Common/tests/tests
	




















COMMON_TESTS := $(COMMON)/tests

COMMON_DEPS = $(COMMON)/testlib.c $(COMMON)/runtimedata.c $(COMMON)/runtimedata.h $(COMMON)/testlib.h $(COMMON)/pch.h
TEST_DEPS = $(COMMON_TESTS)/CommonTests.c $(COMMON)/testlib.h $(COMMON)/pch.h
ALL_OBJS = $(COMMON)/testlib.o $(COMMON_TESTS)/commontests.o $(COMMON)/runtimedata.o


CommonTests: DEBUG=$(DEBUG_UNIT_TEST)
CommonTests: $(ALL_OBJS)
	gcc -o $(COMMON_TESTS)/build.tests $(ALL_OBJS) $(INCLUDES) $(DEBUG)


verbose: DEBUG=$(DEBUG_VERBOSE)
verbose: $(ALL_OBJS)
	gcc -o $(COMMON_TESTS)/build.verbose $(ALL_OBJS) $(INCLUDES) $(DEBUG)


silent: DEBUG=$(DEBUG_NONE)
silent: $(ALL_OBJS)
	gcc -o $(COMMON_TESTS)/build.silent $(ALL_OBJS) $(INCLUDES) $(DEBUG)

$(COMMON)/testlib.o : $(COMMON_DEPS)
	gcc -c $(COMMON)/testlib.c -o $(COMMON)/testlib.o $(INCLUDES) $(DEBUG)

$(COMMON)/runtimedata.o : $(COMMON_DEPS)
	gcc -c $(COMMON)/runtimedata.c -o $(COMMON)/runtimedata.o $(INCLUDES) $(DEBUG)

$(COMMON_TESTS)/commontests.o : $(TEST_DEPS)
	gcc -c $(COMMON_TESTS)/commontests.c -o $(COMMON_TESTS)/commontests.o $(INCLUDES) $(DEBUG)

	
	




















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


DEBUG_UNIT_TEST = -D__DEBUG__=1 -D_CURRENT_DBG_LVL_=3
DEBUG_VERBOSE	= -D__DEBUG__=1 -D_CURRENT_DBG_LVL_=5
DEBUG_NONE		= -D__DEBUG__=0 -D_CURRENT_DBG_LVL_=0

tests: DEBUG=$(DEBUG_UNIT_TEST)
tests: $(ALL_OBJS)
	gcc -o $(COMMONTESTS)/tests $(ALL_OBJS) $(INCLUDES) $(DEBUG)
	$(MAKE) postbuildcleanup


verbose: DEBUG=$(DEBUG_VERBOSE)
verbose: $(ALL_OBJS)
	gcc -o $(COMMONTESTS)/verboseTests $(ALL_OBJS) $(INCLUDES) $(DEBUG)
	$(MAKE) postbuildcleanup


silent: DEBUG=$(DEBUG_NONE)
silent: $(ALL_OBJS)
	gcc -o $(COMMONTESTS)/silent $(ALL_OBJS) $(INCLUDES) $(DEBUG)
	$(MAKE) postbuildcleanup

$(COMMON)/testlib.o : $(COMMON_DEPS)
	gcc -c $(COMMON)/testlib.c -o $(COMMON)/testlib.o $(INCLUDES) $(DEBUG)

$(COMMONTESTS)/commontests.o : $(TEST_DEPS)
	gcc -c $(COMMONTESTS)/commontests.c -o $(COMMONTESTS)/commontests.o $(INCLUDES) $(DEBUG)

postbuildcleanup: 
	find $(BASEDIR)/ -name "*.o" -type f -delete

clean :
	$(MAKE) postbuildcleanup
	rm -f $(BASEDIR)/Common/tests/tests
	rm -f $(BASEDIR)/Common/tests/verboseTests
	rm -f $(BASEDIR)/Common/tests/silent
	
	




















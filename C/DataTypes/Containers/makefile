# BASEDIR:=$(PWD)/../..
# COMMON := $(BASEDIR)/Common
# DATATYPES := $(BASEDIR)/DataTypes
COMMON_TESTS := $(COMMON)/tests

CONTAINERS 		 := $(DATATYPES)/Containers
CONTAINERS_TESTS := $(DATATYPES)/Containers/tests

COMMON_OBJS 	:= $(COMMON)/testlib.o 
COMMON_OBJS		+= $(COMMON_TESTS)/commontests.o 
COMMON_OBJS		+= $(COMMON)/runtimedata.o

CONTAINER_OBJS 	:= $(CONTAINERS)/Nodes.o 

COMMON_DEPS 	:= $(COMMON)/pch.h
COMMON_DEPS 	+= $(COMMON)/RuntimeData.h
COMMON_DEPS 	+= $(COMMON)/TestLib.h

CONTAINER_DEPS 	:= $(CONTAINER)/Nodes.h

ContainerTests: DEBUG=$(DEBUG_UNIT_TEST)
ContainerTests: $(COMMON_OBJS) $(CONTAINER_OBJS)
	gcc -o $(CONTAINERS_TESTS)/build.tests $(COMMON_OBJS) $(CONTAINER_OBJS) $(INCLUDES) $(DEBUG)


verbose: DEBUG=$(DEBUG_VERBOSE)
verbose: $(COMMON_OBJS) $(CONTAINER_OBJS)
	gcc -o $(CONTAINERS_TESTS)/build.verbose $(COMMON_OBJS) $(CONTAINER_OBJS) $(INCLUDES) $(DEBUG)


silent: DEBUG=$(DEBUG_NONE)
silent: $(COMMON_OBJS) $(CONTAINER_OBJS)
	gcc -o $(CONTAINERS_TESTS)/build.silent $(COMMON_OBJS) $(CONTAINER_OBJS) $(INCLUDES) $(DEBUG)


$(CONTAINERS)/Nodes.o: $(COMMON_OBJS) $(CONTAINERS)/Nodes.h $(COMMON)/pch.h
	gcc -c $(CONTAINERS)/Nodes.c -o $(CONTAINERS)/Nodes.o $(INCLUDES) $(DEBUG)
	




















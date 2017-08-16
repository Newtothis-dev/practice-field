export DEBUG_UNIT_TEST = -D__DEBUG__=1 -D_CURRENT_DBG_LVL_=3
export DEBUG_VERBOSE	= -D__DEBUG__=1 -D_CURRENT_DBG_LVL_=5
export DEBUG_NONE		= -D__DEBUG__=0 -D_CURRENT_DBG_LVL_=0

export BASEDIR:=$(PWD)
export COMMON := $(BASEDIR)/Common
export DATATYPES := $(BASEDIR)/DataTypes


INCLUDES := -I$(BASEDIR)
INCLUDES += -I$(BASEDIR)/Common
INCLUDES += -I$(BASEDIR)/Common/tests
INCLUDES += -I$(BASEDIR)/DataTypes/
INCLUDES += -I$(BASEDIR)/DataTypes/Containers
INCLUDES += -I$(BASEDIR)/DataTypes/Containers/tests

export INCLUDES



tests:
	cd Common && $(MAKE) CommonTests && cd ../
	cd DataTypes/Containers && $(MAKE) ContainerTests cd ../../
	$(MAKE) postbuildcleanup


verbose:
	cd Common && $(MAKE) verbose && cd ../
	$(MAKE) postbuildcleanup


silent:
	cd Common && $(MAKE) silent && cd ../
	$(MAKE) postbuildcleanup


postbuildcleanup: 
	find . -name "*.o" -type f -delete

clean :
	$(MAKE) postbuildcleanup
	find . -name "build.*" -type f -delete
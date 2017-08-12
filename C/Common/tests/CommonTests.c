#include "pch.h"
#include "TestLib.h"

bool passTest()
{
	return true;
}

bool failTest()
{
	return false;
}



struct test_case_container passing_test = {.test_case=&passTest, .failure_statement="Failure Statement For passTest()"};
struct test_case_container failing_test = {.test_case=&failTest, .failure_statement="Failure Statement For failTest()"};
extern struct test_case_container terminal_test_case;


int main(int argc, char *argv[])
{

	#ifdef __DEBUG__
	printf("Debugging enabled!\n\r");
	#endif

#define _DBG_LVL_VERBOSE_   5
#define _DBG_LVL_HIGH_      4
#define _DBG_LVL_UNIT_TEST	3
#define _DBG_LVL_MEDIUM_    2
#define _DBG_LVL_LOW_       1

	switch(_CURRENT_DBG_LVL_)
	{
		case (_DBG_LVL_LOW_):
			printf("Current debug level is _DBG_LVL_LOW_\n\r");
		break;
		case(_DBG_LVL_MEDIUM_):
			printf("Current debug level is _DBG_LVL_MEDIUM_\n\r");
		break;
		case(_DBG_LVL_UNIT_TEST):
			printf("Current debug level is _DBG_LVL_UNIT_TEST\n\r");
		break;
		case(_DBG_LVL_HIGH_):
			printf("Current debug level is _DBG_LVL_HIGH_\n\r");
		break;
		case (_DBG_LVL_VERBOSE_):
			printf("Current debug level is _DBG_LVL_VERBOSE_\n\r");
		break;
		default:
			printf("Current Debug Level set to unsupported value\n\r");
		break;
	}

	struct test_case_container allPassingTests[] = 
	{
	passing_test, 
	passing_test,
	terminal_test_case
	};


	struct test_case_container oneFailingTest[] = 
	{
	passing_test, 
	failing_test,
	terminal_test_case
	};

	if (true == RunTests(1, allPassingTests) && false == RunTests(1, oneFailingTest))
	{
		printf("All tests passed\n\r");
		return 0;
	}
	printf("Some tests failed\n\r");
	return 1;
}
#include "Common/pch.h"
#include "Common/TestLib.h"
#include "Common/RuntimeData.h"

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


bool TestingBuidAndTestStructure()
{
	#ifdef __DEBUG__
	printf("Debugging enabled!\n\r");
	#endif

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
		return true;
	}
	printf("Some tests failed\n\r");
	return false;
}



int main(int argc, char *argv[])
{
	struct test_case_container CommonTests[] =
	{
		{.test_case=&TestingBuidAndTestStructure, 			.failure_statement="Build or Test Platform failure"},
		{.test_case=&TestBuildingIntRuntimeData, 			.failure_statement="Test Building Int Runtime Data failed"},
		{.test_case=&TestBuildingUnsignedIntRuntimeData, 	.failure_statement="Test Building Unsigned Int Runtime Data failed"},
		{.test_case=&TestBuildingFloadRuntimeData, 			.failure_statement="Test Building Float Runtime Data failed"},
		{.test_case=&TestBuildingBoolRuntimeData, 			.failure_statement="Test Building Bool Runtime Data failed"},
		{.test_case=&TestBuildingCharRuntimeData, 			.failure_statement="Test Building Char Runtime Data failed"},
		{.test_case=&TestBuildingInvalidRuntimeData,		.failure_statement="Test Building Invalid Runtime Data failed"},
		terminal_test_case
	};

	if (true == RunTests(_CURRENT_DBG_LVL_, CommonTests))
	{
		printf("All Tests Pass!\n\r");
		return 0;
	}

	printf("Some Test Failure\n\r");
	return 1;
	
}
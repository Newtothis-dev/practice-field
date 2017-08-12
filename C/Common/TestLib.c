#include "Common/TestLib.h"

struct test_case_container terminal_test_case = {.test_case = NULL, .failure_statement = NULL};


bool RunTests(int debugLevel, struct test_case_container test_case_array[])
{
	if (NULL != test_case_array)
	{
		for (int i = 0;
				NULL != test_case_array[i].test_case && !IS_TERMINAL_TEST(test_case_array[i]); 
			 	i++)
		{
			if ((test_case_array[i].test_case)())
			{
				continue;
			}
			if (!IS_TERMINAL_TEST(test_case_array[i]))
			{
				char *msg = test_case_array[i].failure_statement == NULL ? "<No Failure Statement>" : test_case_array[i].failure_statement
				dbgPrint(debugLevel, "Test Failure[%s]\n\r",msg);
			}
			return false;
		}
		return true;
	}
	return true;

}
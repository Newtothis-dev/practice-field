#include "TestLib.h"

struct test_case_container terminal_test_case = {.test_case = NULL, .failure_statement = NULL};


bool RunTests( struct test_case_container test_case_array[])
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
			printf("Test Failure[%s]\n\r",
				test_case_array[i].failure_statement == NULL ? 
					"<No Failure Statement>" : 
					test_case_array[i].failure_statement);
			return false;
		}
		return true;
	}
	return true;

}
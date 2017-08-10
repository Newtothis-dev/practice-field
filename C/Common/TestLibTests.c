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


struct test_case_container passing_test = {.test_case=&passTest, .failure_statement="This should never happen"};
struct test_case_container failing_test = {.test_case=&failTest, .failure_statement="This should always happen"};
//struct test_case_container ttc = {.test_case = NULL, .failure_statement = NULL};
extern struct test_case_container terminal_test_case;


int main()
{

	struct test_case_container tests[] = 
	{
	passing_test, 
	failing_test,
	terminal_test_case
	};


	if (true == RunTests(tests))
	{
		printf("All tests passed\n\r");
		return 0;
	}
	printf("Some tests failed\n\r");
	return 1;
}
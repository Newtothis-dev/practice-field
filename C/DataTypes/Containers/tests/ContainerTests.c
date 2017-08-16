#include "DataType/Containers/Node.h"


int main(int argc, char *argv[])
{
	struct test_case_container ContainerTests[] =
	{
		{.test_case=&TestBuildingSingleLinkedIntNode, 			.failure_statement="Build or Test Single Linked Node Failure"},
		terminal_test_case
	};

	if (true == RunTests(_CURRENT_DBG_LVL_, ContainerTests))
	{
		printf("All Tests Pass!\n\r");
		return 0;
	}

	printf("Some Test Failure\n\r");
	return 1;
	
}
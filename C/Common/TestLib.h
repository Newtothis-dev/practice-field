#include "pch.h"
#pragma once
/// @breif Method that runs a self contained test. 
typedef bool (*test_case_method_t)(void);

struct test_case_container
{
	test_case_method_t test_case;		///< Test case to be run
	char* failure_statement;			///< String literal contianing a statement to be printed if the test fails. 
};

/// @brief Takes an array of tests and runs all of them. 
/// @note the terminal test in the array must be a terminal_test_case (a test case with NULL for both values)
/// If there is no terminal test case the tests will seg fault
/// This testing methodology is used to allow users to test without caring how many tests are in the array
/// @returns True if all tests pass. If a test fails will print it's associated failure statement
bool RunTests( struct test_case_container test_case_array[]);

/// Macro allowing users to easily determine if something is the terminal statement. 
#define IS_TERMINAL_TEST(tc) (tc.test_case == NULL && tc.failure_statement == NULL)

/// Example terminal statement defined by TestLib to be used. 
extern struct test_case_container terminal_test_case;
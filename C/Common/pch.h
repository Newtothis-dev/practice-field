/*
	This is the 'Pre-Compiled Headder' file. This file should be 
	included in all files that are used within the project. It allows for
	a way to commonize information across all files that all files need. 
*/

#pragma once
#include <stdio.h>
#include <stdbool.h>



#define _CURRENT_DBG_LVL_ 	2 ///< Set to 2 unless user wants to up it    
#define _DBG_LVL_VERBOSE_   4
#define _DBG_LVL_HIGH_      3
#define _DBG_LVL_MEDIUM_    2
#define _DBG_LVL_LOW_       1



#if defined(__DEBUG__)
#define dbgPrint(dbgLvl, printString, ...) if (dbgLvl >= _CURRENT_DBG_LVL_) {printf(printString, __VA_ARGS__);}
#else 
#define dbgPrint(printString, ...) 
#endif 




/*
	This is the 'Pre-Compiled Headder' file. This file should be 
	included in all files that are used within the project. It allows for
	a way to commonize information across all files that all files need. 
*/

#pragma once
#include <stdio.h>
#include <stdbool.h>



  
#define _DBG_LVL_VERBOSE_   5
#define _DBG_LVL_HIGH_      4
#define _DBG_LVL_UNIT_TEST	3
#define _DBG_LVL_MEDIUM_    2
#define _DBG_LVL_LOW_       1

//#define _CURRENT_DBG_LVL_ _DBG_LVL_MEDIUM_ ///< Set by build flags, can enable manually though 

#ifndef _CURRENT_DBG_LVL_
#define _CURRENT_DBG_LVL_ _DBG_LVL_MEDIUM_
#endif


#if defined(__DEBUG__)
#define dbgPrint(dbgLvl, printString, ...) if (dbgLvl >= _CURRENT_DBG_LVL_) {printf(printString, __VA_ARGS__);}
#else 
#define dbgPrint(printString, ...) 
#endif 




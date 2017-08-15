#include "Common/pch.h"
#include "Common/TestLib.h"
#include "Common/RuntimeData.h"
#pragma once

typedef struct Node_t
{
	RuntimeData_t runtimeData;
	Node_t* pNext;

} Node_t;



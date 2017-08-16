#include "Common/pch.h"
#include "Common/TestLib.h"
#include "Common/RuntimeData.h"
#pragma once

typedef struct SingleLinkedNode_t
{
	RuntimeData_t runtime_data;
	struct SingleLinkedNode_t* pNext;

} SingleLinkedNode_t;

/// @brief builds a SingleLinkedNode of type @param type. 
SingleLinkedNode_t BuildSingleLinkNode(DataType_t type, void * data, int size);

#define GetNodeDataInt(RUNTIME_NODE) 			RUNTIME_NODE.runtime_data.data.i
#define GetNodeDataUnsignedInt(RUNTIME_NODE) 	RUNTIME_NODE.runtime_data.data.ui
#define GetNodeDataFloat(RUNTIME_NODE)			RUNTIME_NODE.runtime_data.data.f
#define GetNodeDataBool(RUNTIME_NODE) 			RUNTIME_NODE.runtime_data.data.b
#define GetNodeDataChar(RUNTIME_NODE) 			RUNTIME_NODE.runtime_data.data.ch

#define IsNodeTypeInt(RUNTIME_NODE) 			(bool)(RUNTIME_NODE.runtime_data.type == DataTypeInt)
#define IsNodeTypeUnsignedInt(RUNTIME_NODE) 	(bool)(RUNTIME_NODE.runtime_data.type == DataTypeUnsignedInt)
#define IsNodeTypeFloat(RUNTIME_NODE) 			(bool)(RUNTIME_NODE.runtime_data.type == DataTypeFloat)
#define IsNodeTypeBool(RUNTIME_NODE) 			(bool)(RUNTIME_NODE.runtime_data.type == DataTypeBool)
#define IsNodeTypeChar(RUNTIME_NODE) 			(bool)(RUNTIME_NODE.runtime_data.type == DataTypeChar)






///////////////// Tests ////////////////////

bool TestBuildingSingleLinkedIntNode();

// bool TestBuildingSingleLinkedUnsignedIntNode();

// bool TestBuildingSingleLinkedFloatNode();

// bool TestBuildingSingleLinkedBoolNode();

// bool TestBuildingSingleLinkedCharNode();

// bool TestBuildingSingleLinkedInvalidNode();
#include "DataTypes/Containers/Nodes.h"

SingleLinkedNode_t BuildSingleLinkNode(DataType_t type, void * data, int size)
{
	SingleLinkedNode_t sln;
	sln.runtime_data = BuildRuntimeData(type);

	bool 		 *bData 	= NULL;
	int 		 *iData 	= NULL;
	unsigned int *uiData 	= NULL;
	float 		 *fData 	= NULL;
	char  		 *cData 	= NULL;

	/// Set the type
	switch (type)
	{
		case DataTypeBool:
			bData = (bool *) data;
			GetNodeDataBool(sln) = *bData;
			sln.runtime_data.initialized = true;
			break;
		case DataTypeInt:
			iData = (int *) data;
			GetNodeDataInt(sln) = *iData;
			sln.runtime_data.initialized = true;
			break;
		case DataTypeUnsignedInt:
			uiData = (unsigned int *) data;
			GetNodeDataUnsignedInt(sln) = *uiData;
			sln.runtime_data.initialized = true;
			break;
		case DataTypeFloat:
			fData = (float *) data;
			GetNodeDataFloat(sln) = *fData;
			sln.runtime_data.initialized = true;
			break;
		case DataTypeChar:
			cData = (char *) data;
			memcpy(&GetNodeDataChar(sln)[0], cData, size);
			sln.runtime_data.initialized = true;
			break;
		default:
			break;
	}
	return sln;
}



bool TestBuildingSingleLinkedIntNode()
{
	int SomeInt = 10;
	SingleLinkedNode_t sln = BuildSingleLinkNode(DataTypeInt, (void *)&SomeInt, 0);
	return IsNodeTypeInt(sln) && GetNodeDataInt(sln) == 10;
}
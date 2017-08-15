#include "Common/RuntimeData.h"

RuntimeData_t BuildRuntimeData( DataType_t type)
{
	RuntimeData_t rtd;
	rtd.initialized = false;
	memset(&rtd.data.ch[0], 0, sizeof(rtd.data.ch));

	/// Set the type
	switch (type)
	{

		case DataTypeBool:
			rtd.data.b = false;
		case DataTypeInt:
		case DataTypeUnsignedInt:
		case DataTypeFloat:
		case DataTypeChar:
			rtd.type = type;
			break;
		default:
			rtd.type = DataTypeInvalid;
			break;
	}
	return rtd;
}


bool TestBuildingIntRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeInt);
	return GetRuntimeInt(rtd) == 0 && 
		true == IsRuntimeInt(rtd) && 
		false == IsRuntimeDataInitialized(rtd);
}

bool TestBuildingUnsignedIntRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeUnsignedInt);
	return GetRuntimeUnsignedInt(rtd) == 0 && 
		IsRuntimeUnsignedInt(rtd) && 
		false == IsRuntimeDataInitialized(rtd);
}

bool TestBuildingFloadRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeFloat);
	return GetRuntimeFloat(rtd) == 0 && 
		IsRuntimeFloat(rtd) && 
		false == IsRuntimeDataInitialized(rtd);
}

bool TestBuildingBoolRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeBool);
	return GetRuntimeBool(rtd) == false && 
		IsRuntimeBool(rtd) && 
		false == IsRuntimeDataInitialized(rtd);
}

bool TestBuildingCharRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeChar);
	return GetRuntimeChar(rtd)[0] == 0 && 
		IsRuntimeChar(rtd) && 
		false == IsRuntimeDataInitialized(rtd);
}

bool TestBuildingInvalidRuntimeData()
{
	RuntimeData_t rtd = BuildRuntimeData(DataTypeMax);
	bool bPass = rtd.type == DataTypeInvalid; 

	rtd = BuildRuntimeData(DataTypeInvalid);
	bPass &= rtd.type == DataTypeInvalid;

	rtd = BuildRuntimeData(-1);
	bPass &= rtd.type == DataTypeInvalid;

	return bPass && false == IsRuntimeDataInitialized(rtd); 
}






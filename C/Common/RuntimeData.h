#include "Common/pch.h"

#ifndef MAX_DATA_SIZE
#define MAX_DATA_SIZE 256
#endif


typedef union Data_t
{
	unsigned int ui;
	int i; 
	float f; 
	bool b;
	char ch[MAX_DATA_SIZE];
} Data_t;

typedef enum DataType_t
{
	DataTypeInvalid 		= 0x00,
	DataTypeInt 			= 0x01, 
	DataTypeUnsignedInt 	= 0x02,
	DataTypeFloat 			= 0x04,
	DataTypeBool 			= 0x08,
	DataTypeChar 			= 0x10,
	DataTypeMax 			= 0x20
}DataType_t;

typedef struct RuntimeData_t
{
	Data_t data; 
	DataType_t type;
	bool initialized;
}RuntimeData_t;



#define GetRuntimeInt(RUNTIME_DATA) 			RUNTIME_DATA.data.i
#define GetRuntimeUnsignedInt(RUNTIME_DATA) 	RUNTIME_DATA.data.ui
#define GetRuntimeFloat(RUNTIME_DATA)			RUNTIME_DATA.data.f
#define GetRuntimeBool(RUNTIME_DATA) 			RUNTIME_DATA.data.b
#define GetRuntimeChar(RUNTIME_DATA) 			RUNTIME_DATA.data.ch

#define IsRuntimeInt(RUNTIME_DATA) 			(bool)(RUNTIME_DATA.type == DataTypeInt)
#define IsRuntimeUnsignedInt(RUNTIME_DATA) 	(bool)(RUNTIME_DATA.type == DataTypeUnsignedInt)
#define IsRuntimeFloat(RUNTIME_DATA) 		(bool)(RUNTIME_DATA.type == DataTypeFloat)
#define IsRuntimeBool(RUNTIME_DATA) 		(bool)(RUNTIME_DATA.type == DataTypeBool)
#define IsRuntimeChar(RUNTIME_DATA) 		(bool)(RUNTIME_DATA.type == DataTypeChar)

#define IsRuntimeDataInitialized(RUNTIME_DATA)	RUNTIME_DATA.initialized == true

/// @brief factory method to build a default runtime data type
RuntimeData_t BuildRuntimeData(DataType_t type);


///////////////// Tests ////////////////////

bool TestBuildingIntRuntimeData();

bool TestBuildingUnsignedIntRuntimeData();

bool TestBuildingFloadRuntimeData();

bool TestBuildingBoolRuntimeData();

bool TestBuildingCharRuntimeData();

bool TestBuildingInvalidRuntimeData();





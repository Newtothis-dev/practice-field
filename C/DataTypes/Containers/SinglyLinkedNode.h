#include <stdlib.h> 
#include "CustomType.h"
#pragma once

struct Node
{
    void* data; 
    void* pNextNode;
};

typedef void (*node_data_destructor)(void *);

/// @brief: Node factory method, assumes that the data within node cannot be NULL
/// @param: ppNode Address of a pointer to a Node so that the factory can populate that data
/// @param: data, pointer to a piece of data 
bool NodeFactory(struct Node** ppNode, void *data);



/// @brief Destroys a node properly
/// @note: Assumes that a node's contents do not need to be destroyed
/// updates/improvements would take a function pointer to handle the node data
bool NodeDestructor(struct Node** ppNode, node_data_destructor fnDestructor);




bool TestBasicBuildAndPopulate();
bool TestBasicBuildAndDestroy();

/// @brief Node Factory Unit test
bool IsNodeFactoryWorking(int* failedTest);
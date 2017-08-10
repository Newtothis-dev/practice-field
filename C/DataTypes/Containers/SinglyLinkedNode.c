#include "Node.h"



/// @brief: Node factory method, assumes that the data within node cannot be NULL
/// @param: ppNode Address of a pointer to a Node so that the factory can populate that data
/// @param: data, pointer to a piece of data 
bool NodeFactory(struct Node** ppNode, void *data)
{
    bool bBuildNode = false;
    if (data)
    {
        struct Node* newNode = malloc(sizeof(struct Node)); 
        if (newNode)
        {
            (*ppNode) = newNode; 
            (*ppNode)->data = data;
            (*ppNode)->pNextNode = NULL;
            bBuildNode = true;
        }
    }
    return bBuildNode;
}

/// @brief Destroys a node properly
/// @param: fnDestructor is the data destructor for node data
/// @note: Assumes data requires no destruction method if is NULL
bool NodeDestructor(struct Node** ppNode, node_data_destructor fnDestructor)
{
    if (NULL == (*ppNode))
    {
        return false;
    }

    if (NULL != fnDestructor)
    {
        (*fnDestructor)((*ppNode)->data);
        if (NULL != (*ppNode)->data)
        {
            return false;
        }
    }

    free(*ppNode);
    if (NULL == (*ppNode))
    {
        return true;
    }

    return false;
}



bool TestBasicBuildAndPopulate()
{
    struct Node* pNodeOne = NULL;
    int const compareVal = 10;
    int data01 = compareVal; 
    if (NodeFactory(&pNodeOne, &data01))
    {
        if (pNodeOne && (compareVal == *((int*)(pNodeOne->data))))
        {
            return true;
        }
    }
    return false;
}

void TestDataDestructor(void *data)
{
    return;
}

bool TestBasicBuildAndDestroy()
{
    struct Node* pNodeOne = NULL;
    int const compareVal = 10;
    int data01 = compareVal; 
    if (NodeFactory(&pNodeOne, &data01))
    {
        if (NodeDestructor(&pNodeOne, &TestDataDestructor))
        {
            if (NULL == pNodeOne)
            {
                return true;
            }
        }
    }
    return false;
}

/// @brief Node Factory Unit test
bool IsNodeFactoryWorking(int* failedTest)
{
    bool bPassedAllTests = true;


    struct Node* pNodeOne = NULL;
    int data01 = 10; 
    if (bPassedAllTests && 
        !TestBasicBuildAndPopulate())
    {
        /// Expected to pass 
        *failedTest = 1;
        bPassedAllTests = false;
    }

    return bPassedAllTests;
}
#include "LinkedList.h"
/// @brief get's the length of the linked list
unsigned long length(struct LinkedList* list)
{
    if (list)
    {
        return list->length;
    }
    return 0;
}


/// @brief inserts at @param location if possible. 
/// @note for locations > length just appends.
bool insert(struct LinkedList* list, void *Data, unsigned long location)
{
   
    struct Node* pNode; 
    if (NULL == list || 
        NULL == Data || 
        !NodeFactory(&pNode, Data))
    {
        dbgPrint(_DBG_LVL_HIGH_, "\t%s: did not insert [%s] data to [%s] list\n\r", __FUNCTION__, 
            NULL != Data ? "Non-null" : "Null",
            NULL != list ? "Non-null" : "Null");
        return false;
    }

    dbgPrint(_DBG_LVL_VERBOSE_, "\t%s: inserting into list of length [%lu]\n\r", __FUNCTION__, list->length);

    if (NULL == list->Head)
    {
        dbgPrint(_DBG_LVL_HIGH_, "\t%s: inserting at position 0\n\r", __FUNCTION__);
        list->Head = pNode; 
        list->Tail = pNode->pNextNode;
    }
    else if (location > list->length)
    {
        dbgPrint(_DBG_LVL_HIGH_, "\t%s: inserting at end of list\n\r", __FUNCTION__);
        list->Tail->pNextNode = pNode;
        list->Tail = pNode;
        list->Tail->pNextNode = NULL;
    }
    else if (0 == location)
    {
        pNode->pNextNode = list->Head;
        list->Head = pNode;
    }
    else 
    {
        struct Node* pTempNode = list->Head;
        for (unsigned long i = 0; i < location-1; ++i)
        {
            dbgPrint(_DBG_LVL_VERBOSE_, "\t%s: Stepping through list\n\r", __FUNCTION__);
           
            if (NULL != pTempNode)
            {
                pTempNode = list->Tail;
                continue;
            }
            dbgPrint(_DBG_LVL_HIGH_, "\t%s: Found Null Node Before Length Represented End Of List\n\r", __FUNCTION__);
            return false;
        }
        struct Node* pOtherTempNode = pTempNode->pNextNode;
        pTempNode->pNextNode = pNode;
        pNode->pNextNode = pOtherTempNode;
    }
    list->length++;

    return true;
}


/// @brief adds Data to the end of the list. 
/// TODO: Refactor to use insert
bool append(struct LinkedList* list, void *Data)
{
    if (NULL == list)
    {
        return false;
    }
    return insert(list, Data, list->length);
    // struct Node* pNode; 
    // if (!NodeFactory(&pNode, Data))
    // {
    //     return false;
    // }
    // if (NULL == list->Head)
    // {
    //     list->Head = pNode; 
    //     list->Tail = pNode;
    //     list->length = 1;
    // }
    // else
    // {
    //     list->Tail->pNextNode = pNode;
    //     list->Tail = pNode;
    //     list->Tail->pNextNode = NULL;
    //     list->length++;
    // }

    // return true;
}

/// @brief adds data to the the start of the list
/// TODO: Refactor to use insert
bool prepend(struct LinkedList* list, void *Data)
{
    return insert(list, Data, 0);
    // struct Node* pNode; 
    // if (!NodeFactory(&pNode, Data))
    // {
    //     return false;
    // }

    // struct Node* temp = list->Head;
    // list->Head = pNode;
    // list->Head->pNextNode = temp;
    // list->length++;

    // return true;
}

/// @brief get's the data at @param: location if possible
/// @note returns false if location is invalid. 
void* get(struct LinkedList* list, unsigned long location)
{
    struct Node* pNode = list->Head;
    void* Data = NULL;

    if (location > list->length)
    {
        dbgPrint(_DBG_LVL_VERBOSE_, "\t%s: Get Location is greater than length\n\r",__FUNCTION__);
        return Data;
    }

    for (unsigned long l = 0; l < list->length && (NULL != pNode); ++l)
    {
        if (location == l)
        {
            Data = pNode->data;
            break;
        }

        pNode = pNode->pNextNode;
    }

    return Data; 
}

/// @brief gets the location of data within the list. 
bool contains(struct LinkedList* list, void* Data, unsigned long *location, data_compare_function fnCompare)
{

    if (NULL == list || NULL == Data)
    {
        return false;
    }

    bool bDoesContain = false;
    struct Node* pNode = list->Head;
    for (unsigned long l = 0; 
        !bDoesContain && l < list->length && (NULL != pNode); 
        ++l)
    {
        bDoesContain = fnCompare == NULL ? 
            pNode->data == Data : 
            (fnCompare)(pNode->data, Data);
        
        if (bDoesContain && (NULL != location))
        {
            *location = l;
        }
        pNode = pNode->pNextNode;
    }

    return bDoesContain;
}

/// @brief removes data at @param location
void* removeItemAt(struct LinkedList* list, unsigned long location)
{
    struct Node* pNode = list->Head;
    struct Node* pPriorNode = NULL;
    void* Data = NULL;

    if (location > list->length)
    {
        return Data;
    }

    for (unsigned long l = 0; l < list->length && (NULL != pNode); ++l)
    {
        if (location == l)
        {
            Data = pNode->data;
            break;
        }
        pPriorNode = pNode;
        pNode = pNode->pNextNode;
    }

    if (MAX_LENGTH != list->length && 
        NULL != pNode)
    {
        if (NULL != pPriorNode)
        {
        pPriorNode->pNextNode = pNode->pNextNode;
        }
        list->length--;
        NodeDestructor(&pNode, NULL);
    }

    /// Assert pNode is null
    return Data; 
}

/// @brief removes specific data from the list
bool removeItem(struct LinkedList* list, void*Data, data_compare_function fnCompare)
{
    return false;
}


bool printIntLinkedList(struct LinkedList* list)
{
    if (!list)
    {
        printf("Invalid list passed to printer\n\r");
        return false;
    }
    printf("LinkedList of Integers:");
    struct Node* pNode = list->Head;
    if (NULL == pNode)
    {
        printf("<empty>");
    }
    else
    {
        for (unsigned long i = 0; i < MAX_LENGTH && (NULL != pNode); i++)
        {
            int* someInt = pNode->data;
            printf("%s[%d]",i>0 ? ",":"",(*someInt));
            pNode = pNode->pNextNode;
        }
    }
    
    printf("\n\r");

    return true;
}


bool resetList(struct LinkedList* list)
{
    if (list)
    {
        list->Head = NULL;
        list->Tail = NULL;
        list->length = 0;
        return true;
    }
    return false;
}









bool IsLinkedListWorking(int *failedTest)
{

    test_case_method_t test_case_method_array[] = 
    {
        &TestLengthAndResetOfList,  
        &TestAppendAndGet,          
        &TestPrependAndGet,         
        &TestContains,
        &TestRemoveItemAt,              
        /// ... 
        NULL/// MUST be last item in list or will seg fault
    };

    *failedTest = -1;

    for (int i = 0; NULL != test_case_method_array[i]; i++)
    {
        if ( false == test_case_method_array[i]())
        {
            *failedTest = i;
            return false;
        } 
    }

    return true;
}


bool intCompare(void *data, void* other)
{
    int* iData = data;
    int* iOther = other;
    return (*iData) == (*iOther);
}










bool TestLengthAndResetOfList()
{
    dbgPrint(_DBG_LVL_LOW_, "Starting %s\n\r", __FUNCTION__);
    struct LinkedList ll; 
    return resetList(&ll) && 
        ll.Head == NULL &&
        ll.Tail == NULL &&
        ll.length == 0 &&
        0 == length(&ll);
}


bool TestAppendAndGet()
{
    dbgPrint(_DBG_LVL_LOW_, "Starting %s\n\r", __FUNCTION__);
    struct LinkedList ll; 
    if (!resetList(&ll))
    {
        return false;
    }
    int dataList[] = {1,2,3,4,5};
    for (unsigned long i = 0; i < 5; ++i)
    {
        int someValue = -1; 
        int* somePtr = &someValue;
        if (false == append(&ll, &dataList[i]) || 
            NULL == get(&ll, i) || 
            length(&ll) != (i+1))
        {
            printf("TestAppendAndGet:length[%lu] newVal[%d] iterVal[%lu]\n\r",
            length(&ll), dataList[i], i);
            return false;
        }

        void* got = get(&ll, i);
        if (*(int*)(got) != dataList[i])
        {
            printf("Got[%d] expected [%d]\n\r", 
                *(int*)(got), dataList[i]);
            return false;
        }

    }
    return true;
}


bool TestPrependAndGet()
{
    dbgPrint(_DBG_LVL_LOW_, "Starting %s\n\r", __FUNCTION__);
    struct LinkedList ll; 
    if (!resetList(&ll))
    {
        return false;
    }


    int prependList[] = {1,2,3,4,5};
    for (unsigned long i = 0; i < 5; ++i)
    {
        
        int someValue = -1; 
        int* somePtr = &someValue;
        if (false == prepend(&ll, &prependList[i]))
        {
            dbgPrint(_DBG_LVL_MEDIUM_, "%s: prepend failed on [%d:%lu]\n\r", __FUNCTION__, prependList[i],i);
            return false;
        }

        int* got = get(&ll, 0);
        if (NULL == got || (*got) != prependList[i])
        {
            dbgPrint(_DBG_LVL_MEDIUM_, "%s: get failed iteration [%lu] because [%s]. Expected [%d] got [%d]\n\r", 
                __FUNCTION__, 
                i,
                NULL == got ? "item not in list" : "incorrect item found", 
                prependList[i], 
                NULL == got ? -1 : *got);
            return false;
        }
        if (length(&ll) != (i+1))
        {
            dbgPrint(_DBG_LVL_MEDIUM_, "%s: length increment failed on [%d:%lu]\n\r", __FUNCTION__, prependList[i],i);
            return false;
        }
    }
    return true;
}


bool TestContains()
{
    dbgPrint(_DBG_LVL_LOW_, "Starting %s\n\r", __FUNCTION__);
    struct LinkedList ll; 
    if (!resetList(&ll))
    {
        return false;
    }
    int dataList[] = {1,2,3,4,5};
    for (unsigned long i = 0; i < 5; ++i)
    {
        int someValue = -1; 
        int* somePtr = &someValue;
        unsigned long location = 0;
        if (false == append(&ll, &dataList[i]) || 
            NULL == get(&ll, i) || 
            length(&ll) != (i+1) || 
            false == contains(&ll, &dataList[i], &location, &intCompare) || 
            location != i)
        {
            printf("TestContains:length[%lu] newVal[%d] iterVal[%lu]\n\r",
            length(&ll), dataList[i], i);
            return false;
        }
    }
    return true;
}



bool TestRemoveItemAt()
{
    dbgPrint(_DBG_LVL_LOW_, "Starting %s\n\r", __FUNCTION__);
    struct LinkedList ll; 
    resetList(&ll);

    int llData[] = {0,1,2, -1};
    int notInLL = 10;
    for (int i = 0; llData[i] != -1;)
    {
        append(&ll, &llData[i++]);
    }

    removeItemAt(&ll, 2);
    removeItemAt(&ll, 1);

    return false == contains(&ll, &llData[1], NULL, &intCompare) 
        && false == contains(&ll, &llData[2], NULL, &intCompare)
        && true == contains(&ll, &llData[0], NULL, &intCompare)
        && false == contains(&ll, &notInLL, NULL, &intCompare);
}






bool DisplayLinkedListFunctionality()
{
    struct LinkedList ll; 
    resetList(&ll);

    int llData[] = {1,3,5,7,9,2,4,6,8,10}; // 10 items

    for (int i = 0; i < 10;)
    {
        
        append(&ll, &llData[i++]);
        printf("Appended: %d\n\r", llData[i-1]);
        printf("Prepend: %d\n\r", llData[i]);
        prepend(&ll, &llData[i++]);
    }
    // 10,6,2,7,3,1,5,9,4,8
    printf("Expected:\n\r[10],[6],[2],[7],[3],[1],[5],[9],[4],[8]\n\rReceived:\n\r");
    printIntLinkedList(&ll);

    return true;
} 
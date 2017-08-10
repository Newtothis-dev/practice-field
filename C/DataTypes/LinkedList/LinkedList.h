#include "Node.h"
#include "CustomType.h"
#include <stdio.h>

#pragma once
#define MAX_LENGTH (unsigned long)-1





struct LinkedList
{
    struct Node* Head;
    struct Node* Tail;
    unsigned long length; 

};


typedef bool (*data_compare_function)(void *, void *);


/// @brief get's the length of the linked list
/// @note: Returns 0 if list is invalid.
unsigned long length(struct LinkedList* list);

/// @brief inserts at @param location if possible. 
/// @note for locations > length just appends.
bool insert(struct LinkedList* list, void *Data, unsigned long location);

/// @brief adds Data to the end of the list. 
bool append(struct LinkedList* list, void *Data);

/// @brief adds data to the the start of the list
bool prepend(struct LinkedList* list, void *Data);

/// @brief get's the data at @param: location if possible
/// @note returns false if location is invalid. 
void* get(struct LinkedList* list, unsigned long location);

/// @brief gets the location of data within the list. 
bool contains(struct LinkedList* list, void* Data, unsigned long *location, data_compare_function fnCompare);

/// @brief removes data at @param location
void* removeItemAt(struct LinkedList* list, unsigned long location); 

/// @brief removes specific data from the list
bool removeItem(struct LinkedList* list, void*Data, data_compare_function fnCompare); 

/// @brief printList
bool printIntLinkedList(struct LinkedList* list);

/// @brief zero's a linked list
/// @note: Assumes no items in linked list. 
bool resetList(struct LinkedList* list);

////////////////////////////////////////////////////////////////////////
/////////////// Tests
////////////////////////////////////////////////////////////////////////


bool IsLinkedListWorking(int* failedTest); 

bool TestLengthAndResetOfList();

bool TestAppendAndGet();

bool TestPrependAndGet();

bool TestContains();

bool TestRemoveItemAt();

bool DisplayLinkedListFunctionality();
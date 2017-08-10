#include <stdio.h>
#include "CustomType.h"
#include "Node.h"
#include "LinkedList.h"

#define __VERBOSE__ 

bool HandleFailure(int failValue, const char* posFailValString, const char* negFailValString)
{
    if ( failValue < 0)
    {
        dbgPrint(_DBG_LVL_VERBOSE_, "%s\n\r",negFailValString);
        return false;
    }

    dbgPrint(_DBG_LVL_VERBOSE_, "Test %d failed [%s]\n\r",failValue, posFailValString);
    return true;
}


bool TestsPass()
{
    int failedTest = -1;
    bool bFailed = false;
    if (!bFailed && !IsNodeFactoryWorking(&failedTest))
    {
        HandleFailure(failedTest,
        "IsNodeFactoryWorking has shown the node factory is not working",
        "Invalid failure value, Node factory broken");
        bFailed = true;
    }

    if (!bFailed && !IsLinkedListWorking(&failedTest))
    {
        HandleFailure(failedTest,
        "IsLinkedListWorking has shown the linked list is not working",
        "Invalid failure value, Linked List Broken");
        bFailed = true;
    }




    return !bFailed;
}


int main(int argc, char *argv[])
{

    /// Run all unit tests: 
    if (!TestsPass())
    {
        dbgPrint(_DBG_LVL_VERBOSE_, "%s: Library is broken, tests failing\n\r", __FUNCTION__);
        return 1;
    }
    else
    {
        dbgPrint(_DBG_LVL_VERBOSE_, "%s: All tests passed, continuing to program\n\r", __FUNCTION__);
    }

    
    DisplayLinkedListFunctionality();
}

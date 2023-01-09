#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
/*Searching for a specific user*/
Member *SearchingAccount(char *name, char *password, Member *headM)
{
    Member *currentM;
    currentM = headM->next;
    while ((currentM != NULL) && (strcmp(currentM->UserName, name) != 0) && (strcmp(currentM->Password, password) != 0))
    {
        currentM = currentM->next;
    }
    if (currentM == NULL)
    {
        return NULL;
    }
    if ((strcmp(currentM->UserName, name) != 0) || (strcmp(currentM->Password, password) != 0))
    {
        return NULL;
    }
    else
    {
        return currentM;
    }
}
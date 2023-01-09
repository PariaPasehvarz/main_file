#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Add a new member of structure of users*/
Member *CreatingNewAccount(Member *headM, char *name, char *password)
{
    Member *NewNode;
    Member *currentM;
    int i, j;
    int len1, len2;
    len1 = strlen(name);
    len2 = strlen(password);
    NewNode = (struct MembersInfo *)malloc(sizeof(struct MembersInfo));
    if (NewNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headM;
    }
    NewNode->Password = (char *)malloc(sizeof(char) * len2);
    if (NewNode->Password == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headM;
    }
    NewNode->UserName = (char *)malloc(sizeof(char) * len1);
    if (NewNode->UserName == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headM;
    }
    strcpy(NewNode->UserName, name);
    strcpy(NewNode->Password, password);
    NewNode->Status = 0;
    currentM = headM;
    while (currentM->next != NULL)
    {
        currentM = currentM->next;
    }
    NewNode->NoUser = (currentM->NoUser) + 1;
    currentM->next = NewNode;
    NewNode->next = NULL;
    return headM;
}

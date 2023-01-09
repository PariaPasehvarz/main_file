#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*User wants Like sb's post*/
Posts *LikeCom(Posts *headP, Member *headM)
{
    int i;
    Member *currentM;
    Posts *currentP;
    /*Extract UserName and PostID*/
    char *name;
    int postid;
    name = strtok(NULL, " ");
    postid = atoi(strtok(NULL, " "));
    if (postid == '\0')
    {
        printf("Name or PostID didn't entered!\n");
        return headP;
    }
    /*Search for the user that is in her account now*/
    currentM = headM;
    if (currentM->next == NULL)
    {
        printf("You should login first\n");
        return headP;
    }
    while (currentM != NULL)
    {
        if (currentM->Status == 1)
        {
            break;
        }
        currentM = currentM->next;
    }
    if (currentM == NULL)
    {
        printf("You should login first\n");
        return headP;
    }
    /*Finding post*/
    currentP = headP;
    while ((currentP != NULL))
    {
        if ((strcmp(currentP->Owner, name) == 0) && (currentP->PostID == postid))
        {
            break;
        }
        currentP = currentP->next;
    }
    if (currentP == NULL)
    {
        printf("This post does not exist\n");
        return headP;
    }
    currentP->Array = (int *)realloc(currentP->Array, sizeof(int));
    if (currentP->Array == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headP;
    }
    for (i = 0; i <= currentP->Like; i++)
    {
        if (currentP->Array[i] == currentM->NoUser)
        {
            printf("You can not like one post twice\n");
            return headP;
        }
    }
    currentP->Array[currentP->Like] = currentM->NoUser;
    (currentP->Like)++;
    return headP;
}
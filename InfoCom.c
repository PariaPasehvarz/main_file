#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*User wants to see her info*/
int InfoCom(Member *headM, Posts *headP)
{
    Member *currentM;
    Posts *currentP;
    /*Search for the user that is in her account now*/
    currentM = headM;
    if (currentM->next == NULL)
    {
        printf("You should login first\n");
        return 0;
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
        return 0;
    }
    printf("The UserName is %s\n", currentM->UserName);
    printf("The Password is %s\n", currentM->Password);
    currentP = headP->next;
    while ((currentP != NULL))
    {
        if ((strcmp(currentP->Owner, currentM->UserName) == 0))
        {
            printf("PostID: %d\n", currentP->PostID);
            printf("Likes: %d\n", currentP->Like);
            printf("Text: %s\n", currentP->Text);
        }
        currentP = currentP->next;
    }
    return 0;
}
#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Delete a post*/
Posts *DeleteCom(Member *headM, Posts *headP)
{
    Member *currentM;
    Posts *currentP;
    Posts *previousP;
    int PostNum;
    PostNum = atoi(strtok(NULL, " "));
    /*Check for proper input*/
    if (PostNum == '\0')
    {
        printf("You didn't entered your postID!\n");
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
    /*Check if user has any posts and if she has any post with that postID*/
    currentP = headP;
    while ((currentP != NULL))
    {
        if ((strcmp(currentP->Owner, currentM->UserName) == 0) && (currentP->PostID == PostNum))
        {
            break;
        }
        previousP = currentP;
        currentP = currentP->next;
    }
    if (currentP == NULL)
    {
        printf("This user does not have any post with this PostID\n");
        return headP;
    }
    /*Deleting post*/
    previousP->next = currentP->next;
    free(currentP);
    return headP;
}
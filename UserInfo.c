#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*User wants to see sb's info*/
int UserInfo(char *temp, Member *headM, Posts *headP, int lenght)
{
    int i, j;
    Member *currentM;
    Posts *currentP;
    char *text;
    text = (char *)malloc(sizeof(char) * (lenght - 9));
    if (text == NULL)
    {
        printf("Unable to allocate memory!\n");
        return 0;
    }
    /*Extract text part from input string*/
    for (i = 9, j = 0; i <= lenght; i++, j++)
    {
        text[j] = temp[i];
    }
    /*Check if user has done login*/
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
    currentM = headM->next;
    while ((currentM != NULL))
    {
        if ((strcmp(currentM->UserName, text) == 0))
        {
            printf("UserName: %s\n", currentM->UserName);
            printf("PassWord: %s\n", currentM->Password);
            break;
        }
        currentM = currentM->next;
    }
    if (currentM == NULL)
    {
        printf("This user does not exists\n");
        return 0;
    }
    currentP = headP->next;
    while ((currentP != NULL))
    {
        if ((strcmp(currentP->Owner, text) == 0))
        {
            printf("PostID: %d\n", currentP->PostID);
            printf("Likes: %d\n", currentP->Like);
            printf("Text: %s\n", currentP->Text);
        }
        currentP = currentP->next;
    }
    return 0;
}
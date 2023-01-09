#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Create a post*/
Posts *PostCom(char *temp, Member *headM, Posts *headP, int lenght)
{
    int i = 0, j = 0;
    Member *currentM;
    Posts *currentP;
    Posts *NewPost;
    char *text;
    text = (char *)malloc(sizeof(char) * (lenght));
    if (text == NULL)
    {
        printf("Unable to allocate memory!\n");
        return headP;
    }
    /*Extract text part from input string*/
    for (i = 5, j = 0; i <= lenght; i++, j++)
    {
        text[j] = temp[i];
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
    /*Allocating memory for new post*/
    NewPost = (struct PostsInfo *)malloc(sizeof(struct PostsInfo));
    if (NewPost == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headP;
    }
    NewPost->Text = (char *)malloc(sizeof(char) * (lenght));
    if (NewPost->Text == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headP;
    }
    NewPost->Owner = (char *)malloc(sizeof(currentM->UserName));
    if (NewPost->Owner == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headP;
    }
    NewPost->Array = (int *)malloc(sizeof(int));
    if (NewPost->Array == NULL)
    {
        printf("Unable to allocate memory.\n");
        return headP;
    }
    /*Copy the name of user in her account into Owner name*/
    strcpy(NewPost->Owner, currentM->UserName);
    strcpy(NewPost->Text, text);
    NewPost->Like = 0;
    /*Finding the last post someone posted*/
    currentP = headP;
    while (currentP->next != NULL)
    {
        currentP = currentP->next;
    }
    NewPost->PostID = (currentP->PostID) + 1;
    currentP->next = NewPost;
    NewPost->next = NULL;
    return headP;
}

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "MyStruct_Funcs.h"
#define ACCOUNTSFILE "accounts.txt"
#define POSTSFILE "posts.txt"
#define ONE 1
int main()
{
    int i, j;
    int lenght;
    int result;
    char *message;
    char *temp;
    char *command;
    char str1[15];
    char str2[15];
    char str3[15];
    char str4[15];
    char str5[15];
    char str6[15];
    char str7[15];
    char str8[15];
    char str9[15];
    strcpy(str1, "signup");
    strcpy(str2, "login");
    strcpy(str3, "logout");
    strcpy(str4, "post");
    strcpy(str5, "like");
    strcpy(str6, "delete");
    strcpy(str7, "info");
    strcpy(str8, "userinfo");
    strcpy(str9, "exit_program");
    /*Creating head with non specific data*/
    Member *headM;
    Member *currentM;
    Posts *headP;
    Posts *currentP;
    headM = (struct MembersInfo *)malloc(sizeof(struct MembersInfo));
    if (headM == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headM->Password = (char *)malloc(sizeof(char));
    if (headM->Password == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headM->UserName = (char *)malloc(sizeof(char));
    if (headM->UserName == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headP = (struct PostsInfo *)malloc(sizeof(struct PostsInfo));
    if (headP == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headP->Text = (char *)malloc(sizeof(char));
    if (headP->Text == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headP->Array = (int *)malloc(sizeof(int));
    if (headP->Array == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    headP->Owner = (char *)malloc(sizeof(char));
    if (headP->Array == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 0;
    }
    strcpy(headM->UserName, "A");
    strcpy(headM->Password, "B");
    headM->NoUser = 0;
    headM->NoPosts = -1;
    headM->Status = -1;
    headM->next = NULL;
    headP->PostID = 0;
    headP->Like = 0;
    strcpy(headP->Text, "C");
    strcpy(headP->Owner, "A");
    headP->Array[0] = 0;
    headP->next = NULL;
    printf("Hello! Welcome to my program. Please select your command.\n");
    result = 0;
    while (result != 1)
    {
        /*Get string from user and store it*/
        message = InputString(stdin, 10);
        /*strtok function change the string after use, so we have to store it*/
        lenght = strlen(message);
        temp = (char *)malloc(sizeof(char) * lenght);
        strcpy(temp, message);
        /*Extract first word of string, that is command*/
        command = strtok(message, " ");
        if (strcmp(command, str1) == 0)
        {
            headM = SignupCom(headM);
            printf("Any other command?\n");
        }
        if (strcmp(command, str2) == 0)
        {
            headM = LoginCom(temp, headM);
            printf("Any other command?\n");
        }
        if (strcmp(command, str3) == 0)
        {
            headM = LogoutCom(temp, headM);
            printf("Any other command?\n");
        }
        if (strcmp(command, str4) == 0)
        {
            headP = PostCom(temp, headM, headP, lenght);
            printf("Any other command?\n");
        }
        if (strcmp(command, str5) == 0)
        {
            headP = LikeCom(headP, headM);
            printf("Any other command?\n");
        }
        if (strcmp(command, str6) == 0)
        {
            headP = DeleteCom(headM, headP);
            printf("Any other command?\n");
        }
        if (strcmp(command, str7) == 0)
        {
            InfoCom(headM, headP);
            printf("Any other command?\n");
        }
        if (strcmp(command, str8) == 0)
        {
            UserInfo(temp, headM, headP, lenght);
            printf("Any other command?\n");
        }
        if (strcmp(command, str9) == 0)
        {
            result = 1;
        }
        if (strcmp(command, str1) != 0 && strcmp(command, str2) != 0 && strcmp(command, str3) != 0 && strcmp(command, str4) != 0 && strcmp(command, str5) != 0 && strcmp(command, str6) != 0 && strcmp(command, str7) != 0 && strcmp(command, str8) != 0 && strcmp(command, str9) != 0)
        {
            printf("This command does not exist. Please try again!\n");
        }
    }
    /*Initialize all Post numbers with 1*/
    currentM = headM->next;
    while (currentM != NULL)
    {
        currentM->NoPosts = 0;
        currentM = currentM->next;
    }
    /*Get the number of posts for each person*/
    currentM = headM->next;
    while (currentM != NULL)
    {
        currentP = headP->next;
        while (currentP != NULL)
        {
            if (strcmp(currentP->Owner, currentM->UserName) == 0)
            {
                (currentM->NoPosts)++;
            }
            currentP = currentP->next;
        }
        currentM = currentM->next;
    }
    /*Write data in file*/
    FILE *accounts = fopen(ACCOUNTSFILE, "w");
    currentM = headM->next;
    while (currentM != NULL)
    {
        fputs(currentM->UserName, accounts);
        fwrite(" ", sizeof(char), ONE, accounts);
        fputs(currentM->Password, accounts);
        fwrite(" ", sizeof(char), ONE, accounts);
        fprintf(accounts, "%d", currentM->NoPosts);
        fwrite("\n", sizeof(char), ONE, accounts);
        currentM = currentM->next;
    }
    fclose(accounts);
    FILE *posts = fopen(POSTSFILE, "w");
    currentP = headP->next;
    while (currentP != NULL)
    {
        fputs(currentP->Text, posts);
        fwrite(" ", sizeof(char), ONE, posts);
        fputs(currentP->Owner, posts);
        fwrite(" ", sizeof(char), ONE, posts);
        fprintf(posts, "%d", currentP->Like);
        fwrite("\n", sizeof(char), ONE, posts);
        currentP = currentP->next;
    }
    fclose(posts);
    /*Free allocated memories*/
    currentM = headM->next;
    while (currentM != NULL)
    {
        free(currentM);
        free(currentM->UserName);
        free(currentM->Password);
        currentM = currentM->next;
    }
    currentP = headP->next;
    while (currentP != NULL)
    {
        free(currentP);
        free(currentP->Text);
        free(currentP->Owner);
        free(currentP->Array);
        currentP = currentP->next;
    }
    free(message);
    printf("See you soon!\n");
    getch();
    return 0;
}
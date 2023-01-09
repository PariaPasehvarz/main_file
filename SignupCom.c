#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
/*A new member wants to register to our program*/
Member *SignupCom(Member *headM)
{
    Member *currentM;
    /*Extract name and Password*/
    char *name;
    char *password;
    name = strtok(NULL, " ");
    password = strtok(NULL, " ");
    if (password == NULL)
    {
        printf("Name or password didn't entered!\n");
        return headM;
    }
    currentM = headM->next;
    while (currentM != NULL)
    {
        if (currentM->Status == 1)
        {
            printf("Some one is in her account.You can not signup now.\n");
            return headM;
        }
        currentM = currentM->next;
    }
    /*Checking if usernames are same*/
    currentM = headM;
    while (currentM != NULL)
    {
        if (strcmp(currentM->UserName, name) == 0)
        {
            printf("This username already exists. Please try again!\n");
            return headM;
        }
        currentM = currentM->next;
    }
    headM = CreatingNewAccount(headM, name, password);
    return headM;
}
#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
/*Member wants to login her account*/
Member *LoginCom(char *temp, Member *headM)
{
    Member *Node;
    Member *currentM;
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
            printf("Some one is in her account.You can not login now\n");
            return headM;
        }
        currentM = currentM->next;
    }
    Node = SearchingAccount(name, password, headM);
    if (Node == NULL)
    {
        printf("User not found!\n");
        return headM;
    }
    Node->Status = 1;
    return headM;
}
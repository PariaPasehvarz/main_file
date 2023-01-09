#include "MyStruct_Funcs.h"
#include <stdio.h>
#include <string.h>
/*Member wants to logout her account*/
Member *LogoutCom(char *temp, Member *headM)
{
    Member *Node;
    char *name;
    char *password;
    name = strtok(NULL, " ");
    password = strtok(NULL, " ");
    if (password == NULL)
    {
        printf("Name or password didn't entered!\n");
        return headM;
    }
    Node = SearchingAccount(name, password, headM);
    if (Node == NULL)
    {
        return headM;
    }
    if (Node->Status == 0)
    {
        printf("This user has done logout\n");
        return headM;
    }
    if (Node->Status == 1)
    {
        Node->Status = 0;
    }
    return headM;
}
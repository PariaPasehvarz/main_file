#include <stdio.h>
/*My Structures*/
typedef struct PostsInfo Posts;
struct PostsInfo
{
    int PostID;
    int Like;
    char *Text;
    /*This array stores NoUser of people who liked a post*/
    int *Array;
    char *Owner;
    Posts *next;
};
typedef struct MembersInfo Member;
struct MembersInfo
{
    int NoPosts;
    int NoUser;
    char *UserName;
    char *Password;
    /*If user has done log in, the Status is 1, otherwise 0.*/
    int Status;
    Member *next;
};
/*Decleration of functions*/
Member *CreatingNewAccount(Member *headM, char *name, char *password);
Member *SignupCom(Member *headM);
Member *SearchingAccount(char *name, char *password, Member * headM);
Member *LogoutCom(char *temp, Member *headM);
Member *LoginCom(char *temp, Member *headM);
Posts *PostCom(char *temp, Member *headM, Posts *headP, int lenght);
Posts *DeleteCom(Member *headM, Posts *headP);
Posts *LikeCom(Posts *headP, Member *headM);
int InfoCom(Member *headM, Posts *headP);
int UserInfo(char *temp, Member *headM, Posts *headP, int lenght);
char *InputString(FILE *fp, size_t size);
///////////////
// Libraries //
///////////////

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <mysql/mysql.h>

////////////////
// Structures //
////////////////

typedef struct user {
  int id_user;
  char name[15];
  char l_name[20];
  char type_of[20];
  int id_institution;
} User;

////////////////
// Prototypes //
////////////////

extern void __HELP();
extern void strUpper(char *str);
extern bool strCheck(char *str);
extern void dbInit(MYSQL *mysql);
extern void logIn(char *user_name, char *password, MYSQL *mysql);
extern void dbQuery(char *buffer, MYSQL *mysql, MYSQL_RES **res);
extern void userType(char *type);
extern void setStruct(char cont[][20], User *usr);
extern void notNUll(MYSQL_ROW row, char cont[][20], int x);
extern void setMenu(User usr);
extern int strInt(char *str);
extern void optionMenu(User usr, int x);
extern void optionInsert(char *type_of);
extern void optionQuery(char *type_of);

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
// Prototypes //
////////////////

extern void __HELP();
extern void strUpper(char *str);
extern bool strCheck(char *str);
extern void dbInit(MYSQL *mysql);
extern void logIn(char *user_name, char *password, MYSQL *mysql);
extern void dbQuery(char *buffer, MYSQL *mysql, MYSQL_RES **res);

////////////////
// Structures //
////////////////

typedef struct user {
  int id_user;
  char name[15];
  char l_name[20];
  char l_name2[20];
  char email[40];
  char username[10];
  char password[10];
  char phone[15];
  char address[100];
  char rfc[13];
  char type_of[3];
  int id_institution;
} User;

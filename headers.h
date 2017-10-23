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

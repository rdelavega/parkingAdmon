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

typedef struct vehicle {
  int id_vehicle;
  char record[20];
} Vehicle;

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
extern void setMenu(User usr,MYSQL *mysql);
extern int strInt(char *str);
extern void optionMenu(User usr, int x, MYSQL *mysql);
extern void optionInsert(char *type_of);
extern void optionQuery(char *type_of);
extern void insertRoute(User usr, int x, MYSQL *mysql);
extern void queryRoute(User usr, int x, MYSQL *mysql);
extern bool dbInsert(char *buffer, MYSQL *mysql);
extern void addInstitute(MYSQL * mysql);
extern bool valForced(char sFor[][100], int x);
extern bool valNotForced(char nFor[][100], int x);
extern void saveInstitute(MYSQL *mysql, char sFor[][100], char nFor[][100]);
extern void addUser(MYSQL *mysql, User usr);
extern int selInstitute(MYSQL *mysql, User usr);
extern int selType(char *usertype);
extern void saveUser(char sFor[][100], char nFor[][100], char *inst, MYSQL *mysql);
extern int selVehicle(MYSQL *mysql, int usr, char *ctr);
extern void addState(MYSQL *mysql);
extern int selState(MYSQL *mysql);
extern int selSector(MYSQL *mysql);
extern int selParking(MYSQL *mysql);
extern void addSector(MYSQL *mysql);
extern void addType(MYSQL *mysql);
extern int selParkingType(MYSQL *mysql);
extern void addParking(MYSQL *mysql, User usr);
extern float strFloat (char *str);
extern int selParkingInstitute(MYSQL *mysql, int usr);
extern void addSchedule(MYSQL *mysql, User usr);
extern void addVehicle(MYSQL *mysql, User usr);
extern void addPark(MYSQL *mysql, User usr);
extern void visitedParking(MYSQL *mysql);
extern void usersParking(MYSQL *mysql);
extern void parkingSector(MYSQL *mysql);
extern void usersRegis(MYSQL *mysql);
extern void scheduleParking(MYSQL *mysql);
extern void sectorUsers(MYSQL *mysql);
extern void hourParking(MYSQL *mysql);
extern void usersSector(MYSQL *mysql);
extern void space(MYSQL *mysql);

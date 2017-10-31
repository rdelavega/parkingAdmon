#include "headers.h"

/*****************************************
* Comparar si es un inicio de sesion    *
* valido, en caso de serlo, guardar sus *
* datos en un estructura.               *
* @method logIn                         *
* @param  user_name user_name           *
* @param  password  contrasena          *
* @param  mysql     pointer a DB        *
*****************************************/

void logIn(char *user_name, char *password, MYSQL *mysql) {
        char account[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        User usr;

        sprintf(account, "SELECT name, l_name, typeof, id_user, id_institution FROM p1_users WHERE username = '%s' AND password = '%s'", user_name, password);
        dbQuery(account,mysql,&res);

        if (!(row = mysql_fetch_row(res))) {

                printf("\n\n\n\tUsuario o contraseña incorrectos\n\tIntenta de nuevo!!!\n\n\n");

        } else {
                char cont[mysql_num_fields(res)][20];
                notNUll(row,cont,mysql_num_fields(res));
                setStruct(cont,&usr);

                printf("\n\n\n\tBienvenido: %s %s (%s)\n\n",usr.name,usr.l_name,usr.type_of);
                printf("\tPresione Enter para continuar...");
                getchar();

                setMenu(usr,mysql);
        }

        mysql_free_result(res);
}

/*****************************************
* Verifica si el valor regresado por el *
* query es nulo, de serlo regresa una   *
* cadena vacia.                         *
* @method notNUll                       *
* @param  row     resultset             *
* @param  cont    String array          *
* @param  x       fields                *
*****************************************/

void notNUll(MYSQL_ROW row, char cont[][20], int x) {
        for (int i = 0; i < x; i++) {
                if (row[i] != NULL) {
                        strcpy(cont[i],row[i]);
                } else {
                        strcpy(cont[i],"");
                }
        }
}

/************************************
* Guarda los datos del query en la *
* estructura del usuario.          *
* @method setStruct                *
* @param  cont      String array   *
* @param  usr       user struct    *
************************************/

void setStruct(char cont[][20], User *usr) {
        strcpy(usr->name,cont[0]);
        strcpy(usr->l_name,cont[1]);
        userType(cont[2]);
        strcpy(usr->type_of,cont[2]);
        usr->id_user = strInt(cont[3]);

        if (strcmp(cont[4],"") == 0) {
                usr->id_institution = -1;
        } else {
                usr->id_institution = strInt(cont[4]);
        }
        printf("%d\n", usr->id_institution);
        printf("%d\n", usr->id_user);
}

/*************************************
* Regresa un String del nombre del  *
* tipo de uusuario, segun mascara   *
* binaria.                          *
* @method userType                  *
* @param  type     pointer a String *
*************************************/

void userType(char *type) {
        if (strcmp(type,"00") == 0) {
                strcpy(type,"Superuser");
        } else if (strcmp(type,"01") == 0) {
                strcpy(type,"Administrador");
        } else if (strcmp(type,"10") == 0) {
                strcpy(type,"Cliente");
        }
}

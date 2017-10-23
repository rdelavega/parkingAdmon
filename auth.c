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

        sprintf(account, "SELECT * FROM p1_users WHERE username = '%s' AND password = '%s'",user_name,password);

        dbQuery(account,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < mysql_num_fields(res); i++) {
                        if (row[i]!=NULL) {
                                printf("%s\t", row[i]);
                        } else {
                                printf("--\t");
                        } // if
                } // for
                printf("\n");
        } // while

        mysql_free_result(res);
}

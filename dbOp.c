#include "headers.h"

/********************************
* Inicializar la base de datos *
* @method dbInit.              *
* @param  mysql  pointer a DB  *
********************************/

void dbInit(MYSQL *mysql) {
        char *server = "localhost";
        char *user = "ic15rvb";
        char *password = "196190";
        char *db = "ic15rvb";

        mysql_init(mysql);

        if (!mysql_real_connect(mysql,server,user,password,db,0,NULL,0)) {
                printf("Error al conectarse a la base de datos %s\n", mysql_error(mysql));
                exit(1);
        }// if

        if (mysql_select_db(mysql,db)) {
                printf("Error al seleccionar %s\n", mysql_error(mysql));
                exit(1);
        }// if
}

/************************************
* Control de errores e inicializar *
* al guardar y ejecutar el comando *
* del query en res.                *
* @method dbQuery                  *
* @param  buffer  query            *
* @param  mysql   pointer a DB     *
* @param  res     poimnter a res   *
************************************/

void dbQuery(char *buffer, MYSQL *mysql, MYSQL_RES **res) {
        if (mysql_query(mysql,buffer)) {
                printf("Error al ejecutar query %s\n", mysql_error(mysql));
                exit(1);
        } // if

        if (!(*res=mysql_store_result(mysql))) {
                printf("Error al obtener el resultset %s\n", mysql_error(mysql));
                exit(1);
        } // if
}

/************************************
* Control de errores e inicializar *
* al ejecutar el comando insert.   *
* @method dbQuery                  *
* @param  buffer  comando          *
* @param  mysql   pointer a DB     *
************************************/

void dbInsert(char *buffer, MYSQL *mysql) {
        if (mysql_query(mysql,buffer)) {
                printf("Error al ejecutar query %s\n", mysql_error(mysql));
                exit(1);
        } // if
}

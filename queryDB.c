#include "headers.h"

/**********************************************************
* Muestra las opciones de las organizaciones registradas *
* o si el nivel del usuario es Administrador devuelve su *
* mismo id_institution                                   *
* @method selInstitute                                   *
* @param  mysql        pointer a db                      *
* @param  usr          user's struct                     *
* @return              Eleccion (id_institution)         *
**********************************************************/

int selInstitute(MYSQL *mysql, User usr) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 1, num[100];
        bool val = false;
        if (strcmp(usr.type_of,"Superuser") == 0) {
                sprintf(buffer,"SELECT id_institution, name FROM p1_institution");
                dbQuery(buffer,mysql,&res);
                if (!(row = mysql_fetch_row(res))) {
                        printf("\n\tNo hay organizaciones registradas\n");
                        opc = -1;
                } else {
                        printf("\n\tElige una organizacion:\n");
                        printf("\t\t%s) %s\n", row[0], row[1]);
                        sprintf(str,"%s\n",row[0]);
                        num[0] = strInt(str);
                        while ((row = mysql_fetch_row(res))) {
                                printf("\t\t%s) %s\n", row[0], row[1]);
                                sprintf(str,"%s\n",row[0]);
                                num[i] = strInt(str);
                                i++;
                        }
                        fgets(str,20,stdin);
                        opc = strInt(str);
                        for (int j = 0; j < i; j++) {
                                if (opc == num[j]) {
                                        val = true;
                                }
                        }
                        if (val != true) {
                                opc = -1;
                        }
                }
        } else if (strcmp(usr.type_of,"Administrador") == 0) {
                opc = usr.id_institution;
        }
        return opc;
}

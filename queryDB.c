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

int selVehicle(MYSQL *mysql, int usr, char *ctr) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 1;
        Vehicle car[100];
        bool val = false;

        sprintf(buffer,"SELECT brand, model, record FROM p1_vehicle");
        dbQuery(buffer,mysql,&res);

        printf("\n\n\tElige un vehiculo:\n");
        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%d) %s, %s (%s)\n", i, row[0], row[1], row[3]);
                sprintf(car[i-1].record,"%s",row[3]);
                car[i-1].id_vehicle = i;
                i++;
        }

        if ((i-1) == 0) {
                printf("\n\tNo hay vehiculos registrados!!\n");
                opc = -1;
                strcpy(ctr,"NULL");
        } else {
                fgets(str,20,stdin);
                opc = strInt(str);
                for (int j = 0; j < (i-1); j++) {
                        if (opc == car[j].id_vehicle) {
                                val = true;
                                strcpy(ctr,car[j].record);
                        }
                }
                if (val != true) {
                        opc = -1;
                }
        }
        return opc;
}

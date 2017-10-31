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

/*******************************************************
* Muestra al usuarios los vehiculos que le pertenecen *
* y regresa como pointer su matricula.                *
* @method selVehicle                                  *
* @param  mysql      pointer a db                     *
* @param  usr        user's struct                    *
* @param  ctr        matricula                        *
* @return            -1 opcion invalida               *
*******************************************************/

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
                printf("\t\t%d) %s, %s (%s)\n", i, row[0], row[1], row[2]);
                sprintf(car[i-1].record,"%s",row[2]);
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

/*********************************************************
* Muestra los estados registrados y permite al usuario  *
* seleccionar uno.                                      *
* @method selState                                      *
* @param  mysql    pointer a DB                         *
* @return          -1 opcion invalida                   *
*********************************************************/

int selState(MYSQL *mysql) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 0, num[100];
        bool val = false;

        sprintf(buffer,"SELECT id_state, name FROM p1_state");
        dbQuery(buffer,mysql,&res);

        printf("\n\n\tElige un estado:\n");
        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s) %s\n", row[0], row[1]);
                sprintf(str,"%s\n",row[0]);
                num[i] = strInt(str);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay estados registrados!!\n");
                opc = -1;
        } else {
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
        return opc;
}

/*********************************************************
* Muestra las zonas registradas y permite al usuario    *
* seleccionar uno.                                      *
* @method selSector                                     *
* @param  mysql    pointer a DB                         *
* @return          -1 opcion invalida                   *
*********************************************************/

int selSector(MYSQL *mysql) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 0, num[100];

        int x = selState(mysql);
        if (x != -1) {
                sprintf(buffer,"SELECT id_sector, name FROM p1_sector WHERE id_state = %d",x);
                dbQuery(buffer,mysql,&res);

                printf("\n\n\tElige un sector:\n");
                while ((row = mysql_fetch_row(res))) {
                        printf("\t\t%d) %s\n", (i+1), row[1]);
                        sprintf(str,"%s\n",row[0]);
                        num[i] = strInt(str);
                        i++;
                }

                if (i == 0) {
                        printf("\n\tNo hay zonas registradas!!\n");
                        opc = -1;
                } else {
                        fgets(str,20,stdin);
                        opc = strInt(str);
                        if (opc >= 1 && opc <= (i+1)) {
                                opc = num[(opc-1)];
                        }
                }
        } else {
                opc = -1;
        }
        return opc;
}

/*********************************************************
* Muestra los estac. registrados y permite al usuario   *
* seleccionar uno.                                      *
* @method selParking                                    *
* @param  mysql    pointer a DB                         *
* @return          -1 opcion invalida                   *
*********************************************************/

int selParking(MYSQL *mysql) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 0, num[100];
        bool val = false;

        int x = selSector(mysql);
        if (x != -1) {
                sprintf(buffer,"SELECT id_parking, address FROM p1_parking WHERE id_sector = %d",x);
                dbQuery(buffer,mysql,&res);

                printf("\n\n\tElige un estacionamiento:\n");
                while ((row = mysql_fetch_row(res))) {
                        printf("\t\t%d) %s\n", (i+1), row[1]);
                        sprintf(str,"%s\n",row[0]);
                        num[i] = strInt(str);
                        i++;
                }

                if (i == 0) {
                        printf("\n\tNo hay estacionamientos registrados!!\n");
                        opc = -1;
                } else {
                        fgets(str,20,stdin);
                        opc = strInt(str);
                        if (opc >= 1 && opc <= (i+1)) {
                                opc = num[(opc-1)];
                        }
                }
        } else {
                opc = -1;
        }
        return opc;
}

/*********************************************************
* Muestra los estac. registrados y permite al usuario   *
* seleccionar uno de una organizacion                   *
* @method selParkingInstitute                           *
* @param  mysql    pointer a DB                         *
* @return          -1 opcion invalida                   *
*********************************************************/

int selParkingInstitute(MYSQL *mysql, int usr) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 0, num[100];
        bool val = false;

        sprintf(buffer,"SELECT id_parking, address FROM p1_parking WHERE id_institution = %d",usr);
        dbQuery(buffer,mysql,&res);

        printf("\n\n\tElige un estacionamiento:\n");
        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%d) %s\n", (i+1), row[1]);
                sprintf(str,"%s\n",row[0]);
                num[i] = strInt(str);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay estacionamientos registrados!!\n");
                opc = -1;
        } else {
                fgets(str,20,stdin);
                opc = strInt(str);
                if (opc >= 1 && opc <= (i+1)) {
                        opc = num[(opc-1)];
                }
        }

        return opc;
}

/**************************************************
* Muestar los distintos tipos de estacionamiento *
* que hay registrados y regresa la decision.     *
* @method  selParkingType                        *
* @param   mysql   pointer a DB                  *
* @return  opc     -1 Opcion invalida            *
**************************************************/

int selParkingType(MYSQL *mysql) {
        char buffer[1024], str[20];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int opc = 0, i = 0, num[100];
        bool val = false;

        sprintf(buffer,"SELECT id_type, typeof FROM p1_type");
        dbQuery(buffer,mysql,&res);

        printf("\n\n\tElige un Tipo:\n");
        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s) %s\n", row[0], row[1]);
                sprintf(str,"%s\n",row[0]);
                num[i] = strInt(str);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay tipos registrados!!\n");
                opc = -1;
        } else {
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
        return opc;
}

/************************************************
* Muestra al usuario los estacionamientos mas  *
* visitados.                                   *
* @method  visitedParking                      *
* @param   mysql   pointer a DB                *
************************************************/

void visitedParking(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        sprintf(buffer,"SELECT address AS parked FROM p1_parking LEFT JOIN p1_park USING(id_parking) GROUP BY address HAVING count(id_parking) = (SELECT count(id_parking) AS parked FROM p1_park GROUP BY id_parking ORDER BY parked DESC LIMIT 1) ORDER BY parked DESC;");
        dbQuery(buffer,mysql,&res);

        system("clear");
        printf("\n\n\n\tEstacionamientos mas visitados\n\n\n\n");

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/**********************************************************
* Muestra a las personas que visitan mas estacionamientos *
* diferentes.                                             *
* @method   usersParking                                  *
* @param    mysql   pointer a DB                          *
**********************************************************/

void usersParking(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        sprintf(buffer,"SELECT concat(l_name,' ',l_name2,', ',name) AS nombre FROM p1_park LEFT JOIN p1_vehicle USING(record) LEFT JOIN p1_users USING(id_user) GROUP BY id_user HAVING count(DISTINCT id_parking) = (SELECT count(DISTINCT id_parking) FROM p1_park LEFT JOIN p1_vehicle USING(record) LEFT JOIN p1_users USING(id_user) GROUP BY id_user ORDER BY count(DISTINCT id_parking) DESC LIMIT 1)");
        dbQuery(buffer,mysql,&res);

        system("clear");
        printf("\n\n\n\tPersonas que mas estacionamientos visitan\n\n\n\n");

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/***********************************************************
* Tras obtener el id de la zona deseada, muestra el query *
* de cuantos estacionamientos estan disponibles.          *
* @method  parkingSector                                  *
* @param   mysql   pointer a DB                           *
***********************************************************/

void parkingSector(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tEstacionamientos disponibles en una zona determinada\n\n\n\n");

        int x = selSector(mysql);

        sprintf(buffer,"SELECT address FROM p1_parking LEFT JOIN p1_sector USING(id_sector) LEFT JOIN p1_park USING(id_parking) WHERE exitof IS NULL AND id_sector = %d GROUP BY id_parking HAVING count(id_park) < avg(sizeof);",x);
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();

}

/*******************************************
* Muestra una lista de todos los Usuarios *
* actualmente registrados.                *
* @method  usersRegis                     *
* @param   mysql   pointer a DB           *
*******************************************/

void usersRegis(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tUsuarios registrados en el sistema\n\n\n\n");

        sprintf(buffer,"SELECT concat(l_name,', ',name) AS nombre FROM p1_users ORDER BY l_name;");
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/****************************************
* Despues de que el usuario seleccione *
* un estacionamiento, se despliega una *
* lista de sus horarios.               *
* @method  scheduleParking             *
* @param   mysql   pointer a DB        *
****************************************/

void scheduleParking(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tHorarios de un estacionamiento en particular\n\n\n\n");

        int x = selParking(mysql);

        sprintf(buffer,"SELECT DAY, startof, endof FROM p1_schedule LEFT JOIN p1_parking USING(id_parking) WHERE id_parking = %d ORDER BY DAY;",x);
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t| %s | %s | %s |\n", row[0], row[1], row[2]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/**************************************
* Muestra una lista de las zonas mas *
* concurridas.                       *
* @param   mysql                     *
**************************************/

void sectorUsers(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tZonas mas concurridas\n\n\n\n");

        sprintf(buffer,"SELECT name FROM p1_park LEFT JOIN p1_parking USING(id_parking) LEFT JOIN p1_sector USING(id_sector) GROUP BY id_sector HAVING count(id_park) = (SELECT count(id_park) FROM p1_park LEFT JOIN p1_parking USING(id_parking) GROUP BY id_sector ORDER BY count(id_park) DESC LIMIT 1);");
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/************************************************
* Despues de obtener el id del estacionamiento *
* deseado, muestra un horario de los Horarios  *
* mas concurridos.                             *
* @method  hourParking                         *
* @param   mysql   pointer a DB                *
************************************************/

void hourParking(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tHorarios mas concurridos por estacionamiento\n\n\n\n");

        int x = selParking(mysql);

        sprintf(buffer,"SELECT hour(entryof) FROM p1_park LEFT JOIN p1_parking USING(id_parking) WHERE id_parking = %d GROUP BY hour(entryof) HAVING count(id_park) = (SELECT count(id_park) FROM p1_park LEFT JOIN p1_parking USING(id_parking) WHERE id_parking = %d GROUP BY hour(entryof) ORDER BY count(id_park) DESC LIMIT 1);",x,x);
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s horas\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/************************************************
* Despues de recibir el id de la zona deseada, *
* muestra una lista del o los horarios mas     *
* concurridos.                                 *
* @mathod  usersSector                         *
* @param   mysql   pointer a DB                *
************************************************/

void usersSector(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tHorarios mas concurridos por estacionamiento\n\n\n\n");

        int x = selSector(mysql);

        sprintf(buffer,"SELECT hour(entryof) FROM p1_park LEFT JOIN p1_parking USING(id_parking) LEFT JOIN p1_sector USING(id_sector) WHERE id_sector = %d GROUP BY hour(entryof) HAVING count(id_park) = (SELECT count(id_park) FROM p1_park LEFT JOIN p1_parking USING(id_parking) LEFT JOIN p1_sector USING(id_sector) WHERE id_sector = %d GROUP BY hour(entryof) ORDER BY count(id_park) DESC LIMIT 1);",x,x);
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s horas\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/**************************************************
* Despues de recinir el id de el estacionamiento *
* deseado, se muestra el numero de lugares       *
* disponibñes.                                   *
* @method  space                                 *
* @param   mysql   pointer a DB                  *
**************************************************/

void space(MYSQL *mysql) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;

        system("clear");
        printf("\n\n\n\tLugares disponibles en un estacionamiento particular\n\n\n\n");

        int x = selParking(mysql);

        sprintf(buffer,"SELECT p1_resta(sizeof,count(id_park)) AS disponibles FROM p1_parking LEFT JOIN p1_park USING(id_parking) WHERE id_parking = %d AND exitof IS NULL GROUP BY id_parking HAVING count(id_park) < avg(sizeof);",x);
        dbQuery(buffer,mysql,&res);

        while ((row = mysql_fetch_row(res))) {
                printf("\t\t%s lugares disponibles\n", row[0]);
                i++;
        }

        if (i == 0) {
                printf("\n\tNo hay registros!!\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/*******************************************************
* Solicita al usuario dos fechas, para posteriormente *
* desplegar una lista de los lugares en los que ha    *
* estado y de que tipo era.                           *
* @method  typePlaces                                 *
* @param   mysql   pointer a DB                       *
* @param   usr     user's struct                      *
*******************************************************/

void typePlaces(MYSQL *mysql, User usr) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;
        char sFor[2][100];

        system("clear");
        printf("\n\n\n\tTipos de lugares usados\n\n\n\n");

        printf("\tFecha inicio (AAAA-MM-DD)\n");
        fgets(sFor[0],100,stdin);

        printf("\tFecha fin (AAAA-MM-DD)\n");
        fgets(sFor[1],100,stdin);

        printf("\n\n\n");

        if (valForced(sFor,2) == true) {

                sprintf(buffer,"SELECT record, date(entryof), tp.typeof FROM p1_park LEFT JOIN p1_vehicle USING(record) LEFT JOIN p1_users USING(id_user) LEFT JOIN p1_parking USING(id_parking) LEFT JOIN p1_type AS tp USING(id_type) WHERE id_user = %d AND date(entryof) >= %s AND date(entryof) <= %s ORDER BY date(entryof);",usr.id_user,sFor[0],sFor[1]);
                dbQuery(buffer,mysql,&res);

                while ((row = mysql_fetch_row(res))) {
                        printf("\t\t| Matricula: %s | Fecha: %s | Tipo: %s |\n", row[0],row[1],row[2]);
                        i++;
                }

                if (i == 0) {
                        printf("\n\tNo hay registros!!\n");
                }

        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

/*******************************************
* Muestra al usuario el monto total entre *
* dos fechas que el mismo proporciona.    *
* @mathod  total                          *
* @param   mysql   pointer a DB           *
* @param   usr     user's struct          *
*******************************************/

void total(MYSQL *mysql, User usr) {
        char buffer[1024];
        MYSQL_RES *res;
        MYSQL_ROW row;
        int i = 0;
        char sFor[2][100];

        system("clear");
        printf("\n\n\n\tMonto total\n\n\n\n");

        printf("\tFecha inicio (AAAA-MM-DD)\n");
        fgets(sFor[0],100,stdin);

        printf("\tFecha fin (AAAA-MM-DD)\n");
        fgets(sFor[1],100,stdin);

        printf("\n\n\n");

        if (valForced(sFor,2) == true) {

                sprintf(buffer,"SELECT ty.typeof, sum(p1_rate(timestampdiff(MINUTE,entryof,exitof),rate)) AS total FROM p1_park LEFT JOIN p1_vehicle USING(record) LEFT JOIN p1_users USING(id_user) LEFT JOIN p1_parking AS prki USING(id_parking) LEFT JOIN p1_type AS ty USING(id_type) WHERE exitof IS NOT NULL AND id_user = %d AND date(entryof) >= %s AND date(entryof) <= %s GROUP BY id_type;",usr.id_user,sFor[0],sFor[1]);
                dbQuery(buffer,mysql,&res);

                while ((row = mysql_fetch_row(res))) {
                        printf("\t\t| Tipo: %s | Total: $%s |\n", row[0],row[1]);
                        i++;
                }

                if (i == 0) {
                        printf("\n\tNo hay registros!!\n");
                }

        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }

        printf("\n\n\n\tPresione Enter para continuar...");
        getchar();
}

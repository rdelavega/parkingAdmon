#include "headers.h"

/*******************************
* Primer menu que se muestra  *
* @method setMenu             *
* @param  usr     User struct *
*******************************/

void setMenu(User usr,MYSQL *mysql) {
        char str[20];
        int opc = 0;
        do {
                system("clear");
                printf("\n\n\tElige una opcion:\n\n");
                printf("\t\t1) Agregar a la base de datos.\n");
                printf("\t\t2) Consultas a la base de datos.\n");
                printf("\t\t0) Salir del sistema\n");
                fgets(str,20,stdin);
                opc = strInt(str);
                if (opc == 1 || opc == 2) {
                        optionMenu(usr,opc,mysql);
                }
        } while(opc != 0);
}

/*************************************
* Redirige al usuario a el menu de  *
* agregado o de consulta de la base *
* de datos segun su eleccion.       *
* @method optionMenu                *
* @param  usr        User struct    *
* @param  x          Opcion         *
*************************************/

void optionMenu(User usr, int x, MYSQL *mysql) {
        char str[20];
        int opc = 0;
        do {
                if (x == 1) {
                        optionInsert(usr.type_of);
                } else if (x == 2) {
                        optionQuery(usr.type_of);
                }
                fgets(str,20,stdin);
                opc = strInt(str);
                if (x == 1) {
                        insertRoute(usr,opc,mysql);
                } else if (x == 2) {
                        queryRoute(usr,opc,mysql);
                }
        } while(opc != 0);
}

/***************************************
* Dirige al usuario a la funcion que  *
* el mismo haya escogido.             *
* @method insertRoute                 *
* @param  type_of     nivel de acceso *
* @param  x           Opcion          *
***************************************/

void insertRoute(User usr, int x, MYSQL *mysql) {
        if (strcmp(usr.type_of,"Superuser") == 0) {
                switch (x) {
                case 1:
                        addInstitute(mysql);
                        break;
                case 2:
                        addUser(mysql,usr);
                        break;
                case 3:
                        addState(mysql);
                        break;
                case 4:
                        addSector(mysql);
                        break;
                case 5:
                        addType(mysql);
                        break;
                }
        } else if (strcmp(usr.type_of,"Administrador") == 0) {
                switch (x) {
                case 1:
                        addUser(mysql,usr);
                        break;
                case 2:
                        addParking(mysql,usr);
                        break;
                case 3:
                        addSchedule(mysql,usr);
                        break;
                }
        } else if (strcmp(usr.type_of,"Cliente") == 0) {
                switch (x) {
                case 1:
                        addVehicle(mysql,usr);
                        break;
                case 2:
                        addPark(mysql,usr);
                        break;
                }
        }
}

/***************************************
* Dirige al usuario a la funcion que  *
* el mismo haya escogido.             *
* @method insertRoute                 *
* @param  type_of     nivel de acceso *
* @param  x           Opcion          *
***************************************/

void queryRoute(User usr, int x, MYSQL *mysql) {
        char str[20];
        int opc = 0;
        if ((strcmp(usr.type_of,"Superuser") == 0) || (strcmp(usr.type_of,"Administrador") == 0)) {
                switch (x) {
                case 1:
                        //visitedParking();
                        break;
                case 2:
                        //usersParking();
                        break;
                case 3:
                        // parkingSector();
                        break;
                case 4:
                        // usersRegis();
                        break;
                case 5:
                        // scheduleParking();
                        break;
                case 6:
                        //sectorUsers();
                        break;
                case 7:
                        //usersParking();
                        break;
                case 8:
                        //usersSector();
                        break;
                case 9:
                        //space();
                        break;
                case 0:
                        //previous();
                        break;
                }
        } else if (strcmp(usr.type_of,"Cliente") == 0) {
                switch (x) {
                case 1:
                        //visitedParking();
                        break;
                case 2:
                        //usersParking();
                        break;
                case 3:
                        // parkingSector();
                        break;
                case 4:
                        // usersRegis();
                        break;
                case 5:
                        // scheduleParking();
                        break;
                case 6:
                        //sectorUsers();
                        break;
                case 7:
                        //usersParking();
                        break;
                case 8:
                        //usersSector();
                        break;
                case 9:
                        //space();
                        break;
                case 10:
                        // typePlaces();
                        break;
                case 11:
                        // total();
                        break;
                case 0:
                        // previous();
                        break;
                }
        }
}

/*******************************************
* Muestra el menu de agregado a la        *
* base de datos segun el tipo de usuario. *
* @method optionInsert                    *
* @param  type_of      Tipo de usuario    *
*******************************************/

void optionInsert(char *type_of) {
        system("clear");
        printf("\n\n\tElige una opcion:\n\n");
        if (strcmp(type_of,"Superuser") == 0) {
                printf("\t\t1) Agregar Institucion\n");
                printf("\t\t2) Agregar Usuarios\n");
                printf("\t\t3) Agregar estado\n");
                printf("\t\t4) Agregar zona\n");
                printf("\t\t5) Agregar tipo de estacionamiento\n");
        } else if (strcmp(type_of,"Administrador") == 0) {
                printf("\t\t1) Agregar Usuarios\n");
                printf("\t\t2) Agregar estacionamiento\n");
                printf("\t\t3) Agregar horarios\n");
        } else if (strcmp(type_of,"Cliente") == 0) {
                printf("\t\t1) Agregar vehiculos\n");
                printf("\t\t2) Registrar estacionado\n");
        }
        printf("\t\t0) Menu anterior\n");
}

/*******************************************
* Muestra el menu de consulta a la        *
* base de datos segun el tipo de usuario. *
* @method optionInsert                    *
* @param  type_of      Tipo de usuario    *
*******************************************/

void optionQuery(char *type_of) {
        system("clear");
        printf("\n\n\tElige una opcion:\n\n");
        if ((strcmp(type_of,"Superuser") == 0) || (strcmp(type_of,"Administrador") == 0)) {
                printf("\t\t 1) Estacionamientos mas visitados\n");
                printf("\t\t 2) Personas que mas estacionamientos visitan\n");
                printf("\t\t 3) Estacionamientos disponibles en una zona determinada\n");
                printf("\t\t 4) Usuarios registrados en el sistema\n");
                printf("\t\t 5) Horarios de un estacionamiento en particular\n");
                printf("\t\t 6) Zonas mas concurridas\n");
                printf("\t\t 7) Horarios mas concurridos por estacionamiento\n");
                printf("\t\t 8) Horarios mas concurridos por zona\n");
                printf("\t\t 9) Lugares disponibles en un estacionamiento particular\n");
        } else if (strcmp(type_of,"Cliente") == 0) {
                printf("\t\t 1) Estacionamientos mas visitados\n");
                printf("\t\t 2) Personas que mas estacionamientos visitan\n");
                printf("\t\t 3) Estacionamientos disponibles en una zona determinada\n");
                printf("\t\t 4) Usuarios registrados en el sistema\n");
                printf("\t\t 5) Horarios de un estacionamiento en particular\n");
                printf("\t\t 6) Zonas mas concurridas\n");
                printf("\t\t 7) Horarios mas concurridos por estacionamiento\n");
                printf("\t\t 8) Horarios mas concurridos por zona\n");
                printf("\t\t 9) Lugares disponibles en un estacionamiento particular\n");
                printf("\t\t10) Tipos de lugares usados\n");
                printf("\t\t11) Monto total\n");
        }
        printf("\t\t 0) Menu anterior\n");
}

#include "headers.h"

/*******************************
* Primer menu que se muestra  *
* @method setMenu             *
* @param  usr     User struct *
*******************************/

void setMenu(User usr) {
        char str[20];
        int opc = -1;
        do {
                system("clear");
                printf("\n\n\tElige una opcion:\n\n");
                printf("\t\t1) Agregar a la base de datos.\n");
                printf("\t\t2) Consultas a la base de datos.\n");
                printf("\t\t0) Salir del sistema\n");
                fgets(str,20,stdin);
                opc = strInt(str);
                if (opc == 1 || opc == 2) {
                        optionMenu(usr,opc);
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

void optionMenu(User usr, int x) {
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
                printf("%d\n", opc);
        } while(opc != 0);
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
        printf("\t\t 1) Estacionamientos mas visitados\n");
        printf("\t\t 2) Personas que mas estacionamientos visitan\n");
        printf("\t\t 3) Estacionamientos disponibles en una zona determinada\n");
        printf("\t\t 4) Usuarios registrados en el sistema\n");
        printf("\t\t 5) Horarios de un estacionamiento en particular\n");
        printf("\t\t 6) Zonas mas concurridas\n");
        printf("\t\t 7) Horarios mas concurridos\n");
        printf("\t\t 8) Lugares disponibles en un estacionamiento particular\n");
        printf("\t\t 9) Tipos de lugares usados\n");
        printf("\t\t10) Monto total\n");
        printf("\t\t0) Menu anterior\n");
}

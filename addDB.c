#include "headers.h"

/********************************************
* Solicita los datos necesarios al usuario *
* @method addInstitute                     *
* @param  mysql        pointer a db        *
********************************************/

void addInstitute(MYSQL *mysql) {
        char sFor[1][20];
        char nFor[4][20];
        int x = 0;
        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tNombre de la organizacion\n");
        fgets(sFor[0],20,stdin);
        printf("\tRFC:\n");
        fgets(nFor[0],20,stdin);
        printf("\tDireccion:\n");
        fgets(nFor[1],20,stdin);
        printf("\tTelefono:\n");
        fgets(nFor[2],20,stdin);
        printf("\tTipo de empresa:\n\t\t1) Gubernamental\n\t\t2) Privada\n");
        fgets(nFor[3],20,stdin);
        x = strInt(nFor[3]);
        if (x == 1) {
                strcpy(nFor[3],"00\n\0");
        } else if (x == 2) {
                strcpy(nFor[3],"01\n\0");
        } else {
                strcpy(nFor[3],"\n\0");
        }
        if (valForced(sFor,1) == true && valNotForced(nFor,4) == true) {
                saveInstitute(mysql,sFor,nFor);
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\n\n\tPresione Enter para continuar...");
        getchar();
}

/*************************************************
* Guarda en buffer el comando para ejecutar en  *
* mysql                                         *
* @method saveInstitute                         *
* @param  mysql         pointer a db            *
* @param  sFor          datos obligatorios      *
* @param  nFor          datos no obligatorios   *
*************************************************/

void saveInstitute(MYSQL *mysql, char sFor[][20], char nFor[][20]) {
        char buffer[1024];
        sprintf(buffer,"INSERT INTO p1_institution(name,typeof,address,phone,rfc) VALUES(%s,%s,%s,%s,%s)",sFor[0],nFor[3],nFor[2],nFor[1],nFor[0]);
        printf("%s\n", buffer);
        dbInsert(buffer,mysql);
        printf("\n\n\tse agrego %s correctamente!!!\n",sFor[0]);
}

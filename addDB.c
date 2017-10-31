#include "headers.h"

/********************************************
* Solicita los datos necesarios al usuario *
* @method addInstitute                     *
* @param  mysql        pointer a db        *
********************************************/

void addInstitute(MYSQL *mysql) {
        char sFor[1][100];
        char nFor[4][100];
        int x = 0;
        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tNombre de la organizacion\n");
        fgets(sFor[0],100,stdin);
        printf("\tRFC:\n");
        fgets(nFor[0],100,stdin);
        printf("\tDireccion:\n");
        fgets(nFor[1],100,stdin);
        printf("\tTelefono:\n");
        fgets(nFor[2],100,stdin);
        printf("\tTipo de empresa:\n\t\t1) Gubernamental\n\t\t2) Privada\n");
        fgets(nFor[3],100,stdin);
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

void saveInstitute(MYSQL *mysql, char sFor[][100], char nFor[][100]) {
        char buffer[1024];
        sprintf(buffer,"INSERT INTO p1_institution(name,typeof,address,phone,rfc) VALUES(%s,%s,%s,%s,%s)",sFor[0],nFor[3],nFor[2],nFor[1],nFor[0]);
        printf("%s\n", buffer);
        if (dbInsert(buffer,mysql) == true) {
                printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
        }
}

/****************************************
* Solicita la informacion necesaria al *
* usuario                              *
* @method addUser                      *
* @param  mysql   pointer a db         *
* @param  usr     user's struct        *
****************************************/

void addUser(MYSQL *mysql, User usr) {
        char sFor[6][100];
        char nFor[4][100];
        char str[20];
        int type = 0, inst = 0;
        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tNombre:\n");
        fgets(sFor[0],100,stdin);
        printf("\tApellido Paterno:\n");
        fgets(sFor[1],100,stdin);
        printf("\tApellido Materno:\n");
        fgets(nFor[0],100,stdin);
        printf("\tEmail:\n");
        fgets(sFor[2],100,stdin);
        printf("\tUsername (MAX 10 caracteres);\n");
        fgets(sFor[3],100,stdin);
        printf("\tPassword (MAX 10 caracteres);\n");
        fgets(sFor[4],100,stdin);
        printf("\tRFC:\n");
        fgets(nFor[1],100,stdin);
        printf("\tDireccion:\n");
        fgets(nFor[2],100,stdin);
        printf("\tTelefono\n");
        fgets(nFor[3],100,stdin);
        type = selType(usr.type_of);
        if (type == 0) {
                strcpy(sFor[5],"00\n\0");
        } else if (type == 1) {
                strcpy(sFor[5],"01\n\0");
        } else if (type == 2) {
                strcpy(sFor[5],"10\n\0");
        } else {
                strcpy(sFor[5],"\n\0");
        }
        inst = selInstitute(mysql,usr);
        if (valForced(sFor,6) == true && valNotForced(nFor,4) == true) {
                sprintf(str,"%d",inst);
                if (inst == -1) {
                        strcpy(str,"NULL");
                }
                saveUser(sFor,nFor,str,mysql);
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\n\n\tPresione Enter para continuar...");
        getchar();
}

/********************************************
* Ejecuta el comando SQL con los valores   *
* recibidos                                *
* @method saveUser                         *
* @param  sFor     Valores obligatorios    *
* @param  nFor     Valores no obligatorios *
* @param  inst     id_institution          *
* @param  mysql    pointer a db            *
********************************************/

void saveUser(char sFor[][100], char nFor[][100], char *inst, MYSQL *mysql) {
        char buffer[1024];
        sprintf(buffer,"INSERT INTO p1_users(name,l_name,l_name2,email,username,password,phone,address,rfc,typeof,id_institution)VALUES (%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)",sFor[0],sFor[1],nFor[0],sFor[2],sFor[3],sFor[4],nFor[1],nFor[2],nFor[3],sFor[5],inst);
        printf("%s\n", buffer);
        if (dbInsert(buffer,mysql) == true) {
                printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
        }
}

/**************************************
* Muestra las opciones de niveles de *
* usuario que se pueden escoger.     *
* @method selType                    *
* @param  usertype Tipo de usuario   *
* @return          Eleccion          *
**************************************/

int selType(char *usertype) {
        char str[20];
        int opc = 0;
        if (strcmp(usertype,"Superuser") == 0) {
                printf("\tSelecciona el tipo de usuario:\n\t\t1) Superuser\n\t\t2) Administrador\n\t\t3) Cliente");
                fgets(str,20,stdin);
                opc = strInt(str);
                if (opc < 1 || opc > 3) {
                        opc = -1;
                }
        } else if (strcmp(usertype,"Administrador") == 0) {
                opc = 2;
        }
        return opc;
}

/********************************************
* Solicita el nombre del estado al usuario *
* y posteriormente lo agrega a la base.    *
* @method addState                         *
* @param  mysql    pointer a DB            *
********************************************/

void addState(MYSQL *mysql) {
        char sFor[1][100];
        char buffer[1024];

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tNombre del estado:\n");
        fgets(sFor[0],100,stdin);

        if (valForced(sFor,1) == true) {
                sprintf(buffer,"INSERT INTO p1_state(name) VALUES(%s)",sFor[0]);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
                        printf("\tPresione Enter para continuar...");
                        getchar();
                }
        }
}

/********************************************
* Solicita el nombre del sector al usuario *
* y posteriormente lo agrega a la base.    *
* @method addSector                        *
* @param  mysql    pointer a DB            *
********************************************/

void addSector(MYSQL *mysql) {
        char sFor[1][100];
        char buffer[1024];
        int x = selState(mysql);

        system("clear");
        if (x != -1) {
                printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
                printf("\tNombre de la zona:\n");
                fgets(sFor[0],100,stdin);

                if (valForced(sFor,1) == true) {
                        sprintf(buffer,"INSERT INTO p1_sector(name,id_state) VALUES(%s,%d)",sFor[0],x);
                        printf("%s\n", buffer);
                        if (dbInsert(buffer,mysql) == true) {
                                printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
                        }
                }
        } else {
                printf("\n\tSeleccion de estado no valida!!\n");
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

/******************************************
* Solicita al usuario los datos y agrega *
* una nueva categoria de estacionamiento *
* @method addType                        *
* @param  mysql   pointer a DB           *
******************************************/

void addType(MYSQL *mysql) {
        char sFor[1][100];
        char buffer[1024];

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tNombre del tipo:\n");
        fgets(sFor[0],100,stdin);

        if (valForced(sFor,1) == true) {
                sprintf(buffer,"INSERT INTO p1_type(typeof) VALUES(%s)",sFor[0]);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
                }
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

/******************************************
* Solicita al usuario los datos y agrega *
* a la base de datos.                    *
* @param mysql   pointer a DB            *
* @parma usr     user's struct           *
******************************************/

void addParking(MYSQL *mysql, User usr) {
        char sFor[1][100];
        char nFor[2][100];
        char str[20], buffer[1024];
        int sz = 0, ins = 0, ty = 0, sec = 0;
        float rt = 0;

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tDireccion:\n");
        fgets(sFor[0],100,stdin);
        printf("\tLongitud:\n");
        fgets(nFor[0],100,stdin);
        printf("\tLatitud:\n");
        fgets(nFor[1],100,stdin);
        printf("\tCapacidad:\n");
        fgets(str,20,stdin);
        sz = strInt(str);
        printf("\tTarifa:\n");
        fgets(str,20,stdin);
        rt = strFloat(str);
        ins = usr.id_institution;
        ty = selParkingType(mysql);
        sec = selSector(mysql);
        if (valForced(sFor,1) == true && valNotForced(nFor,2) == true && sz > 0 && ty != -1 && sec != -1) {
                sprintf(buffer,"INSERT INTO p1_parking(address,longitude,latitude,sizeof,id_sector,id_institution,id_type,rate) VALUES(%s,%s,%s,%d,%d,%d,%d,%f)",sFor[0],nFor[0],nFor[1],sz,sec,ins,ty,rt);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
                }
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

/******************************************
* Solicita al usuario los datos y agrega *
* a la base de datos.                    *
* @param mysql   pointer a DB            *
* @parma usr     user's struct           *
******************************************/

void addSchedule(MYSQL *mysql, User usr) {
        char sFor[2][100];
        char str[20], buffer[1024];
        int day = 0, park = 0;

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tIndica el dia de la semana:\n\t\t1) Mon\n\t\t2) Tue\n\t\t3) Wed\n\t\t4) Thu\n\t\t5) Fri\n\t\t6) Sat\n\t\t7) Sun\n");
        fgets(str,20,stdin);
        day = strInt(str);
        switch (day) {
        case 1:
                sprintf(str,"'mon'");
                break;
        case 2:
                sprintf(str,"'tue'");
                break;
        case 3:
                sprintf(str,"'wed'");
                break;
        case 4:
                sprintf(str,"'thu'");
                break;
        case 5:
                sprintf(str,"'fri'");
                break;
        case 6:
                sprintf(str,"'sat'");
                break;
        case 7:
                sprintf(str,"'sun'");
                break;
        default:
                sprintf(str,"NULL");
                break;
        }
        printf("\tHora de inicio (HH:MM):\n");
        fgets(sFor[0],100,stdin);
        printf("\tHora de fin (HH:MM):\n");
        fgets(sFor[1],100,stdin);
        park = selParkingInstitute(mysql,usr.id_institution);
        if (valForced(sFor,2) == true && park != -1 && day != -1) {
                sprintf(buffer,"INSERT INTO p1_schedule(DAY,startof,endof,id_parking) VALUES(%s,%s,%s,%d)",str,sFor[0],sFor[1],park);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego horario correctamente!!!\n");
                }
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

void addVehicle(MYSQL *mysql, User usr) {
        char sFor[4][100];
        char str[20], buffer[1024];

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        printf("\tMatricula:\n");
        fgets(sFor[0],100,stdin);
        printf("\tModelo:\n");
        fgets(sFor[1],100,stdin);
        printf("\tMarca:\n");
        fgets(sFor[2],100,stdin);
        printf("\tColor:\n");
        fgets(sFor[3],100,stdin);

        if (valForced(sFor,4) == true) {
                sprintf(buffer,"INSERT INTO p1_vehicle(record,model,brand,color,id_user) VALUES(%s,%s,%s,%s,%d)",sFor[0],sFor[1],sFor[2],sFor[3],usr.id_user);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego %s correctamente!!!\n",sFor[0]);
                }
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

void addPark(MYSQL *mysql, User usr) {
        char sFor[1][100];
        char str[20], buffer[1024];
        int park = 0;

        system("clear");
        printf("\n\n\n\tIngresa los datos a continuacion solicitados (No hay distincion entre\n\tmayusculas y minusculas):\n\n");
        selVehicle(mysql,usr.id_user,sFor[0]);
        park = selParking(mysql);

        if (valForced(sFor,1) == true && park != -1) {
                sprintf(buffer,"INSERT INTO p1_park(entryof,exitof,record,id_parking) VALUES(CURDATE(),NULL,%s,%d)",sFor[0],park);
                printf("%s\n", buffer);
                if (dbInsert(buffer,mysql) == true) {
                        printf("\n\n\tSe agrego correctamente!!!\n");
                }
        } else {
                printf("\n\n\tERROR en datos ingresados\n\tIntente de nuevo!!!\n\n");
        }
        printf("\tPresione Enter para continuar...");
        getchar();
}

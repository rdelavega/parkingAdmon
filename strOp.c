#include "headers.h"

/***************************************************
* Recibe un String y convierte a mayusculas cada  *
* cracater del mismo.                             *
* @method strUpper                                *
* @param  str      pointer a String               *
***************************************************/

void strUpper(char *str) {
        int i = 0;
        while (str[i]) {
                str[i] = toupper(str[i]);
                i++;
        }
}

/*************************************************
* Verifica que no exista inyeccion de codigo en *
* el texto ingresado por el usuario.            *
* @method strCheck                              *
* @param  str      String a revisar             *
* @return          false si no es aceptado el   *
*                  String                       *
*************************************************/


bool strCheck(char * str) {
        char avoid[34][10] = {"SELECT","INSERT","INTO","VALUES","FROM","AND",
                              "OR","CREATE","TABLE","ALTER","DROP","UPDATE",
                              "DELETE","WHERE","COUNT","AVG","UPPER","LOWER",
                              "TRIM","LIKE","NULL","NOT","BETWEEN","EXISTS",
                              "JOIN","UNION","ORDER","GROUP","HAVING","=","<",
                              ">","MATCH"};
        bool accept = true;
        strUpper(str);

        for (int i = 0; i < 33; i++) {
                if (strstr(str,avoid[i]) != NULL) {
                        accept = false;
                }
        }

        return accept;
}

/***********************************
* Convierte un string a enteros o *
* devuelve -1                     *
* @method strInt                  *
* @param  str    pointer a String *
* @return        Integer          *
***********************************/

int strInt (char *str) {
        char *ptr = "";
        int x = strtol(str, &ptr, 10);
        if (strcmp(ptr,"\n\0") != 0) {
                x = -1;
        }
        return x;
}

#include "headers.h"

int main(int argc, char *argv[]) {

        system("clear");

        if (argc == 5 && strcmp(argv[1],"-u") == 0 && strcmp(argv[3],"-p") == 0) {
                if (strCheck(argv[2]) && strCheck(argv[4])) {
                        MYSQL mysql;
                        dbInit(&mysql);
                        logIn(argv[2],argv[4],&mysql);
                        dbClose(&mysql);
                } else {
                        printf("\n\nLos datos ingresados no son admitidos!!!\n\n");
                }
        } else {
                __HELP();
        }

        printf("\n\n\nBye!!!\n\n\n");

        return 0;
}

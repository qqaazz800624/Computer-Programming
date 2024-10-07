#include <stdio.h>
#include <stdlib.h>


int main(){

    char op;

    while (1){
        puts("i insert data");
        puts("l list data");
        puts("s save data");
        puts("o open data");
        puts("q quit");

        scanf(" %c", &op);

        switch (op){
            case 'i':
                puts("i insert data...");
                break;
            case 'l':
                break;
            case 's':
                break;
            case 'o':
                break;
            case 'q':
                return 0;
                break;
        }
        system("pause");
        system("clear");
    }

    return 0;
};
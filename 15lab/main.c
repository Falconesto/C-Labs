#include <stdio.h>
#include "library.h"


int main(int argc, char* argv[]){
    //FILE* arcfile;
    char i;
    char* arcname;
    printf("\n");
    for (i = 0; i < argc; i++){
        if(!strcmp("--file", argv[i])){
            arcname = argv[i + 1];
        }
        if(!strcmp("--create", argv[i])){
            Create(arcname, argc, argv);
            break;
        }
        if(!strcmp("--extract", argv[i])){
            Extract(arcname);
        }
        if(!strcmp("--list", argv[i])){
            List(arcname);
        }
    }
    return 0;
}
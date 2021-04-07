//
// Created by Александр on 21.12.2019.
//

#include "library.h"

void Extract(char* arcname){
    FILE* arch = fopen(arcname, "rb+wb");
    unsigned long long int  now_position = 0;
    unsigned long long int  write_txt_position = 0;
    int c;
    while ((c = getc(arch)) != EOF) {
        write_txt_position++;
        if (c == '\n')
            break;
    }
    fseek(arch, 0, SEEK_SET);
    char filename[128] = {0};
    unsigned long long int  filesize;
    FILE *file;
    while (fscanf(arch, "< %s : %llu >", filename, &filesize) != 0) {
        file = fopen(filename, "wb");
        if (file == NULL) break;
        now_position = ftell(arch);
        fseek(arch, write_txt_position, SEEK_SET);
        write_txt_position += filesize;
        while (filesize-- > 0)
            putc((c = getc(arch)), file);
        fseek(arch, now_position, SEEK_SET);
        fclose(file);

    }
    printf("\n + Uspeshno + \n");
}

void List(char* arcname){
    FILE* arcfile = fopen(arcname, "rb");
    char filename[128] = {0};
    unsigned long long int  filesize;
    printf("File list:\n");
    while (fscanf(arcfile, "< %s : %llu >", filename, &filesize) != 0) {
        printf("\t%s\n", filename);
    }
    fclose(arcfile);
}

void Create(char* arc_name, int filecount, char* files[]){
    int i;
    int temp;
    FILE* arcfile = fopen(arc_name, "wb");
    FILE* file;
    unsigned long long int nameandsize[50000];
    for (i = 5; i < filecount; i++){
        file = fopen(files[i], "rb");
        if (file == NULL)
            continue;
        fseek(file, 0, SEEK_END);
        nameandsize[i - 5] = ftell(file);
        fseek(file, 0, SEEK_SET);
        fclose(file);
    }
    for (i = 0; i < filecount - 5; i++){
        fprintf(arcfile, "< %s : %llu >", files[i + 5], nameandsize[i]);
    }
    fprintf(arcfile, "\n");
    for (i = 5; i < filecount; i++){
        file = fopen(files[i], "rb");
        if (file == NULL){
            printf("404\n");
            fclose(arcfile);
            remove(arc_name);
            exit(1);
        }
        else{
            printf("Uspeshno\n");
        }
        while ((temp = getc(file)) != EOF)
            putc(temp, arcfile);
        fclose(file);
    }
    printf("\n + Uspeshno + \n");
}
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Directory;
int value = 10;
struct File{
    int id, size;
    char data[256], name[36];
    struct Directory * parent;
};

struct Directory{
    int nf;
    int nd;
    char path[256];
    struct File files[10];
    struct Directory* directories ;
};

void add_to_file(struct File* file, const char* str){
    file->id = strlen(str), file->size = sizeof (str);
    strncpy(file->name, "Foo", 3);
    strcpy(file->data, str);
}

void append_to_file(struct File *file, const char * content){
    strcat(file->data, content);
}

void pwd_file(struct File * file) {
    struct Directory *directory = file->parent;
    printf("%s\n", *directory->path);
    // Example: the path for bash file is /bin/bash

}

int main(){
    return 0;

}

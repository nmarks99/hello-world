#include "print_dir_contents.h"

void print_dir_contents(char* dir_path){

    struct dirent *de;

    DIR *folder = opendir(dir_path);

    if (folder == NULL){
        printf("Could not open directory %s", dir_path);
    }
    else{
        while(1){
            de = readdir(folder);
            if (de != NULL){
                printf("%s\r\n",de->d_name);
            }
            else{
                break;
            }
        }
    }
    closedir(folder);
}


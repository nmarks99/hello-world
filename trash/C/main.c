#define __USE_XOPEN
#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

void get_file_modification_time(char *filePath, char *date_buff) {
    struct stat attrib;
    stat(filePath, &attrib);
    strftime(date_buff, 10, "%d-%m-%y", gmtime(&(attrib.st_ctime)));
    /* printf("The file %s was last modified at %s\n", filePath, date); */
    /* date[0] = 0; */
}

int main(int argc, char *argv[]) {
    char date[20]; 
    get_file_modification_time("../../rmspace.py",date); 
    struct tm tm;
    time_t epoch;
    if ( strptime(date, "%Y-%m-%d %H:%M:%S", &tm) != NULL) {
        epoch = mktime(&tm);
    }
    else {
        printf("hmm");
        //badness
    }

    printf("unix time = %ld\n",epoch);

    /* get_file_modification_time("../../rmspace.py"); */


    return 0;
}



    

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void csv_split_line(char *str, char *x, char *y, char *z);
void slash_split_arr(char *arr);

int main(void) {

  char str[] = "1,2,3";
  char out[100] = "";
  char x[10];
  char y[10];
  char z[10];

  csv_split_line(str,x,y,z);
  printf("%s %s %s\n",x,y,z);

  return 0;
}

void csv_split_line(char *str,char *x,char *y, char *z){
    unsigned const int STRING_LENGTH = strlen(str);
    unsigned int i = 0;
    unsigned int j;
    char coords_temp[STRING_LENGTH];

    for (j = 0; j < STRING_LENGTH; j++){
        if (str[j] != ','){
            strncat(coords_temp,&str[j],1);
        }
        else{
            if (i == 0){ 
              strcpy(x,coords_temp);
            }
            else if (i == 1){
              strcpy(y,coords_temp);
            }
            else if (i == 2){
              strcpy(z,coords_temp);
            }
            memset(coords_temp,0,sizeof(coords_temp));
            i++;
        }
    }
    strcpy(z,coords_temp);
    memset(coords_temp,0,sizeof(coords_temp));
}

void slash_split_arr(char *arr){
  unsigned const int STRING_LENGTH = strlen(arr);
    unsigned int i = 0;
    unsigned int j;
    char line[100];
    char x[10];
    char y[10];
    char z[10];
    char coords_temp[STRING_LENGTH];

    for (j = 0; j < STRING_LENGTH; j++){
        if (arr[j] != '/'){
            strncat(coords_temp,&arr[j],1);
        }
        else{
          strcpy(line,coords_temp);
          memset(coords_temp,0,sizeof(coords_temp));
          
          // Split by commas to get x, y, and z
          csv_split_line(line,x,y,z);
          printf("x=%s, y=%s, z=%s\n",x,y,z);

          // Clear x, y, and z 
          memset(x,0,sizeof(x));
          memset(y,0,sizeof(y));
          memset(z,0,sizeof(z));
        }
    }
    strcpy(line,coords_temp);
    memset(coords_temp,0,sizeof(coords_temp));
    csv_split_line(line,x,y,z);
    printf("x=%s, y=%s, z=%s\n",x,y,z);

    // Clear x, y, and z
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
}
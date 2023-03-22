#include<stdio.h>

int main(void){
  int i;
  for (i = 33; i <= 127; i++){
    printf("%d:%c\t",i,i);
    if ((i % 8) == 0){  // "%" here gives remainder after division
      printf("\n"); // Start a row after every 8 values
    }
  }
  return(0);
}
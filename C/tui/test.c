#include <time.h>
#include <stdio.h>

int main() {
    
    printf("CLOCKS_PER_SEC = %ld\n",CLOCKS_PER_SEC);
    
    clock_t start_time = clock();
    while(1){
        
        clock_t current_time = clock();

        if((current_time - start_time)/CLOCKS_PER_SEC > 1) {
            printf("hello");
            break;
        }
    }
    return 0;

}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    
    char s1[] = "hello";
    char s2[] = "hello";
    bool match1;
    bool match2;

    // set match = true if the strings are the same
    if (strcmp(s1, s2) == 0) {
        match1 = true;
    }
    else {
        match2 = false;
    }
    printf("Match = %d\n", match1);

    // equivalently we could do
    match2 = (strcmp(s1, s2) == 0) ? true : false;
    printf("Match = %d\n", match2);

    return 0;
}

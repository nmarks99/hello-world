#include <stdio.h>
#include "foo.h"

int main(void) {
    printf("Testing a shared library...\n");
    foo();
    return 0;
}

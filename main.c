#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* test = malloc(8);
    int* test2 = test;

    free(test2);
}

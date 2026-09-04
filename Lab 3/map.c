#include <stdio.h>
#include <stdlib.h>

void recur(int depth) {
    int local;
    printf("recur call %d: stack@ %p\n", depth, &local);
    if (depth > 0) recur(depth - 1);
}

int main() {
    static int static_var;
    int local;
    int *heap1 = malloc(16);
    int *heap2 = malloc(16);

    printf("_main @ %p\n", main);
    printf("recur @ %p\n", recur);
    printf("_main stack: %p\n", &local);
    printf("static data: %p\n", &static_var);
    printf("Heap: malloc 1: %p\n", heap1);
    printf("Heap: malloc 2: %p\n", heap2);

    recur(3);

    free(heap1);
    free(heap2);
    return 0;
}

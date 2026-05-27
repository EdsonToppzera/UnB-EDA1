#include <stdio.h>
#include <stdlib.h>

//Exercício 4 — Swap manual (sem função) 
void ativ4() {
    int x = 100, y = 200;
    int *px = &x, *py = &y;

    *px = *px + *py;
    *py = *px - *py;
    *px = *px - *py;

    printf("x = %d, y = %d\n", x, y);
}
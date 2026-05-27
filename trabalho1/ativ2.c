#include <stdio.h>
#include <stdlib.h>

//Exercício 2 — Ponteiros cruzados 
void ativ2() {
    int A = 10, B = 20;
    int *p1 = &A, *p2 = &B;
    printf("antigo: *p1 = %d, *p2 = %d\n", *p1, *p2);

    int *temp = p1;
    p1 = p2;
    p2 = temp;
    printf("novo: *p1 = %d, *p2 = %d\n", *p1, *p2);
}
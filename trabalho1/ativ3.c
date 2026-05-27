#include <stdio.h>
#include <stdlib.h>

//Exercício 3 — Incremento indireto
void ativ3() {
    int valor = 10;
    int *p = &valor;
    *p = *p + 5;
    *p = *p * 2;

    printf("Resultado: %d\n", *p); 
}
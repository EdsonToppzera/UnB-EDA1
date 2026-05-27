#include <stdio.h>
#include <stdlib.h>

//Exercício 5 — Vetor com ponteiros 
void ativ5() {
    int v[5] = {10, 20, 30, 40, 50};
    int *p = v;
    int soma = 0;

    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, *(p + i));
        soma += *(p + i);
    }
    printf("total: %d\n", soma);
}
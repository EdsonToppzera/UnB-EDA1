#include <stdio.h>
#include <stdlib.h>

//Exercício 7 — Maior elemento do vetor 
int maior(int *v, int tamanho) {
    int max = *v;
    
    for (int i = 1; i < tamanho; i++) {
        if (*(v + i) > max) {
            max = *(v + i);
        }
    }
    return max;
}
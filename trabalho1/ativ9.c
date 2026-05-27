#include <stdio.h>
#include <stdlib.h>

//Exercício 9 — Inversão de vetor (in-place) 
void inverte(int *v, int tamanho) {
    int *inicio = v;
    int *fim = v + (tamanho - 1);

    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}
#include <stdio.h>
#include <stdlib.h>

//QUESTÃO 1 (1 Ponto): Vetores, Matrizes e Ponteiros 
//a) Declare um vetor de inteiros de tamanho 10 e inicialize todos os elementos com 0. Depois escreva um laço for que imprima todos os elementos.  
int main() {
    int v[10] = {0};

    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//b) Escreva o trecho de código que declara uma matriz 3x3 de inteiros e preenche a diagonal principal com o valor 1 (os demais elementos devem ser 0). 
int m[3][3] = {0};

for (int i = 0; i < 3; i++) {
    m[i][i] = 1; 
}
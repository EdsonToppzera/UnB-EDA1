#include <stdio.h>
#include <stdlib.h>

//Exercício 6 — Modificação por função
void dobra(int *x) {
    *x = (*x) * 2;
}
// Se passar sem o ponteiro, ela vai modificar so a uma copia que o programa cria, não a original
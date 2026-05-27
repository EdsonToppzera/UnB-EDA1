#include <stdio.h>
#include <stdlib.h>

//Exercício 10 — Intercalação de vetores 
void intercala(int *v1, int *v2, int *v3, int n) {
    int *p1 = v1, *p2 = v2, *p3 = v3;

    for (int i = 0; i < n; i++) {
        *p3 = *p1;
        p3++; p1++;
        *p3 = *p2;
        p3++; p2++;
    }
}
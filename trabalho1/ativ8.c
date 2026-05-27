#include <stdio.h>
#include <stdlib.h>

//Exercício 8 — Contagem de caracteres
int conta(char *str, char c) {
    int ocorrencias = 0;
    while (*str != '\0') {
        if (*str == c) {
            ocorrencias++;
        }
        str++;
    }
    return ocorrencias;
}
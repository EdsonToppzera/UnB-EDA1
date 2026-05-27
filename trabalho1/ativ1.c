#include <stdio.h>
#include <stdlib.h>

//Exercício 1 — Inspeção de memória 
void ativ1() {
    int inteiro = 42;
    float flutuante = 3.14f;
    int *p_int = &inteiro;
    float *p_float = &flutuante;

    printf("int, valor: %d, Endereco: %p\n", inteiro, (void*)&inteiro);
    printf("ponteiro int - endereco que guarda: %p, valor: %d\n", (void*)p_int, *p_int);
    printf("float, valor: %.2f, endereco: %p\n", flutuante, (void*)&flutuante);
    printf("ponteiro float, endereco que guarda: %p, valor: %.2f\n", (void*)p_float, *p_float);
}
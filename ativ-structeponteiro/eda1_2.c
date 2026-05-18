#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa joao;
    
    strcpy(joao.nome, "Joao");
    joao.idade = 25;
    joao.altura = 1.80;

    printf("nome1: %s\n", joao.nome);
    printf("idade1: %d\n", joao.idade);
    printf("altura1: %f\n", joao.altura);

    joao.idade = 26;
    joao.altura = 1.81;

    printf("idade1: %d\n", joao.idade);
    printf("altura1: %f\n", joao.altura);

    return 0;
}
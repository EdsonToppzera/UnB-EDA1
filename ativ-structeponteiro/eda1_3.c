#include <stdio.h>
#include <string.h>

struct Carro {
    char modelo[50];
    int ano;
    char cor[30];
};

void ImprimirCarro(struct Carro carro) {
    printf("Modelo: %s\n", carro.modelo);
    printf("Ano: %d\n", carro.ano);
    printf("Cor: %s\n", carro.cor);
}

int main() {
    struct Carro fusquinha;
    
    strcpy(fusquinha.modelo, "Fusca");
    fusquinha.ano = 1990;
    strcpy(fusquinha.cor, "Azul bebe");
    ImprimirCarro(fusquinha);

    return 0;
}
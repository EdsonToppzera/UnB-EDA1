#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Produto {
    char nome[50];
    int quantidade;
};

struct Produto produtos[10] = {
    {"arroz", 0}, {"feijao", 0}, {"macarrao", 0}, {"oleo", 0}, {"acucar", 10},
    {"sal", 0}, {"cafe", 0}, {"leite", 0}, {"pao", 0}, {"manteiga", 0}
};

void ImprimirProdutos() {
    printf("\n--- Produtos disponiveis ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - Quantidade: %d\n", i + 1, produtos[i].nome, produtos[i].quantidade);
    }
}

int main() {
    char opcao;
    char nomeProduto[50];
    int qtdAlterar;

    for (int i = 0; i < 10; i++) {
        produtos[i].quantidade = (rand() % 10) + 1;
    }
    
    while (true) {
        
        ImprimirProdutos();

        printf("\nDeseja comprar ou vender? (c/v) ou 's' para sair: ");
        scanf(" %c", &opcao);

        if (opcao == 's') break;

        printf("Digite exato o nome do produto: ");
        scanf("%s", nomeProduto);
        
        printf("Quantidade: ");
        scanf("%d", &qtdAlterar);

        for (int i = 0; i < 10; i++) {
            if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                if (opcao == 'c') {
                    produtos[i].quantidade -= qtdAlterar; // Você compra, sai do estoque
                } else if (opcao == 'v') {
                    produtos[i].quantidade += qtdAlterar; // Você vende/abastece, entra no estoque
                }
            }
        }
    }

    return 0;
}
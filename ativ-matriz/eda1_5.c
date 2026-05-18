#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// falso -> cadeira livre
bool teatro[15][20] = {false};

void ImprimirTeatro() {
    printf("\n--- Teatro ---\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c ", teatro[i][j] ? 'X' : 'O'); // X para reservado, O para livre
        }
        printf("\n");
    }
}

int main() {
    char opcao;
    int fileira, cadeira;

    while (true) {
        printf("\nDeseja reservar? (r) ou 's' para sair: ");
        scanf(" %c", &opcao);

        if (opcao == 's') break;

        printf("Digite a fileira (1-15): ");
        scanf("%d", &fileira);
        printf("Digite a cadeira (1-20): ");
        scanf("%d", &cadeira);

        if (opcao == 'r') {
            if (!teatro[fileira - 1][cadeira - 1]) {
                teatro[fileira - 1][cadeira - 1] = true; 
                printf("Reserva feita.\n");
            } else {
                printf("ja reservada.\n");
            }
        }
        ImprimirTeatro();
    }
    return 0;
}
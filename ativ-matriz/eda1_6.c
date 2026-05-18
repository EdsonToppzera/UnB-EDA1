#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//andar, sala, temperatura
int predio[5][10][24];

int main() {
    for (int a = 0; a < 5; a++) {
        for (int s = 0; s < 10; s++) {
            for (int t = 0; t < 24; t++) {
                predio[a][s][t] = rand() % 40;
            }
        }
    }

    while (true) {
        int andar, sala;
        printf("\nDigite o andar (1-5), sala (1-10) ou '0 0' para sair: ");
        scanf("%d %d", &andar, &sala);

        if (andar == 0 && sala == 0) break;

        if (andar >= 1 && andar <= 5 && sala >= 1 && sala <= 10) {
            int t_media = 0;
            for (int t = 0; t < 24; t++) {
                printf("sala %d, andar %d: %d graus as %dh\n", sala, andar, predio[andar - 1][sala - 1][t], t);
                t_media += predio[andar - 1][sala - 1][t];
            }
            printf("-------------------------------\n");
            printf("Media diaria: %d graus\n", t_media / 24);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    char cidade[20];
    float *temperatura; 
} TMedidas;

typedef struct {
    int qtde_dias;      
    int qtde_medidas;   
    TMedidas *medidas;
} TTemperaturas;

int main() {
    TTemperaturas controle;
    controle.qtde_dias = 0;
    controle.qtde_medidas = 0;
    controle.medidas = NULL;

    int opcao = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Reset\n");
        printf("2. Inserir Medida\n");
        printf("3. Estatistica\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // RESET
                // Limpa memoria anterior se existir
                if (controle.medidas != NULL) {
                    for (int i = 0; i < controle.qtde_medidas; i++) {
                        free(controle.medidas[i].temperatura);
                    }
                    free(controle.medidas);
                }
                
                printf("Quantidade de dias: ");
                scanf("%d", &controle.qtde_dias);
                
                controle.medidas = (TMedidas*) malloc(controle.qtde_dias * sizeof(TMedidas));
                controle.qtde_medidas = 0;
                printf("Sistema resetado.\n");
                break;

            case 2: // INSERIR
                if (controle.medidas == NULL) {
                    printf("Erro: Inicialize no Reset primeiro.\n");
                } else if (controle.qtde_medidas >= controle.qtde_dias) {
                    printf("Erro: Limite atingido.\n");
                } else {
                    int i = controle.qtde_medidas;
                    printf("Cidade: ");
                    scanf("%s", controle.medidas[i].cidade);
                    
                    // Alocando o ponteiro de temperatura da struct
                    controle.medidas[i].temperatura = (float*) malloc(sizeof(float));
                    printf("Temperatura: ");
                    scanf("%f", controle.medidas[i].temperatura);
                    
                    controle.qtde_medidas++;
                }
                break;

            case 3: // ESTATISTICA
                if (controle.qtde_medidas == 0) {
                    printf("Sem dados.\n");
                } else {
                    float soma = 0, menor, maior;
                    int iMenor = 0, iMaior = 0;

                    for (int i = 0; i < controle.qtde_medidas; i++) {
                        float v = *(controle.medidas[i].temperatura);
                        soma += v;
                        if (i == 0) {
                            menor = maior = v;
                        } else {
                            if (v < menor) { menor = v; iMenor = i; }
                            if (v > maior) { maior = v; iMaior = i; }
                        }
                    }
                    printf("\nResultados:\n");
                    printf("Media: %.2f\n", soma / controle.qtde_medidas);
                    printf("Menor: %s (%.2f)\n", controle.medidas[iMenor].cidade, menor);
                    printf("Maior: %s (%.2f)\n", controle.medidas[iMaior].cidade, maior);
                }
                break;

            case 4: // SAIR
                if (controle.medidas != NULL) {
                    for (int i = 0; i < controle.qtde_medidas; i++) {
                        free(controle.medidas[i].temperatura);
                    }
                    free(controle.medidas);
                }
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}
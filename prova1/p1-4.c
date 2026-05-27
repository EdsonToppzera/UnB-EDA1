#include <stdio.h>
#include <stdlib.h>

//QUESTÃO 4 (2 Ponto): Alocação Dinâmica de Memória
//Escreva a continuação do programa em C acima que: 
//Aloque dinamicamente um vetor de Produto de tamanho n. 
//Preencha os dados de todos os produtos. 
//Libere a memória no final e discurse o porquê é importante fazer isso.
    Produto *vetor = (Produto*) malloc(n * sizeof(Produto));
    
    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf(" %49[^\n]", vetor[i].nome); // Lê a string com espaços
        
        printf("Digite o preco: ");
        scanf("%f", &vetor[i].preco);
        
        printf("Digite a quantidade: ");
        scanf("%d", &vetor[i].quantidade);
    }

    free(vetor);

    return 0;
}

//Com o malloc a memoria fica guardada no sistema até o programar ser fechado, o que pode causar
//memory leak, fazendo o sistema ficar cada vez mais lento e sem RAM, 
//o free() serve justamente pra livrar essa memoria do sistema. 
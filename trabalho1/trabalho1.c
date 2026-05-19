#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dados básicos lidos do arquivo
typedef struct Cadastro {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

// Dados para a lista final (inclui o 'Tipo')
typedef struct CadastroU {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo; 
} TCadastroU;

// Nó da lista de Indústria (Simples)
typedef struct Nol {
    TCadastro *Dados;
    struct Nol *Prox; 
} TNOI;

// Nó da lista de Comércio (Dupla)
typedef struct NoC {
    TCadastro *Dados;
    struct NoC *Ant;  
    struct NoC *Prox; 
} TNOC;

// Nó da lista de Serviços (Dupla)
typedef struct NoS {
    TCadastro *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNOS;

// Descritor da lista de Serviços
typedef struct DescritorS {
    TNOS *Inicio;
    int Tamanho;
    TNOS *Fim;
} TDescritorS;

// Nó da lista Unificada (Dupla)
typedef struct NoU {
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

// Descritor da lista Unificada
typedef struct DescritorU {
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorU;


// funçcoes:

// Insere no final da lista de Indústria
void insereInd(TNOI **lista, TCadastro *cad) {
    TNOI *novo = (TNOI*)malloc(sizeof(TNOI)); 
    novo->Dados = cad;
    novo->Prox = NULL; 
    
    if (*lista == NULL) { 
        *lista = novo;
    } else {
        TNOI *aux = *lista;
        while (aux->Prox != NULL) { 
            aux = aux->Prox;
        }
        aux->Prox = novo; 
    }
}

// Insere no final da lista de Comércio
void insereCom(TNOC **lista, TCadastro *cad) {
    TNOC *novo = (TNOC*)malloc(sizeof(TNOC));
    novo->Dados = cad;
    novo->Prox = NULL;
    
    if (*lista == NULL) {
        novo->Ant = NULL;
        *lista = novo;
    } else {
        TNOC *aux = *lista;
        while (aux->Prox != NULL) { 
            aux = aux->Prox;
        }
        aux->Prox = novo;  
        novo->Ant = aux;   
    }
}

// Insere no final da lista de Serviços
void insereSer(TDescritorS *desc, TCadastro *cad) {
    TNOS *novo = (TNOS*)malloc(sizeof(TNOS));
    novo->Dados = cad;
    novo->Prox = NULL;
    novo->Ant = desc->Fim; 
    
    if (desc->Inicio == NULL) { 
        desc->Inicio = novo;
    } else {
        desc->Fim->Prox = novo; 
    }
    desc->Fim = novo; 
    desc->Tamanho++;  
}

//Arquivos:

// Lê os dados de um cliente no arquivo de texto
TCadastro* leCadastroTxt(FILE *f) {
    TCadastro *c = (TCadastro*)malloc(sizeof(TCadastro));
    
    if (fscanf(f, " %[^\n]", c->CNPJ) != 1) {
        free(c);
        return NULL;
    }
    fscanf(f, " %[^\n]", c->RazaoSocial);
    fscanf(f, " %[^\n]", c->Cidade);
    fscanf(f, " %[^\n]", c->Fone);
    
    return c;
}

// Carrega os 3 arquivos txt e preenche as listas iniciais
void carregarDados(TNOI **lI, TNOC **lC, TDescritorS *lS) {
    FILE *f;
    TCadastro *cad;

    f = fopen("Industria.txt", "r");
    if (f != NULL) {
        while ((cad = leCadastroTxt(f)) != NULL) insereInd(lI, cad);
        fclose(f);
        printf("Arquivo Industria.txt carregado.\n");
    }

    f = fopen("Comercio.txt", "r");
    if (f != NULL) {
        while ((cad = leCadastroTxt(f)) != NULL) insereCom(lC, cad);
        fclose(f);
        printf("Arquivo Comercio.txt carregado.\n");
    }

    f = fopen("Servico.txt", "r");
    if (f != NULL) {
        while ((cad = leCadastroTxt(f)) != NULL) insereSer(lS, cad);
        fclose(f);
        printf("Arquivo Servico.txt carregado.\n");
    }
}

//Unificados:

// Insere um registro na lista unificada com o identificador de tipo
void insereUni(TDescritorU *desc, TCadastro *cad, char tipo) {
    TNoU *novo = (TNoU*)malloc(sizeof(TNoU));
    novo->Dados = (TCadastroU*)malloc(sizeof(TCadastroU));
    
    strcpy(novo->Dados->CNPJ, cad->CNPJ);
    strcpy(novo->Dados->RazaoSocial, cad->RazaoSocial);
    strcpy(novo->Dados->Cidade, cad->Cidade);
    strcpy(novo->Dados->Fone, cad->Fone);
    novo->Dados->Tipo = tipo; 

    novo->Prox = NULL;
    novo->Ant = desc->Fim;

    if (desc->Inicio == NULL) {
        desc->Inicio = novo;
    } else {
        desc->Fim->Prox = novo;
    }
    desc->Fim = novo;
    desc->Tamanho++;
}

// Transfere os dados das 3 listas para a lista unificada
void gerarUnificada(TNOI *lI, TNOC *lC, TDescritorS *lS, TDescritorU *lU) {
    TNOI *auxI = lI;
    while (auxI != NULL) { insereUni(lU, auxI->Dados, 'I'); auxI = auxI->Prox; }

    TNOC *auxC = lC;
    while (auxC != NULL) { insereUni(lU, auxC->Dados, 'C'); auxC = auxC->Prox; }

    TNOS *auxS = lS->Inicio;
    while (auxS != NULL) { insereUni(lU, auxS->Dados, 'S'); auxS = auxS->Prox; }
    
    printf("Lista unificada gerada! Total: %d clientes.\n", lU->Tamanho);
}

//Relatorios:

// Imprime um cadastro original
void printCad(TCadastro *c) {
    printf("CNPJ: %s | Razao: %s | Cidade: %s | Fone: %s\n", c->CNPJ, c->RazaoSocial, c->Cidade, c->Fone);
}

// Imprime o cadastro unificado com o Tipo
void printCadU(TCadastroU *c) {
    printf("[%c] CNPJ: %s | Razao: %s | Cidade: %s | Fone: %s\n", c->Tipo, c->CNPJ, c->RazaoSocial, c->Cidade, c->Fone);
}

// Relatório: Indústria
void relInd(TNOI *l) {
    printf("\nINDUSTRIA -\n");
    while(l != NULL) { printCad(l->Dados); l = l->Prox; }
}

// Relatório: Comércio
void relCom(TNOC *l) {
    printf("\nCOMERCIO -\n");
    while(l != NULL) { printCad(l->Dados); l = l->Prox; }
}

// Relatório: Comércio (Ordem Inversa)
void relComInv(TNOC *l) {
    printf("\nCOMERCIO INVERTIDA -\n");
    if(l == NULL) return;
    while(l->Prox != NULL) l = l->Prox; 
    while(l != NULL) { printCad(l->Dados); l = l->Ant; } 
}

// Relatório: Serviços
void relSer(TDescritorS *d) {
    printf("\nSERVICOS -\n");
    TNOS *aux = d->Inicio;
    while(aux != NULL) { printCad(aux->Dados); aux = aux->Prox; }
}

// Relatório: Serviços (Ordem Inversa)
void relSerInv(TDescritorS *d) {
    printf("\nSERVICOS INVERTIDA -\n");
    TNOS *aux = d->Fim; 
    while(aux != NULL) { printCad(aux->Dados); aux = aux->Ant; }
}

// Relatório: Unificada
void relUni(TDescritorU *d) {
    printf("\nLISTA UNIFICADA -\n");
    TNoU *aux = d->Inicio;
    while(aux != NULL) { printCadU(aux->Dados); aux = aux->Prox; }
}

// Relatório: Unificada (Ordem Inversa)
void relUniInv(TDescritorU *d) {
    printf("\nLISTA UNIFICADA INVERTIDA -\n");
    TNoU *aux = d->Fim;
    while(aux != NULL) { printCadU(aux->Dados); aux = aux->Ant; }
}

//Limpeza:

// Libera toda a memória alocada nas listas
void apagarListas(TNOI **lI, TNOC **lC, TDescritorS *lS, TDescritorU *lU) {
    TNOI *auxI; 
    while(*lI != NULL) { 
        auxI = *lI; 
        *lI = (*lI)->Prox; 
        free(auxI->Dados); 
        free(auxI);        
    }
    
    TNOC *auxC; 
    while(*lC != NULL) { 
        auxC = *lC; 
        *lC = (*lC)->Prox; 
        free(auxC->Dados); 
        free(auxC); 
    }
    
    TNOS *auxS = lS->Inicio; 
    TNOS *proxS;
    while(auxS != NULL) { 
        proxS = auxS->Prox; 
        free(auxS->Dados); 
        free(auxS); 
        auxS = proxS; 
    }
    lS->Inicio = NULL; lS->Fim = NULL; lS->Tamanho = 0;

    TNoU *auxU = lU->Inicio; 
    TNoU *proxU;
    while(auxU != NULL) { 
        proxU = auxU->Prox; 
        free(auxU->Dados); 
        free(auxU); 
        auxU = proxU; 
    }
    lU->Inicio = NULL; lU->Fim = NULL; lU->Tamanho = 0;
    
    printf("Listas apagadas. Memoria limpa!\n");
}


int main() {
    TNOI *listaInd = NULL;
    TNOC *listaCom = NULL;
    TDescritorS descSer = {NULL, 0, NULL};
    TDescritorU descUni = {NULL, 0, NULL};

    int opc = -1;

    while (opc != 0) {
        printf("\n======= MENU SECRETARIA DA FAZENDA =======\n");
        printf("1. Carregar Dados de Entrada\n");
        printf("2. Gerar Lista Unificada\n");
        printf("3. Relatorio: Industrias\n");
        printf("4. Relatorio: Comercio\n");
        printf("5. Relatorio: Comercio Invertida\n");
        printf("6. Relatorio: Servicos\n");
        printf("7. Relatorio: Servicos Invertida\n");
        printf("8. Relatorio: Lista Unificada\n");
        printf("9. Relatorio: Lista Unificada Invertida\n");
        printf("10. Apagar Listas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        
        if (scanf("%d", &opc) != 1) break;

        switch (opc) {
            case 1: carregarDados(&listaInd, &listaCom, &descSer); break;
            case 2: gerarUnificada(listaInd, listaCom, &descSer, &descUni); break;
            case 3: relInd(listaInd); break;
            case 4: relCom(listaCom); break;
            case 5: relComInv(listaCom); break;
            case 6: relSer(&descSer); break;
            case 7: relSerInv(&descSer); break;
            case 8: relUni(&descUni); break;
            case 9: relUniInv(&descUni); break;
            case 10: apagarListas(&listaInd, &listaCom, &descSer, &descUni); break;
            case 0: apagarListas(&listaInd, &listaCom, &descSer, &descUni); printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    }
    return 0;
}
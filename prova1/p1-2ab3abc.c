#include <stdio.h>
#include <stdlib.h>

//QUESTÃO 2 (1 Ponto): Structs 
//Considere a struct Produto do anexo.  
//a) Crie uma variável p1 do tipo Produto e preencha seus campos com dados de exemplo (ex: arroz, feijão, macarrão, etc.). 

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto p1;
    strcpy(p1.nome, "Arroz");
    p1.preco = 25.50;
    p1.quantidade = 2;
    
    //b) Escreva o código completo para imprimir todos os campos de p1. 
    printf("Nome: %s\n", p1.nome);
    printf("Preço: R$ %.2f\n", p1.preco);
    printf("Quantidade: %d\n", p1.quantidade);

    //QUESTÃO 3 (2 Ponto): Ponteiros e Structs 
    //Considere a struct Produto do anexo e a variável p1 criada na Questão 2. 
    //a) Declare um ponteiro ptr do tipo Produto* e faça-o apontar para p1. 
    Produto *ptr = &p1;

    //b) Usando o operador ->, imprima o nome e o preço do produto apontado por ptr.
    printf("Produto (via ponteiro): %s\n", ptr->nome);
    printf("Preço (via ponteiro): R$ %.2f\n", ptr->preco);
    
    return 0;
}

//c) Explique a diferença entre ptr->preco e (*ptr).preco. 
//ptr->preco é uma forma abreviada de acessar o campo preco do produto apontado por ptr, enquanto (*ptr).preco é a forma completa que tira a 
//referencia do ponteiro ptr para acessar o campo preco. Ambas as expressões resultam no mesmo valor, 
//mas a notação com -> é mais concisa e comum ao trabalhar com ponteiros para structs.
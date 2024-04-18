#include<stdio.h>
#include<stdlib.h>

/*Criação da estrutura pilha*/
typedef struct pilha Pilha;

/*função de criar a pilha*/
Pilha* pilha_cria(void);

/*Função para adicionar elemento a pilha*/
void pilha_push(Pilha* p,float v);

/*Função para retirar elemento da pilha*/
float pilha_pop(Pilha* p);

/*Função que verifica se a pilha esta vazia*/
int pilha_vazia(Pilha* p);

/*Função de liberar a pilha*/
void pilha_libera(pilha* p);
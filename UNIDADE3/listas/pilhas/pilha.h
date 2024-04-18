#include <stdio.h>
#include <stdlib.h>

/*criação da estrutura pilha*/
typedef struct pilha Pilha;

/*função de criar a pilha*/
Pilha* pilha_cria(void);

/*função para adicionar um elemneto a pilha*/
void pilha_push(Pilha* p, float v);

/*função para retirar elemento da pilha*/
float pilha_pop(Pilha* p);

/*função que verifica se a pilha esta vazia*/
int pilha_vazia(Pilha* p);

/*função que libera a pilha */
void pilha_libera(Pilha* p);

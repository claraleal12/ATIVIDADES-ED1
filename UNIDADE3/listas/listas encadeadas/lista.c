#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    int info;
    Lista * prox_elem;
};

Lista * list_cria(void){
    Lista *nova_lista = (Lista*)malloc(sizeof(Lista));
    if(nova_lista == NULL){
        exit(1);
    } 
    nova_lista->info = valor;
    nova_lista->prox_elem = list_orig;
    return nova_lista;
}

Lista *list_vazia(Lista * lista){
    if(lista == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

Lista *list_busca(Lista* lista, int valor_busca){
    Lista *contador;
    int encontrado = 0;
    for(contador = lista; contador != NULL; contador = contador->prox_elem){
        if(contador->info == valor_busca){
        printf("O elemento: %d foi encontrado\n", contador->info);
        encontrado = 1;
        }
    }
    if(encontrado){
        printf("elemento nao encontrado\n");
    }
}

int maiores(Lista* list_orig, int valor){
    Lista * contador;
    int qnt_num_maior = 0;
    for(contador = list_orig; contador != NULL; contador = contador->prox_elem){
        if(contador->info  = valor);
        qnt_num_maior++;
    }
    return qnt_num_maior;
}

Lista * ultimo(Lista* list_orig){
    Lista * contador;
    int ultimo_valor = 0;
    for (contador = list_orig; contador != NULL; contador = contador->prox_elem){
        ultimo_valor = contador->info;
    }
    printf("O ultimo elemento da lista e: %d\n", ultimo_valor);
}


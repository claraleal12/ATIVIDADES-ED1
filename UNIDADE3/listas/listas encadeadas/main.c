#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(void){
    int qnt_maior = 0;
    int numero_digitado = 0;

    Lista * lista_encadeada = list_cria;
    lista_encadeada = list_insere(lista_encadeada, 12);
    lista_encadeada = list_insere(lista_encadeada, 76);
    lista_encadeada = list_insere(lista_encadeada, 23);
    lista_encadeada = list_insere(lista_encadeada, 86);
    lista_encadeada = list_insere(lista_encadeada, 15);
    lista_encadeada = list_insere(lista_encadeada, 56);


    printf("\n Informe o numero que quer comparar com os que estao presente na lista\n");
    scanf("%d", &numero_digitado);
    qnt_maior = maiores(lista_encadeada, numero_digitado);
    printf("\n Existem %d numeros maiores do que %d na lista.\n", qnt_maior, numero_digitado);

    return 0;
}
#include <stdlib.h>
#include "fila.h"

/*Arquivo fila.c*/
typedef struct _fila{
    int ini, fim;
    int qntde; /*numero de elemntos da fila*/
    int MAX_SIZE; /*tamanho maximo da fila*/
    int *val; /*vetor dos valores*/
}Fila;

Fila *CriaFila(int MAX_SIZE){
    Fila *Q = (Fila*)calloc(1,sizeof(Fila));

    Q->val = (int*)calloc(MAX_SIZE, sizeof(int));
    Q->MAX_SIZE = MAX_SIZE;
    Q->qntde = 0;
    Q->ini = Q->fim = 0;

return Q; 
}

void DestruirFila(Fila **Q){
    Fila *Qaux = *Q;
    free(Qaux->val);
    free(Qaux);
    *Q = NULL;
}

int FilaVazia(Fila *Q){
    return (Q->qntde == 0);
}

int FilaCheia(Fila *Q){
    return (Q->qntde == Q->MAX_SIZE);
}

int InsereFila(Fila*Q, int elem){
    if(FilaCheia(Q)){
        printf("QUE PENA, A FILA ESTA CHEIA!!!!!!!!!!!!!!!!!!!\n");
        return 0;
    }
    else{
        Q->val[Q->fim] = elem;
        Q->fim = (Q->fim + 1) % Q->MAX_SIZE;
        Q->qntde++;
        return 1;
    }
}

int RemoveFila(Fila *Q){
    if (FilaVazia(Q)){
        printf("EBA FILA ESTA VAZIA!!!!!!!!!!!!!!!!!!!!");
        return 0;
    }
    else{
        Q->ini = (Q->ini+1) %  Q->MAX_SIZE;
        Q->qntde--;
        return 1;
    }
}


int ConsultaFila(Fila *Q, int *elem){
    if (FilaVazia(Q)){
        printf("EBA FILA ESTA VAZIA!!!!!!!!!!!!!!!!!!!!!!!");
        return 0;
    }
    else{
        *elem = Q->val[Q->ini];
        return 1;
    }
}
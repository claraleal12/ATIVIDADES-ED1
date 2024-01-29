#include <stdio.h>
#include <stdlib.h>

float media(int tamanho, int *vetor) {
    int soma = 0;
    int contador;
    for(contador = 0; contador < tamanho; contador++){
    soma = vetor[contador] + soma;
    }
    return soma/tamanho;
}

int main() {
    int linhas =  3, colunas = 3,  i, j;

    //alocacao vetor ponteiros 
    int **matriz = (int**) malloc(linhas*sizeof(int*));

    //alocaçao cada linha da matriz
    for (i = 0; i< linhas; i++) {
        matriz[i] = (int*) malloc(colunas*sizeof(int*));
    }

//liberaçao de memoria alocada
    for(i = 0; i < linhas; i++){
        free(matriz[1])
    }
    free(matriz);
return 0;
}


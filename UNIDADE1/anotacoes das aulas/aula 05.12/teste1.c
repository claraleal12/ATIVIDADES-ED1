#include <stdio.h>  // printf, scanf
#include <stdlib.h> //funções malloc, calloc, free, exit

int main(void) {
    int tamanho  = 5;
    int contador;
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    if(vetor == NULL) {
        printf("Erro na alocacao de memoria\n");
        exit(1); //aborta a execução do programa
    }
    else{
        printf("Alocacao realizada com sucesso!\n");
    }

    //ler os dados do vetor
    printf("Digite o valor do vetor:\n");
    for (contador = 0; contador < tamanho; contador++){
        scanf("%d", &vetor[contador]);
    }
    free(vetor);

return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tamanho = 5;
    int contador;
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    if (vetor == NULL){
       printf("Erro na alocacao de memoria\n");
       exit(1); 
    }
    else{
        printf("Sucesso na alocacao de memoria\n");
    }
    printf("Digite o valor do vetor:\n");
    for (contador = 0; contador < tamanho; contador ++){
        scanf("%d", &vetor[contador]);
    }
    free(vetor);
return 0;
}
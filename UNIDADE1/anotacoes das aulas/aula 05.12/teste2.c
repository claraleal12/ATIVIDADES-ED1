#include <stdio.h>  
#include <stdlib.h>

int main(void) {
    int tamanho = 5, novo_tamanho;
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    printf("Entre com o novo tamanho do vetor:\n");
    scanf("%d", &novo_tamanho);
    vetor = (int *) realloc(vetor, novo_tamanho * sizeof(int));
    if (vetor == NULL) {
       printf("Erro ao alocar mamoria\n");
       exit(1);
    }
    else {
        printf("Sucesso ao alocar a memoria\n");
    }
    free (vetor);

return 0;
}
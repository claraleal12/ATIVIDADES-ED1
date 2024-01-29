#include <stdio.h>
#include<stdlib.h>

#include <stdio.h>
#include<stdlib.h>

int main(void){
    int N;

    printf("Digite o número de entrevistados: ");
    scanf("%d", &N);

    char *sexo = (char *)malloc(N * sizeof(char));
    char *opiniao = (char *)malloc(N * sizeof(char));

    if (sexo == NULL || opiniao == NULL) {
        printf("Erro na alocação de memória. Encerrando o programa.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Para a pessoa %d:\n", i + 1);

        printf("Sexo (M/F):\n ");
        scanf(" %c", &sexo[i]);

        printf("Opinião (Gostou/não gostou):\n ");
        scanf(" %c", &opiniao[i]);
    }
    printf("Resultados da pesquisa:\n");
    for (int i = 0; i < N; i++) {
        printf("Pessoa %d - Sexo: %c, Opinião: %c\n", i + 1, sexo[i], opiniao[i]);
    }

    free(sexo);
    free(opiniao);

return 0;
}

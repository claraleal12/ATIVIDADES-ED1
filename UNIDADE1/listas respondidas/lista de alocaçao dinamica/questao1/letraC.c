
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    int countHomemNaoGostou = 0; 

    printf("Digite o número de entrevistados:\n ");
    scanf("%d", &N);

    char *sexo = (char *)malloc(N * sizeof(char));
    char *opiniao = (char *)malloc(N * sizeof(char));

    if (sexo == NULL || opiniao == NULL) {
        // Verificar se a alocação foi bem-sucedida
        printf("Erro na alocação de memória. Encerrando o programa.\n");
        return 1; 
    }

   for (int i = 0; i < N; i++) {
        printf("Para a pessoa %d:\n", i + 1);

        printf("Sexo (M/F):\n ");
        scanf(" %c", &sexo[i]);

        printf("Opinião (Gostou/Não gostou):\n ");
        scanf(" %c", &opiniao[i]);

        if (sexo[i] == 'M' && opiniao[i] == 'n') {
            countHomemNaoGostou++;
        }
    }

    if (countHomemNaoGostou > 0) {
        float percentualHomemNaoGostou = (float)countHomemNaoGostou / N * 100;
        printf("Porcentagem de homens que não gostaram: %.2f%%\n", percentualHomemNaoGostou);
    } else {
        printf("Nenhum homem respondeu que não gostou do produto.\n");
    }

    printf("\nResultados da pesquisa:\n");
    for (int i = 0; i < N; i++) {
        printf("Pessoa %d - Sexo: %c, Opinião: %c\n", i + 1, sexo[i], opiniao[i]);
    }

    free(sexo);
    free(opiniao);

return 0; 
}

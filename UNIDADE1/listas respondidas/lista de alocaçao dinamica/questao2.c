#include <stdio.h>

int main() {
    int N; 
    char gabarito[100];
    float notaAluno[10]; 
    int numAprovados = 0; 

    printf("Digite o número de questões:\n ");
    scanf("%d", &N);

    if (N <= 0 || N > 100) {
        printf("Número de questões inválido. Encerrando o programa.\n");
        return 1; 
    }

    printf("Digite o gabarito da prova (sem espaços):\n ");
    scanf("%s", gabarito);

    for (int i = 0; i < 10; i++) {
        printf("Digite as respostas do aluno %d (sem espaços): ", i + 1);
        char respostasAluno[100];
        scanf("%s", respostasAluno);

        int pontuacao = 0;
        for (int j = 0; j < N; j++) {
            if (respostasAluno[j] == gabarito[j]) {
                pontuacao += 10 / N;
            }
        }
        notaAluno[i] = pontuacao;
     if (notaAluno[i] >= 6) {
            numAprovados++;
        }
    }

    // Mostrar nota do aluno
    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < 10; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notaAluno[i]);
    }

    // Calcular e mostrar porcentagem de aprovação
    float porcentagemAprovacao = (float)numAprovados / 10 * 100;
    printf("\nPorcentagem de aprovação: %.2f%%\n", porcentagemAprovacao);

return 0;
}
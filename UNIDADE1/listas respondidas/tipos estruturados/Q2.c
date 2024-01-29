#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 80
#define MAX_NOME 120

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char turma;
    float notas[5];
    float media;
}Aluno;

void inicia_alunos(Aluno** alunos){
    for (int i = 0; i< MAX_ALUNOS; i++){
        alunos[i] = NULL;
    }
}

void matricula(int n, Aluno** alunos){
    if(n>= 0 && n < MAX_ALUNOS &&alunos[n] == NULL){
        alunos[n] = (Aluno*)malloc(sizeof(Aluno));

        printf("\n Matricula: \n");
        scanf("%d\n", &alunos[n]->matricula);

        printf("\n Nome: \n");
        scanf("%s\n", &alunos[n]->nome);

        printf("\n Turma: \n");
        scanf("%s\n", &alunos[n]->turma);

        printf("\n Notas: \n");
        for(int i = 0; i < 5; i++){
            scanf("%f\n", &alunos[n]->notas[i]);
        }

        alunos[n]->media = 0.0;
    }
    else{
        printf("\n Erro: Nao ha vaga disponivel para a matricula informada\n");

    }
}

void divulga_notas(int n, Aluno** alunos){
    for(int i = 0; i < n; i++){
        if(alunos[i] != NULL){
            float soma = 0.0;
            for(int j = 0; j < 5; j++){
                soma += alunos[i]->notas[j];
            }
            alunos[i]->media = soma / 5.0; 
        }
    }
}

void imprime_tudo(int n, Aluno** alunos){
    for(int i = 0; i < n; i++){
        if(alunos[i] != NULL){
            printf("\n Matricula: %d\n, \n Nome: %s\n, \nTurma: %s\n, \n Media: %.2f\n",
            alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->media);


        }
    }
}

void imprime_turma(int n; Aluno** alunos, char turma){
    for(int i = 0; i < n; i++){
        if(alunos[i] != NULL&& alunos[i]->turma == turma){
            printf("Matricula: %d, Nome: %s, Turma: %c, Media: %.2f\n",
                   alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->media);
       }
    }
}

void imprime_turma_aprovados(int n, Aluno** alunos, char turma) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->turma == turma && alunos[i]->media >= 7.0) {
            printf("Matricula: %d, Nome: %s, Turma: %c, Media: %.2f\n",
                   alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->media);
        }
    }
}

int main(){
    Aluno* alunos[MAX_ALUNOS];
    inicializa_alunos(alunos);

    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));

    // A FUNÇÃO MATRÍCULA PARA 3 ALUNOS
    matricula(0, alunos);
    matricula(1, alunos);
    matricula(2, alunos);
    matricula(3, alunos);
    matricula(4, alunos);

    lanca_notas(5, alunos);

    printf("\nDados de todos os alunos:\n");
    imprime_tudo(5, alunos);

    printf("\nDados da turma A:\n");
    imprime_turma(5, alunos, 'A');

    printf("\nAlunos aprovados na turma A:\n");
    imprime_turma_aprovados(5, alunos, 'A');

    // LIBERANDO A MEMORIA ALOCADA DINAMICAMENTE
    for (int i = 0; i < MAX_ALUNOS; i++) {
        free(alunos[i]);
    }

free(aluno);
return 0;
}
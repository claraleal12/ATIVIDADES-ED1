#include <stdio.h>
#include <stdlib.h>

/*Exemplo de ANINHAMENTO DE ESTRUTURAS*/

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
}Disciplina;

typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
    // Vetor de disciplinas
    Disciplina * materias;
}Aluno;

int main(void){
    //Alocação de memoria da variavel aluno
    Aluno * aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno == NULL){
        exit(1);
    }
    //Alocação para o vetor de 2 disciplinas
    aluno->materias = (Disciplina*) malloc(6*sizeof(Disciplina));
    if (aluno->materias == NULL){
        exit(1);
    }
    printf("Informe os dados do aluno: nome, idade e matricula\n");
    scanf("%s", aluno->nome);
    scanf("%d %d", &aluno->idade, &aluno->matricula);

    // Cadastro das disciplinas
    int index;
    for(index=0; index<6; index++){
        printf("Cadastro da disciplina %d\n", index+1);
        scanf("%[^\n]", aluno->materias[index].nome);
        scanf("%d", &aluno->materias[index].codigo);
        scanf("%f", &aluno->materias[index].nota);
    }
    free(aluno);
return 0;
}

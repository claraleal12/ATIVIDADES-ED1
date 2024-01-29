#include <stdio.h>
#include <stdlib.h>

// ANINHAMENTO DE ESTRUTURAS

typedef struct disciplina {
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
    Disciplina materias;
} Aluno;

int main(void){
    Aluno aluno; // Declarando uma variavel do tipo Aluno
    aluno.idade = 19; //Acessando a variavel idade dentro do aluno
    aluno.matricula = 12345; // Acessando a variavel matricula dentro do aluno
    aluno.materias.codigo = 1233; 
    printf("%d, %d, %d, \n", aluno.idade, aluno.matricula, aluno.materias.codigo);
    
return 0;
}
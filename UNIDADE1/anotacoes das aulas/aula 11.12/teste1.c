#include <stdio.h>
#include <stdlib.h>
 
typedef struct aluno {
   char nome[50];
   int idade;
   int mat;
   char email[50];
}aluno;

void preenche(struct aluno * estudante){
   printf("Digite o nome do aluno:\n");
   scanf("%[^\n]", estudante->nome);
   printf("Digite a idade do aluno:\n");
   scanf("%d", &estudante->idade);
   printf("Digite matricula do aluno:\n");
   scanf("%d", &estudante->mat);
   printf("Digite o email do aluno:\n");
   scanf("%s", &estudante->email);
}

void imprime(struct aluno * estudante){
   printf(" Nome: %s \n Idade: %d \n Matricula: %d \n Email: %s \n", estudante->nome, estudante->idade, estudante->mat, estudante->email );
}

int main(void){
   struct aluno * estudante = (struct aluno*) malloc(sizeof(struct aluno));
   if(estudante == NULL){
      exit(1);
   }
   preenche(estudante);
   imprime(estudante);
   free(estudante); 
   return 0;
}
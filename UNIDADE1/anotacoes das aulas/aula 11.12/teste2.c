#include <stdio.h>
#include <stdlib.h>

typedef struct docente {
    char nome[50];
    int idade;
    int ID;
    char email[50];
}docente;

void preenche(struct docente * professor){
    printf("Digite o nome do docente: \n");
    scanf("%[^\n]", professor->nome);
    printf("Digite a idade do docente\n");
    scanf("%d", &professor->idade);
    printf("Digite a ID do docente\n");
    scanf("%d", &professor->ID);
    printf("Digite o email do docente\n");
    scanf("%s", &professor->email);

}

void imprime(struct docente * professor){
    printf("Nome: %s\n Idade: %d\n ID: %d\n Email: %s\n", professor->nome, professor->idade, professor->ID, professor->email);
}

int main(void){
    struct docente * professor = (struct docente*) malloc(sizeof(struct docente));
    if(professor == NULL){
    exit(1);
    }

    preenche(professor);
    imprime(professor);
    free(professor);
    return 0;
}
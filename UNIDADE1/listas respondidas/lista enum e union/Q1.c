#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union genero{
    char masculino[10];
    char feminino[10];
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero sexo;
    int op
}Pessoa;

void preenche(Pessoa * pessoa){
    printf("Informe o nome:\n");
    scanf("%[^\n]", pessoa->nome);

    printf("informe a idade:\n");
    scanf("%d", &pessoa->idade);

    printf("Informe o genero:\n 0 - Masculino \n 1 - Feminino");
    scanf("%d", &pessoa->op);

    if(pessoa->op){
        strcpy(pessoa->sexo.masculino, "Masculino");
    }
    else{
        strcpy(pessoa->sexo.feminino, "Feminino");
    }
}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    
    preenche(pessoa);

    printf("Nome: %s\n", pessoa->nome);
    printf("Idade:%d\n", pessoa->idade);

    if(pessoa->op){
        printf("Sexo: %s\n", pessoa->sexo.masculino);
    }
    else{
        printf("Sexo: %s\n", pessoa->sexo.feminino);
    }

free(pessoa);
return 0;
}
#include <stdio.h>

typedef union documentos{
    char rg[15];
    char cpf[15];
}Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc;
}Pessoa;

void dados_pessoa(Pessoa * p){
    int opcao;
    printf("\n Informe o nome: \t");
    scanf(" %[^\n]", p->nome);
    printf("\n Informe a idade: \t");
    scanf("%d", &p->idade);
    printf("\n Digite seu CPF:\t");
    scanf("%s", p->doc.cpf);
    printf("\n Digite o seu RG: \t");
    scanf("%sS", p->doc.rg);
    printf("\n Digite 1 para CPF e 2 para RG \t");
    scanf("%d", &opcao);
         if(opcao){
            scanf("[^\n]", p->doc.cpf);
         }
         else{
            scanf("[^\n]", p->doc.rg);
         }
         

}

int main(void){
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(&pessoa);
    printf("CPF = %s \n RG = %s", pessoa->doc.cpf, pessoa->doc.rg);
    free(pessoa);

return 0;
}
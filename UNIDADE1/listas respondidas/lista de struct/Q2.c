#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome [20];
    int rg;
    int idade;
}Pessoa;

void preenche (struct pessoa * Pessoa){

    printf("Digite o nome:\n");
    scanf("%s\n", Pessoa->nome);

    printf("Digite o numero do RG:\n");
    scanf("%d\n", &Pessoa->rg);

    printf("Digite a idade:\n");
    scanf("%d\n", &Pessoa->idade);
}

void imprime(struct pessoa *Pessoa){
    printf("Nome: %s\n", Pessoa -> nome);
    printf("Idade: %d\n", Pessoa -> rg);
    printf("Rg: %d\n", Pessoa -> idade);
}

struct pessoa * MudaIdade(struct pessoa *Pessoa){
     printf("Digite a nova idade:\n");
     scanf("%d\n", &Pessoa->idade);
}

void maisVelhoMaisNovo(struct pessoa * Pessoa, int n){
    int maior_idade = Pessoa[0].idade;
    int menor_idade = Pessoa[0].idade;
    int posicao_maior = 0;
    int posicao_menor = 0;

    for (int i = 0; i < n; i++){
        if(Pessoa[i].idade > maior_idade){
            maior_idade = Pessoa[i].idade;
            posicao_maior = i;
        }
        else if(Pessoa[i].idade < menor_idade){
            menor_idade = Pessoa[i].idade;
            posicao_menor = i;
        }
        
    }
       printf("A pessoa mais velha: %s " "idade: %d\n", Pessoa[posicao_maior].nome, Pessoa[posicao_maior].idade);

       printf("A pessoa mais nova: %s " "idade: %d", Pessoa[posicao_menor].nome, Pessoa[posicao_menor].idade);
}

int main(void){

    int quantidadePessoas, posicao, opcaoEscolha;
    printf("Digite o numero de pessoas:\n ");
    scanf("%d", &quantidadePessoas);

    struct pessoa * Pessoa = (struct pessoa*) malloc (quantidadePessoas * sizeof(struct pessoa));

    for(int i = 0; i < quantidadePessoas; i++){
        printf("------------------------------------\n");
        printf("Digite os dados da pessoa %d\n", i+1);
        preenche(&Pessoa[i]);
    }

    for(int i = 0; i < quantidadePessoas; i++){
        printf("------------------------------------\n");
        printf("Dados da pessoa %d\n", i+1);
        imprime(&Pessoa[i]);
    }  

    printf("Deseja alterar a idade de alguma pessoa? (1 - SIM, 2 - NAO): ");
    scanf("%d", &opcaoEscolha);

    if(opcaoEscolha ==1){
    
    printf("Digite a posicao da pessoa que deseja alterar a idade: ");
    scanf("%d", &posicao);

    MudaIdade(&Pessoa[posicao]);
    }

    maisVelhoMaisNovo(Pessoa, quantidadePessoas);

    free(Pessoa);
    return 0;
}
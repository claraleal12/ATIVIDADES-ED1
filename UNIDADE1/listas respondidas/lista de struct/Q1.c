#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20];
    float salario;
    int ID[10];
    char cargo[20];
    
}Funcionario;

void preenche (struct funcionario * servidor){

    
    printf("Digite o nome do funcionario:\n");
    scanf("%s", servidor->nome);

    printf("Digite o salario do funcionario:\n");
    scanf("%f", &servidor->salario);

    printf("Digite o identificador do funcionario:\n");
    scanf("%d", &servidor->ID);

    printf("Digite o cargo do funcionario:\n");
    scanf("%s", servidor->cargo);

}

void imprime (struct funcionario * servidor){
    printf(" Nome: %s\n Salario: %2.f\n ID : %d\n Cargo: %s\n", servidor->nome, servidor->salario, servidor->ID, servidor->cargo);
}

struct funcionario *mudaSalario(struct funcionario *servidor){
    printf("Insira o novo valor para o salario do funcionario:\n ");
    scanf("%f", &servidor->salario);
}
void maiorMenorSalario(struct funcionario *servidor, int n){
    int maior_salario = servidor[0].salario;
    int menor_salario = servidor[0].salario;
    int posicao_maior = 0;
    int posicao_menor = 0;

    for (int i = 0; i < n; i++){
        if (servidor[i].salario > maior_salario){
            maior_salario = servidor[i].salario;
            posicao_maior = i;
        }
        else if(servidor[i].salario < menor_salario){
            menor_salario = servidor[i].salario;
            posicao_menor = i;
        }
          
    }

     printf(" Cargo do funcionario: %s\n "
    "Mairo salario: %.2f\n",servidor[posicao_maior].cargo,servidor[posicao_maior].salario);
    
    printf(" Cargo do funcionario: %s\n "
    "Menor salario: %.2f\n",servidor[posicao_menor].cargo,servidor[posicao_menor].salario);
    

}

int main(void){
    int quantidadeFuncionarios, opcaoMudar;

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &quantidadeFuncionarios); 

   struct funcionario funcionario[quantidadeFuncionarios];

   for (int i = 0; i < quantidadeFuncionarios; i++){
        printf("Digite os dados do funcionario %d\n", i+1);
        preenche(&funcionario[i]);
   }

   for (int i = 0; i < quantidadeFuncionarios; i++){
        printf("Dados do funcionario %d\n", i +1);
        imprime(&funcionario[i]);
   }

   printf("VOCE DESEJA ALTERAR O VALOR DE ALGUM SALARIO (1- SIM, 2- NAO): ");
   scanf("%d",&opcaoMudar);

   if(opcaoMudar == 1){
        int funcionario_escolhido;
        printf("DIGITE O NUMERO DO FUNCIONARIO QUE DESEJA ALTERAR O SALARIO: ");
        scanf("%d",&funcionario_escolhido);

        mudaSalario(&funcionario[funcionario_escolhido-1]);
        printf("DADOS DO FUNCIONARIO %d\n",funcionario_escolhido);  
        imprime(&funcionario[funcionario_escolhido-1]);
   }
    maiorMenorSalario(funcionario, quantidadeFuncionarios);

return 0;
}
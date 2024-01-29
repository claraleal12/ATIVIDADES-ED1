#include <stdio.h>
#include <stdlib.h>

struct funcionario{
    char *nome[20];
    float *salario;
    int *id;
    char *cargo[10];
};


void imprime (struct funcionario* servidor){
    printf("\n %s", servidor->nome);
    printf("\n %f", *servidor->salario);
    printf("\n %d", *servidor->id);
    printf("\n %s", servidor->cargo);


}

struct funcionario *mudaSalario(struct funcionario*servidor){
    printf("\nInsira o novo valor para o salario do funcionario: ");
    scanf("%f", &servidor->salario);

    return servidor;
}

struct funcionario * alocarFuncionario(struct funcionario* servidor){
    servidor = (struct funcionario*)malloc(sizeof(struct funcionario));
    servidor->nome = (char *)malloc(20*sizeof(char));
    servidor->salario = (float *)malloc(sizeof(float));
    servidor->id = (int *)malloc(sizeof(int));
    servidor->cargo = (char *)malloc(sizeof(char));

    return servidor;
    
}

struct funcionario *criaFuncionario(struct funcionario *servidor){

    

    printf("\nInsira o nome do funcionario: ");
    scanf("%s", servidor->nome);
    
    printf("\nInsira o salario do funcionario: ");
    scanf("%f", servidor->salario);
    
    printf("\nInsira o id do funcionario: ");
    scanf("%d", servidor->id);
    
    printf("\nInsira o cargo do funcionario: ");
    scanf("%s", servidor->cargo);

    return servidor;
    
}


int main(){

struct funcionario *servidor = criaFuncionario(servidor);
servidor  = criaFuncionario(servidor);
imprime(servidor);
servidor = mudaSalario(servidor);
imprime(servidor);

}
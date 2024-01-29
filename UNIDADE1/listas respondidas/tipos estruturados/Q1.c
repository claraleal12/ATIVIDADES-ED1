#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float preco;
    char local[50];
    char atracao[20];
}ingresso;

void preenche(ingresso *i){
    printf("\n Digite o preco do ingresso:\n");
    scanf("%f\n", &i->preco);

    printf("\n Digite o local do evento:\n");
    scanf("%[^\n]", i->local);

    printf("\n Digite a atracao do evento:\n");
    scanf("%[^\n]", i->atracao);
}

void imprime(ingresso * i){
    printf("Preco: R$ %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atracao: %s\n", i->atracao);
}

void muda_preco(ingresso * i, float valor){
    i->preco = valor;
}

void imprime_menor_maior_preco(int n, ingresso * vet){
    float maior_preco = vet[0].preco;
    float menor_preco = vet[0].preco;
    int numero_menor = 0, numero_maior = 0;

    for(int i = 1; i < n; i++){
        if(vet[1].preco < menor_preco) {
            menor_preco = vet[i].preco;
            numero_menor = i;
        }

        if(vet[i].preco > maior_preco){
            maior_preco = vet[i].preco;
            numero_maior = i;
        }
    }

    printf("\n Evento mais caro:\n");
    imprime(&vet[numero_maior]);

    printf("\n Evento mais barato:\n");
    imprime(&vet[numero_menor]);
}

int main(void){

    int num_ingressos;
    printf("\n Digite o numero de ingressos que deseja cadastrar:\n");
    scanf("%d\n", &num_ingressos);

    ingresso * ingressos = (ingresso*)malloc(num_inigresos * sizeof(ingresso));]

    for (int i = 0; i < num_ingressos; i++){
        printf("\n Cadastrando dados do ingresso %d:\n", i + 1);
        preenche(&ingressos[i]);
    }

    printf("\n Ingressos cadastrados:\n");
    for (int i = 0; i< num_ingressos; i++){
        printf("\n Ingresso &d:\n", i + 1);
        imrpime(&ingressos[i]);
    }

    float novo_preco;
    printf("\n Digite o novo preco do ingresso:\n");
    scanf("%f", &novo_preco);


    int numero_altera;
    printf("\n Digite o numro do ingresso que deseja alterar:\n");
    scanf("%d\n", &numero_altera);

    altera_preco(&ingressos[numero_altera - 1], novo_preco);

    printf("\n Ingressos apos a alteracao:\n");
    for (int i = 0; i < num_ingressos; i++){
        printf("\n Ingresso &d:\n", i + 1);
        imprime(&ingressos[i]);
    }

    printf("\n Ingressos do evento mais caro e mais barato:\n\n");
    imprime_menor_maior_preco(num_ingressos, ingressos);

free(ingressos);
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union tipo {
    char alimento[15];
    char bebida[15];
    char eletronico[15];
}Tipo;

typedef struct produto {
    char nome[15];
    float preco;
    Tipo tipo;
    int opcao;
}Produto;

void cad_produto(Produto *p) {

    printf("\n Informe o nome do produto: ");
    scanf(" %[^\n]", p->nome);

    printf("\n Informe o preco do produto: ");
    scanf("%f", &p->preco);

    printf("\n Digite 1 - para Alimento / 2 - para Bebida / 3 - para Eletronico: ");
    scanf("%d", &p->opcao);

        switch (p->opcao) {
        case 1:
            strcpy(p->tipo.alimento, "Alimento");
            break;
        case 2:
            strcpy(p->tipo.bebida, "Bebida");
            break;
        case 3:
            strcpy(p->tipo.eletronico, "Eletronico");
            break;
    }
}

int main(void) {
   
    Produto *p = malloc(sizeof(p));

    cad_produto(p);

    printf("Nome: %s\n", p->nome);
    printf("Preco: %f\n", p->preco);

        switch (p->opcao) {
        case 1:
            printf("Tipo do produto: %s\n", p->tipo.alimento);
            break;
        case 2:
            printf("Tipo do produto: %s\n", p->tipo.bebida);
            break;
        case 3:
            printf("Tipo do produto: %s\n", p->tipo.eletronico);
            break;
    }

    free(p);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char * nome = (char*) malloc(50*sizeof(char));
    if(nome == NULL) {
        exit(1);
    }
    printf("Digite o seu nome completo\n");
    scanf("%s", nome);
    free(nome);

return 0;
}
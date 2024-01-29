#include <stdio.h>

enum MES{
    Janeiro, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setrmbro, Outrubro, Novembro, Dezembro
};

struct Data{
    int dia;
    enum MES mes;
    int ano;
};

int main(){
    struct Data data;
    printf("Digite o dia, mes e ano(separando por espacos):\n");
    scanf("%d %d %d", &data.dia, (int*)&data.mes, &data.ano);

    printf("Data: %02d/%02d/%04d", data.dia, data.mes, data.ano);

return 0;
}
#include<stdio.h>

int main(void) {
int x, *p;
x = 100;
p = &x;
printf(“Valor de p = %d\t Valor de *p = %d”, &p, *p);
}
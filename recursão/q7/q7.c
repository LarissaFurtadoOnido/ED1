/*Faça uma função recursiva que calcule o valor da série S descrita a seguir para um valor n >0.
S = 1 + 1/2! + 1/3! + ... 1/n!*/

#include <stdio.h>

float serieS(int n){
    if(n==1)
        return 1.0;
    
    return 1.0/n + serieS(n - 1);
}

int funcaoSecundaria(){
    int n;
    float soma;

    printf("Forneça um número > 0: ");
    scanf("%d", &n);

    soma=serieS(n);

    printf("%.6f\n", soma);


    return 0;
}

int main(){
    return funcaoSecundaria();
}
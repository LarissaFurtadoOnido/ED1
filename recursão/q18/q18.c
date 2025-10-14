/*Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o fatorial
duplo desse número. O fatorial duplo é definido como o produto de todos os números naturais ıımpares
de 1 até algum número natural ıımpar N. Assim, o fatorial duplode 5 é 5!!= 1x3x5 = 15*/

#include <stdio.h>

int fatorialDuplo(int n){
    if(n==1)
        return 1;
    
    return n * fatorialDuplo(n - 2);
}

int funcaoSecundaria(){
    int n, resultado;

    printf("Forneça um número ímpar: ");
    scanf("%d", &n);

    resultado=fatorialDuplo(n);

    printf("%d!! = %d\n", n, resultado);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
/*Faça uma função recursiva que receba um número inteiro positivo N e retorne o super-fatorial desse
número. O superfatorial de um número N é definida pelo produto dosprimeiros fatoriais de N.
Assim, o superfatorial de 4 é
sf(4)= 1! * 2! * 3! * 4! = 288*/

#include <stdio.h>

int superFatorial(int n){
    int fatorial=1, i;
    
    if(n==1)
        return 1;
    
    for(i=n;i>1;i--)
        fatorial *= i;

    return fatorial * superFatorial(n-1);
}

int funcaoSecundaria(){
    int n=4, result;

    result=superFatorial(n);

    printf("%d\n", result);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
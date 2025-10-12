/*faça uma função recursiva soma que, dados dois números inteiros não negativos a e b, retorne a +
b, usando apenas as operações mais simples de incrementar 1.*/

#include <stdio.h>

int soma(int a, int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    return soma(a-1,b+1);
}

int funcaoSecundaria(){
    int a, b, somaTotal;

    printf("Forneça os valores a e b: ");
    scanf("%d %d", &a, &b);

    somaTotal=soma(a,b);

    printf("\n%d + %d = %d\n", a, b, somaTotal);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
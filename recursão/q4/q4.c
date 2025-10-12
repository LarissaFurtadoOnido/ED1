/*Escreva uma função recursiva que recebe inteiros não negativos m e n e calcule A(m,n).

A(m,n):= n+1                 se m=0
         A(m-1,1)            se m > 0 e n = 0
         A(m-1, A(m, n-1)))  se m,n>0
*/

#include <stdio.h>

int funcaoAckerman(int m, int n){
    if(m == 0)
        return n+1;
    if(m > 0 && n == 0)
        return funcaoAckerman(m-1, 1);
    if(m > 0 && n > 0)
        return funcaoAckerman(m-1, funcaoAckerman(m, n-1));
}

int funcaoSecundaria(){
    int m, n, valorFinal;

    printf("Forneça dois valores: ");
    scanf("%d %d", &m, &n);

    valorFinal=funcaoAckerman(m,n);

    printf("\nA(%d, %d) = %d\n", m, n, valorFinal);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
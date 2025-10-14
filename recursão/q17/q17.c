/*A multiplicação de dois números inteiros pode ser feita através de somas sucessivas. Escreva uma
função recursiva multiplica(n1,n2) que calcule a multiplicação de dois inteiros.*/

#include <stdio.h>

int multiplica(int n1, int n2){
    if(n2==0)
        return 0;
    
    return n1 + multiplica(n1, n2-1);
}

int funcaoSecundaria(){
    int n1, n2, mult;

    printf("Forneça os valores: ");
    scanf("%d %d", &n1, &n2);

    mult=multiplica(n1, n2);

    printf("%d x %d = %d\n", n1, n2, mult);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
/*Implemente uma função recursiva Dec2Bin que dado um número decimal imprima a sua
representação binária corretamente.*/

#include <stdio.h>

int Dec2Bin(int decimal){
    if(decimal == 0)
        return 0;
    
    return (decimal % 2) + 10 * Dec2Bin(decimal/2);
}

int funcaoSecundaria(){
    int decimal, binario;

    printf("Forneça um número decimal: ");
    scanf("%d", &decimal);

    binario=Dec2Bin(decimal);

    printf("%d = %d \n", decimal, binario);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
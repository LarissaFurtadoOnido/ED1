/*Implemente uma função, recursiva, para calcular a soma dos elementos de uma matriz 4x5 de
inteiros.*/

#define LINHA 4
#define COLUNA 5

#include <stdio.h>

int somaMatriz(int matriz[LINHA][COLUNA], int lin, int col){
    if(lin >= LINHA)
        return 0;
    
    if(col >= COLUNA)
        return somaMatriz(matriz, lin+1, 0);
    
    return matriz[lin][col]+somaMatriz(matriz, lin, col+1);
}

int funcaoSecundaria(){
    int matriz[LINHA][COLUNA]= {1,2,3,4,5,
                                6,7,8,9,10,
                                11,12,13,14,15,
                                16,17,18,19,20};
    
    int somaFinal;

    somaFinal=somaMatriz(matriz, 0, 0);

    printf("Soma da matriz = %d\n", somaFinal);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
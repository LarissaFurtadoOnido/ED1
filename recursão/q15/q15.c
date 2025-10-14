/*Implemente uma função que calcule o o maior e o menor valor em um vetor de inteiros.*/

#define TAMANHO 4

#include <stdio.h>

void maiorMenorValor(int *vetor, int indice, int *maior, int *menor){
    
    if(indice>=TAMANHO){
        printf("Maior=%d Menor=%d\n", *maior, *menor);
        return;
    }else{
        if(vetor[indice]>(*maior))
            (*maior)=vetor[indice];
        else if(vetor[indice]<(*menor))
            (*menor)=vetor[indice];

        maiorMenorValor(vetor, indice+1, maior, menor);
        
    }       
}

int funcaoSecundaria(){
    int vetor[TAMANHO] = {1,2,3,4}, maior=vetor[0], menor=vetor[0];

    maiorMenorValor(vetor, 0, &maior, &menor);

    return 0;
}

int main(){
    return funcaoSecundaria();
}
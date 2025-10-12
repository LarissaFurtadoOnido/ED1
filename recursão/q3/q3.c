/*Implemente a pesquisa binária de forma recursiva. Considere um vetor de inteiros como
conjunto de busca.*/

#include <stdio.h>

int buscaBinaria(int *vetor, int esq, int dir, int num){
    int meio;
    meio = (esq+dir)/2;
    if(esq>dir)
        return -1;

    if(vetor[meio]==num)
        return meio;
    if(num < vetor[meio])
        return buscaBinaria(vetor, esq, meio-1, num);
    
    return buscaBinaria(vetor, meio+1, dir, num);
}

int manipulaVetor(){
    int vetor[]={2,4,6,8,10,12,14,16,18,20}, tamanho, num, posicao;

    tamanho = sizeof(vetor)/sizeof(vetor[0]);
    num = 16;

    posicao=buscaBinaria(vetor, 0, tamanho-1, num);

    if(posicao==-1)
        printf("Valor não encontrado!");
    else
        printf("A posição do valor %d é %d.\n", num, posicao);

    return 0;
}

int main(){
    return manipulaVetor();
}
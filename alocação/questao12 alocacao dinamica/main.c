/*Implemente um programa que leia dois números inteiros, m e n, representando, respectivamente, o
número de linhas e de colunas de uma matriz. Em seguida, aloque dinamicamente uma matriz de
inteiros com m linhas e n colunas. Solicite que o usuário preencha todos os elementos da matriz. Após o
preenchimento, exiba o conteúdo em formato tabular (semelhante a uma tabela).
Ao final, libere corretamente toda a memória alocada. */

#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int m, int n){
    int **matriz, i;
    
    matriz=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
        matriz[i]=(int*)malloc(n*sizeof(int));
    
    return matriz;
}

void desalocaMatriz(int **matriz, int tamanho){
    int i;
    for(i=0;i<tamanho;i++)
        free(*(matriz+i));
    free(matriz);
}

void imprimirMatriz(int **matriz, int m, int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void preencherMatriz(int **matriz, int m, int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Forneça o %do. valor da posição %dx%d: ", i+1, i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
            
    }
}

int manipularMatriz(){
    int **matriz, m, n;
    
    printf("Forneça a quatidade de linhas: ");
    scanf("%d", &m);
    printf("Forneça a quatidade de colunas: ");
    scanf("%d", &n);
    
    matriz=alocaMatriz(m, n);
    preencherMatriz(matriz, m, n);
    imprimirMatriz(matriz, m, n);
    desalocaMatriz(matriz, m);
    
    return 0;
}

int main()
{
    return manipularMatriz();
}
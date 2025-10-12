/*Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma matriz de
ordem m x n (linha por coluna), usando 1+m chamadas a função malloc. Agora, aproveite este
programa para construir uma função que recebendo os parâmetros m e n aloque uma matriz de
ordem m x n e retorne um ponteiro para esta matriz alocada. Crie ainda uma função para liberar a
área de memória alocada pela matriz. Finalmente, crie um novo programa (main) que teste/use as
duas funções criadas acima.*/

#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int m, int n){
    int i, **matriz;
    matriz=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++){
        matriz[i]=(int*)malloc(n*sizeof(int));
    }
    
    return matriz;
}

void desalocaMatriz(int **matriz, int m){
    int i;
    for(i=0;i<m;i++){
        free(matriz+i);
    }
    free(matriz);
}

void imprimirMatriz(int **matriz, int m, int n){
    int i,j;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void manipulaMatriz(){
    int **matriz, i, j, m, n;
    
    printf("Forneça a quantidade de linhas: ");
    scanf("%d", &m);
    printf("Forneça a quantidade de colunas: ");
    scanf("%d", &n);
    
    matriz=alocaMatriz(m, n);
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Forneça o %do. valor da matriz da linha %d coluna %d: ", i+1, m, n);
            scanf("%d", &matriz[i][j]);
        }   
    }
    
    imprimirMatriz(matriz, m, n);
    desalocaMatriz(matriz, m);
}

int main()
{
    manipulaMatriz();

    return 0;
}
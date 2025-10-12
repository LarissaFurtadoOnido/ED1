/*Faça um programa que leia um número inteiro n, representando a quantidade de elementos que
serão armazenados. Em seguida, aloque dinamicamente um vetor capaz de armazenar n inteiros.
O programa deve solicitar que o usuário digite os valores um a um, preenchendo todo o vetor. Após
a leitura, exiba todos os elementos armazenados na tela, na mesma ordem em que foram digitados.
Por fim, libere corretamente a memória alocada. */

#include <stdio.h>
#include <stdlib.h>

int *alocaVetorInteiro(int n){
    int *vetor;
    printf("\t\nMemória alocada....... \n");
    vetor=(int*)malloc(n*sizeof(int));
    
    return vetor;
}

void desalocaVetor(int *vetor){
    printf("\t\nMemória liberada....... \n");
    free(vetor);
}

void imprimirVetor(int *vetor, int n){
    int i;
    printf("\t\nImprimindo o vetor....... \n");
    for(i=0;i<n;i++){
        printf("%d ", *(vetor+i));
    }
}

void preencherVetor(int *vetor, int n){
    int i;
    printf("\t\nPreenchendo o vetor....... \n");
    for(i=0;i<n;i++){
        printf("Forneça o %do. elemento: ", i+1);
        scanf("%d", (vetor+i));
    }
}

void manipulaVetor(){
    int *vetor, n;
    
    printf("Forneça a quantidade de elementos que deseja adicionar: ");
    scanf("%d", &n);
    
    vetor=alocaVetorInteiro(n);
    
    preencherVetor(vetor, n);
    imprimirVetor(vetor, n);
    desalocaVetor(vetor);
    
}

int main()
{
    manipulaVetor();

    return 0;
}

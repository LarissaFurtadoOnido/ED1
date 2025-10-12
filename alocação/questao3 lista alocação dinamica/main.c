/*Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e
retorneum ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima
os n elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e
libere esta área de memória. Ao final, crie uma função principal que leia um valor n e chame a
função criada acima. Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação.*/


#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int n){
    int *vetor;
    vetor = malloc(n*sizeof(int));
    
    return vetor;
}

void desalocaVetor(int *vetor){
    free(vetor);
}

void imprimirVetor(int *vetor, int n){
    int i;
    
    for(i=0;i<n;i++)
        printf("%d ", *(vetor+i));
    
}

void manipulaVetor(){
    int *vetor, n, i;
    
    printf("Forneça o tamanho do vetor: ");
    scanf("%d", &n);
    
    vetor=alocaVetor(n);
    
    for(i=0; i<n; i++){
        printf("Forneça o %do. número", i+1);
        scanf("%d", &vetor[i]);
    }
    
    printf("\n");
    
    imprimirVetor(vetor, n);
    desalocaVetor(vetor);
}

int main()
{
    manipulaVetor();
    return 0;
}
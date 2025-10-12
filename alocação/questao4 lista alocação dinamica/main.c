/*Faça um laço de entrada de dados, onde o usuário deve digitar uma sequência de números, sem
limite de quantidade de dados a ser fornecida. O usuário irá digitar os números um a um, sendo que
caso ele deseje encerrar a entrada de dados, ele irá digitar o número Zero. No final, todos os dados
digitados deverão ser salvos em um arquivo texto em disco. Atenção: os dados devem ser
armazenados na memória deste modo... faça com que o programa inicie criando um ponteiro para
um bloco (vetor) de 10 valores inteiros, e alocando dinamicamente espaço em memória para este
bloco; após, caso o vetor alocado esteja cheio; aloque um novo vetor do tamanho do vetor anterior
adicionado com espaço para mais 10 valores (tamanho N+10, onde N inicia com 10), copie os
valores já digitados da área inicial para esta área maior e libere a memória da área inicial; repita
este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o
mesmo estiver cheio. Assim o vetor irá ser “expandido” de 10 em 10 valores. Usar a função
malloc para alocar memória de forma dinâmica.
*/

#include <stdio.h>
#include <stdlib.h>

#define AUMENTA 5

//aloca o vetor incial, de tamanho 10
int* alocaVetor(int n){
    int *vetor;
    vetor=(int*)malloc(n*sizeof(int));
    
    return vetor;
}

//liberar memória
void desalocaVetor(int *vetor){
    free(vetor);
}

int * realocarMemoriaVetor(int *vetor, int n){
    int *novo, i;
    novo=(int*)malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)
        novo[i]=vetor[i];
        
    desalocaVetor(vetor);
    
    return novo;
}

void imprimirVetor(int *vetor, int n){
    int i;
    
    for(i=0;i<n;i++){
        printf("%d ", *(vetor+i));
    }
}

void manipulaVetor(){
    int *vetor, i=0, num, n=AUMENTA;
    
    vetor=alocaVetor(n);
    
    do{
        printf("Forneça um número ou digite 0 para sair: ");
        scanf("%d", &num);
        
        if(num!=0){
            *(vetor+i)=num;
            i++;
            
            if((i-1)==n){
                n+=AUMENTA;
                vetor=realocarMemoriaVetor(vetor, n);
            }
        }
        
    }while(num!=0);
    
    imprimirVetor(vetor, n);
    desalocaVetor(vetor);
}

int main()
{
    manipulaVetor();
    return 0;
}

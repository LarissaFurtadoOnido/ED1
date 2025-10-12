/*Implemente um programa que permita ao usuário cadastrar quantos números inteiros desejar, sem
que o tamanho do vetor seja previamente conhecido. Para isso, utilize a função realloc para
expandir o vetor a cada nova inserção. O processo de inserção continua indefinidamente até que o
usuário digite o valor -1, que deve ser tratado como sentinela de parada (não deve ser armazenado
no vetor). Ao final, exiba todos os números cadastrados na ordem em que foram inseridos e libere a
memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

int *realocarVetor(int tamanho){
    int *vetor;
    vetor=(int*)realloc(vetor, (tamanho+1)*sizeof(int));
    
    return vetor;
}

void desalocaVetor(int *vetor){
    printf("\t\t\n\nMemória liberada\n");
    free(vetor);
}

void imprimirVetor(int *vetor, int tamanho){
    int i;
    printf("\t\t\nImprimindo vetor\n");
    
    for(i=0;i<tamanho;i++){
        printf("%d ", *(vetor+i));
    }
}

void manipulaVetor(){
    int *vetor, num, i=0;
    
    do{
        vetor=realocarVetor(i);
        printf("Forneça um número inteiro ou digite -1 para sair: ");
        scanf("%d", &num);
        
        if(num!=-1){
            *(vetor+i)=num;
            i++;
        }
        
    }while(num!=-1);
    
    imprimirVetor(vetor, i);
    desalocaVetor(vetor);
}

int main()
{
    manipulaVetor();

    return 0;
}

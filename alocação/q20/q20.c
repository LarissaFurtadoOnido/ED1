/*Escreva um programa que leia n números inteiros e os armazene em um vetor alocado dinamicamente.
Em seguida, crie um novo vetor comprimido, armazenando cada número junto com a quantidade de
vezes consecutivas em que ele aparece. Exemplo:
Entrada → 5 5 5 2 2 7 7 7 7
Saída → [5,3, 2,2, 7,4]
O vetor comprimido deve crescer dinamicamente usando realloc, de acordo com os dados
processados. Exiba o vetor comprimido e libere a memória ao final.*/

#include <stdio.h>
#include <stdlib.h>

int *contagemDigitos(int *n, int tamanho){
    int *saida, k, i, aux, cont=0;

    for(i=0;i<tamanho;i++){
        aux=n[i];
        for(k=0;k<tamanho;k++){
            if(k==0)
                saida=(int*)malloc(cont+1*sizeof(int));
            else{
                saida=(int*)realloc(saida, cont*sizeof(int));
            }
            if(aux==n[k]){
                saida[k]=n[k];
                saida[k+1]=cont++;
            }
            
        }
    }
    return saida;
}

int funcaoSecundaria(){
    int *n, i=0, *result, num;

    do{
        printf("Forneça um número (ou digite 0 para sair): ");
        scanf("%d", &num);
        if(num!=0){
            if(i==0){
                n=(int*)malloc(i+1*sizeof(int));
                n[i]=num;
            }else{
                i++;
                n=(int*)realloc(n, i*sizeof(int));
                n[i]=num;
            }
        }
    }while(num!=0);

    result=contagemDigitos(n, i);
    
    int k;
    for(k=0;k<i;k++)
        printf("%d ", result[k]);

    free(saida);
    free(result);
    return 0;
}

int main(){
    return funcaoSecundaria();
}
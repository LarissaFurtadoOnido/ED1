/*Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um
número natural N. Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>
#include <stdlib.h>

char * alocaVetor(int tamanho){
    char *str;
    str=(char *)malloc(tamanho*sizeof(char));

    return str;
}

void desalocaVetor(char *str){
    free(str);
}

char *converteInteiroParaString(int n){
    char *numString;
    int copia=n, cont=0;
    
    do{
        copia/=10;
        cont++;
    }while(copia>0);

    numString=alocaVetor(cont);

    sprintf(numString, "%d", n);

    return numString;
}

int contagemDigitos(char *n, int k, int indice){
    if(n[indice] == '\0')
        return 0;

    if(n[indice] == k + '0')
        return 1 + contagemDigitos(n, k, indice+1);

    return contagemDigitos(n, k, indice+1);
}

int funcaoSecundaria(){
    char *numString;
    int digito, result, n;

    printf("Forneça um número natural: ");
    scanf("%d", &n);
    numString=converteInteiroParaString(n);
    printf("Forneça o dígito que deseja pesquisar: ");
    scanf("%d", &digito);

    result = contagemDigitos(numString, digito, 0);
    
    printf("O dígito %d ocorre %d vezes\n", digito, result);

    desalocaVetor(numString);
    return 0;
}

int main(){
    return funcaoSecundaria();
}


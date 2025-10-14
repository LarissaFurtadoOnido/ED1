/*Crie uma função recursiva que receba um número inteiro positivo e retorne a soma de seus dígitos.
Exemplo: 1234 = 10*/

#include <stdio.h>
#include <stdlib.h>

char *alocaVetor(int tamanho){
    char *str;
    str=(char *)malloc(tamanho*sizeof(char));

    return str;
}

char desalocaVetor(char *str){
    free(str);
}

char * converteInteiroParaString(int n){
    int aux = n, cont = 0;
    char *numString;

    do{
        aux/=10;
        cont++;
    }while(aux>0);

    numString=alocaVetor(cont);

    sprintf(numString, "%d", n);

    return numString;
}

int somaDigitos(char *numString, int indice){
    if(numString[indice] == '\0')
        return 0;
    
    return (numString[indice] - '0') + somaDigitos(numString, indice+1);
}

int funcaoSecundaria(){
    int n, result;
    char *numString;

    printf("Forneça um número: ");
    scanf("%d", &n);

    numString=converteInteiroParaString(n);

    result = somaDigitos(numString, 0);

    printf("A soma dos dígitos do número %d = %d\n", n, result);

    desalocaVetor(numString);

    return 0;
}

int main(){
    return funcaoSecundaria();
}

/*Escreva um programa que leia do usuário uma palavra (sem espaços). Após a leitura, aloque
dinamicamente uma área de memória com o tamanho exato necessário para armazenar a palavra,
incluindo o caractere terminador '\0'. Copie o conteúdo da string para essa nova área e exiba a
palavra copiada. Libere a memória ao final. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void retiraEnter(char *s){
    s[strcspn(s, "\n")]='\0';
}

void converteMaiuscula(char *s, int tamanho){
    int i;
    
    for(i=0;i<tamanho;i++)
        s[i]=toupper(s[i]);
}

char *alocaVetorPalavra(int tamanho){
    char *vetor;
    vetor=(char *)malloc(tamanho*sizeof(char));
    
    return vetor;
}

void desalocaVetorPalavra(char *vetor){
    printf("\t\nMemória liberada\n");
    free(vetor);
}

void imprimirVetorPalavra(char *vetor, int tamanho){
    int i;
    
    printf("\t\nImprimindo\n");
    for(i=0;i<tamanho;i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}

int manipulaVetorPalavra(){
    char *vetor, palavra[100];
    int tamanho;
    
    printf("Forneça uma palavra: ");
    fgets(palavra, 100, stdin);
    setbuf(stdin, NULL);
    
    retiraEnter(palavra);
    tamanho=strlen(palavra);
    converteMaiuscula(palavra, tamanho);
    
    vetor=alocaVetorPalavra(tamanho);
    
    strcpy(vetor, palavra);
    
    imprimirVetorPalavra(vetor, tamanho);
    desalocaVetorPalavra(vetor);
    
    return 0;
}

int main(){
    return manipulaVetorPalavra();}

/*Faça um programa que permita ao usuário cadastrar vários nomes de pessoas.
Cada nome deve ser armazenado em uma área de memória alocada dinamicamente, de forma que o
espaço utilizado seja exatamente o necessário para guardar o nome. Além disso, mantenha todos os
ponteiros para os nomes em um vetor dinâmico de ponteiros, que também deve crescer conforme novos
nomes forem adicionados. Ao término do cadastro (por exemplo, quando o usuário digitar a palavra
"fim"), exiba todos os nomes cadastrados e, em seguida, libere a memória utilizada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpaEnter(char *s){
    s[strcspn(s, "\n")]='\0';
}

void conveterMaiuscula(char *s, int tamanho){
    int i;
    
    for(i=0;i<tamanho;i++)
        s[i]=toupper(s[i]);
}

void imprimirMatriz(char **matriz, int quantnomes){
    int i;
    for(i=0;i<quantnomes;i++){
        printf("%s\n", matriz[i]);
    }
}

void desalocaMatriz(char **matriz, int m){
    int i;
    for(i=0;i<m;i++){
        free(*(matriz+i));
    }
    free(matriz);
}

void manipulaMatrizNomes(){
    int i=0, tamanho;
    char nome[100], **matrizNomes=NULL;
    
    do{
        matrizNomes=(char **)realloc(matrizNomes, (i+1)*sizeof(char *));
        
        printf("Forneça um nome ou digite FIM para sair: ");
        fgets(nome, 100, stdin);
        
        limpaEnter(nome);
        tamanho=strlen(nome);
        conveterMaiuscula(nome, tamanho);
        
        if(strcmp(nome, "FIM")!=0){
             //coluna
            matrizNomes[i]=(char *)malloc((tamanho+1)*sizeof(char));
            
            strcpy(matrizNomes[i], nome);
            
            i++;
        }
        
    }while(strcmp(nome, "FIM")!=0);
    
    imprimirMatriz(matrizNomes, i);
    desalocaMatriz(matrizNomes, i);
}

int main(){
    
    manipulaMatrizNomes();

    return 0;
}
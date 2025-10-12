/*Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[100];
    int data;
    char cpf[12];
}TPessoa;

TPessoa *alocaVetor(TPessoa *pessoa, int n){
    TPessoa *vetor;
    
    vetor=realloc(pessoa, n*sizeof(TPessoa));
    
    return vetor;
}

void imprimirVetorDados(TPessoa *pessoa, int tamanho){
    int i;
    
    for(i=0;i<tamanho;i++){
        printf("\n\tNome: %s ", pessoa[i].nome);
        printf("\tCPF: %s",  pessoa[i].cpf);
        printf("\tData de nascimento: %d\n",  pessoa[i].data);
    }
}

int manipularVetorDados(){
    TPessoa *pessoa=NULL;
    int sair, i=0;
    
    do{
        pessoa = alocaVetor(pessoa, i + 1);
        
        setbuf(stdin, NULL);
        printf("Forneça o nome: ");
        fgets(pessoa[i].nome, 100, stdin);
        
        
        printf("Forneça data de nascimento: DD/MM/AAAA: ");
        scanf("%d", &pessoa[i].data);
        
        
        printf("Forneça o cpf: ");
        fgets(pessoa[i].cpf, 12, stdin);
        
        printf("Deseja sair? \n1-Sim\n2-Não");
        scanf("%d", &sair);
        
        i++;
        
        getchar();
    }while(sair!=1);
    
    imprimirVetorDados(pessoa, i);
    
    free(pessoa);
    
    return 0;
}

int main()
{
    return manipularVetorDados();
}

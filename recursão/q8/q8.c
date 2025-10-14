/*faça uma função recursiva para verificar se uma expressão (string) de parênteses é bem
formada.*/

#include <stdio.h>

int stringParenteses(char *parenteses, int aberto, int posicao){
    if(parenteses[posicao]=='\0')
        return aberto == 0;
    if(aberto<0)
        return 0;
    
    if(parenteses[posicao] == '(')
        aberto++;
    else if(parenteses[posicao] == ')')
        aberto--;
    
    return stringParenteses(parenteses, aberto, posicao+1);
}

int funcaoSecundaria(){
    char parenteses[]="((()))";
    int result;

    result=stringParenteses(parenteses, 0, 0);

    if(result == 0)
        printf("A expressão nao está bem formatada\n");
    else
        printf("Supimpa!\n");

    return 0;
}

int main(){
    return funcaoSecundaria();
}
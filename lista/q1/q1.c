#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

lista criaLista(){
    lista l;
    l=(lista)malloc(sizeof(TLista));

    if(l){
        l->inicio=NULL;
        l->fim=NULL;
        l->tamanho=0;
    }

    return l;
}

void terminaLista(lista l){
    TNodo *ptr;

    while(l->inicio){
        ptr=l->inicio;
        l->inicio=ptr->next;
        free(ptr);
    }
    l->tamanho--;
    free(l);
}

//retorna 0 para elemento inserido com sucesso, caso contrario retorna 1
int inserirNovoItemInicioLista(lista l, TElemento e){
    TNodo *ptr;

    ptr=malloc(sizeof(TNodo));

    if(ptr){
        ptr->info=e;
        ptr->next=l->inicio;
        l->inicio=ptr;

        if(listaVazia(l)==1)
            l->fim=ptr;
        
        l->tamanho++;
        return 0; 
    }
    return 1;
}

int removerItemLista(lista l, TElemento *e){
    TNodo *ptr, *aux;

    ptr=l->inicio; //para que possa percorrer a lista
    while(ptr){
        if(ptr->info==e){
            if(ptr==l->inicio)
                l->inicio=ptr->next;

            else if(ptr==l->fim){
                l->fim=aux;
                l->fim->next=NULL;
            }else
                aux->next=ptr->next;
            
            l->tamanho--;
            free(ptr);
            return 0;
        }

    }
    
    return 1;
}

int listaCheia(lista l){
    TNodo *ptr;

    ptr=malloc(sizeof(TNodo));

    if(ptr){
        free(ptr);
        return 0;
    }

    return 1;
}

int listaVazia(lista l){
    return l->tamanho==0;
}


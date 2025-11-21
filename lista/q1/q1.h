typedef int TElemento;

typedef struct Nodo{
    TElemento info;
    struct Nodo *next;
}TNodo;

typedef struct{
    TNodo *inicio, *fim;
    int tamanho;
}TLista;

typedef TLista *lista;

lista criaLista();
void terminaLista(lista l);
int inserirNovoItemInicioLista(lista l, TElemento e);
int removerItemLista(lista l, TElemento *e);
int listaCheia(lista l);
int listaVazia(lista l);

lista inverteElementos(lista l);
int verificaOrdemLista(lista l);
int inserirNovoItemPosicaoLista(lista l, TElemento e);


#include <stdio.h>
#include <stdlib.h>
#include "acme.h"

struct elemento{
    CLIENTE dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;


// FUNÇÃO QUE CRIA A LISTA
Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

// PROCEDIMENTO DE ABORTAR O PROGRAMA EM CASO DE ERROS
void abortaPrograma(){
    printf("ERRO! Lista não foi alocada\n");
    printf("O programa será encerrado...\n\n");
    system("pause");
    exit(1);
}

// FUNÇÕES VERIFICADORAS
int tamanhoLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaCheia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

// OPÇÃO 1 - INSERIR CLIENTE
int insereOrdenado(Lista *li, CLIENTE cl){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = cl;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return cl.ID;
    }
    else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.ID < cl.ID){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return cl.ID;
    }
}

// OPÇÃO 3 - CONSULTAR POR ID
int consultaID(Lista *li, int ID, CLIENTE *cl){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.ID != ID){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *cl = no->dados;
        return 1;
    }
}

// OPÇÃO 6 - REMOVER CONTATO POR ID
int removeOrdenado(Lista *li, int ID){
    int ID;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *ant, *no = *li;

    while(no != NULL && no->dados.ID != ID){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    ID = no->dados.ID;
    free(no);
    return ID;
}

// OPÇÃO 7 - SALVAR DADOS E APAGAR A LISTA
void apagaLista(Lista *li){

    // FALTA FAZER A LÓGICA E SALVAR OS DADOS NO ARQUIVO EM BINÁRIO AQUI

    if(li!= NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

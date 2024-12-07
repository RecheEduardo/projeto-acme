#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
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
    printf("\n\tERRO! Lista não foi alocada\n");
    printf("\n\tO programa será encerrado...\n\n");
    system("pause");
    exit(1);
}

// PROCEDIMENTO DE EXIBIR AS OPÇÕES DO PROGRAMA NA TELA
void exibeMenu(){
        printf("\t========================================\n\n");
        printf("\tOPÇÃO 1 - INSERIR CLIENTE\n\n");
        printf("\tOPÇÃO 2 - EXIBIR LISTA COMPLETA\n\n");
        printf("\tOPÇÃO 3 - EXIBIR CONTATO\n\n");
        printf("\tOPÇÃO 4 - BUSCAR CLIENTE POR NOME\n\n");
        printf("\tOPÇÃO 5 - EDITAR CONTATO\n\n");
        printf("\tOPÇÃO 6 - REMOVER CONTATO\n\n");
        printf("\tOPÇÃO 7 - SALVAR E SAIR\n\n");
        printf("\t========================================\n\n");
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

// FUNÇÃO QUE RETORNA O CLIENTE CRIADO
CLIENTE coletaDados(){

    CLIENTE cl;

    printf("\n\n\tInserindo novo contato:\n\n");
    printf("\n\tID: ");
    scanf("%d", &cl.ID);
    getchar();

    printf("\n\tNome: ");
    fgets(cl.nomeCliente, sizeof(cl.nomeCliente), stdin);
    strtok(cl.nomeCliente, "\n");

    printf("\n\tEmpresa: ");
    fgets(cl.nomeEmpresa, sizeof(cl.nomeEmpresa), stdin);
    strtok(cl.nomeEmpresa, "\n");

    printf("\n\tDepartamento: ");
    fgets(cl.departamento, sizeof(cl.departamento), stdin);
    strtok(cl.departamento, "\n");

    printf("\n\tTelefone Fixo: ");
    fgets(cl.telefoneFixo, sizeof(cl.telefoneFixo), stdin);
    strtok(cl.telefoneFixo, "\n");

    printf("\n\tTelefone Celular: ");
    fgets(cl.telefoneCelular, sizeof(cl.telefoneCelular), stdin);
    strtok(cl.telefoneCelular, "\n");

    printf("\n\tEmail: ");
    fgets(cl.email, sizeof(cl.email), stdin);
    strtok(cl.email, "\n");

    return cl;
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
    int clienteID;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *ant, *no = *li;

    while(no != NULL && no->dados.ID != clienteID){
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
    clienteID = no->dados.ID;
    free(no);
    return clienteID;
}


// OPÇÃO 7 - SALVAR DADOS E APAGAR A LISTA
void salvarContatos(Lista *li){
    // FALTA FAZER A LÓGICA E SALVAR OS DADOS NO ARQUIVO EM BINÁRIO AQUI
}

void apagaLista(Lista *li){
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

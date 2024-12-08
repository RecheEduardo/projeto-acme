#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "acme.h"

int main()
{
    Lista *li = NULL;

    int x, opcao, id;

    CLIENTE cl;

    setlocale(LC_ALL, "Portuguese");

    li = criaLista();
    if(li == NULL){
        abortaPrograma();
    }

    ////////////////////////

    printf("\n\t--------- SISTEMA INTEGRADO DA EMPRESA ACME ---------\n\n");
    printf("\n\tProjeto de Eduardo Reche Martins e Diego Rocha Vitali\n\n");
    do {
        exibeMenu();
        printf("\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cl = coletaDados();
                x = insereOrdenado(li, cl);
                if(x){
                    printf("\n\t========================================\n\n");
                    printf("\tCliente de numero %d incluido com sucesso!\n\n" , x);
                }else{
                    printf("\n\tERRO! Cliente nao foi inserido...\n\n");
                }
                break;
            case 2:
                exibirListaCompleta(li);
                break;

            case 3:
                printf("\n\tDigite o ID do cliente que deseja consultar: ");
                scanf("%d" , &id);
                getchar();
                x = consultaID(li, id, &cl);
                if(x) {
                    printf("\n\t========================================\n\n");
                    exibirDadosCliente(&cl);
                }else{
                    printf("\n\t========================================\n\n");
                    printf("\tERRO! Cliente inexistente...\n\n");
                }
                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:
                apagaLista(li);
                break;

            default:
                printf("\n\n\n\tOpcao Invalida!\n\n");
        }

    } while (opcao != 7);

    return 0;
}



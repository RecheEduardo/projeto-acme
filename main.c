#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "acme.h"

int main()
{
    Lista *li = NULL;

    int x, opcao;

    CLIENTE cl;

    setlocale(LC_ALL, "Portuguese");

    if(li = criaLista() == NULL){
        abortaPrograma();
    }

    printf("\n\tSISTEMA INTEGRADO DA EMPRESA ACME�\n\n");
    printf("\n\tProjeto de Eduardo Reche Martins e Diego Rocha Vitali\n\n");
    do {
        exibeMenu();
        printf("\tEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cl = coletaDados();
                x = insereOrdenado(li, cl); // por algum motivo ta dando erro aqui
                if(x){
                    printf("Cliente de numero %d incluido com sucesso!" , x);
                }else{
                    printf("ERRO! Cliente não foi inserido...");
                }
                break;
            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            case 7:

                break;

            default:
                printf("\n\n\n\tOpção Inválida!\n\n");
        }

    } while (opcao != 7);

    return 0;
}



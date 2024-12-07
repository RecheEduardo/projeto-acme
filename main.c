#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "acme.h"

int main()
{
    int opcao;
    setlocale(LC_ALL, "Portuguese");

    printf("\n\tSISTEMA INTEGRADO DA EMPRESA ACME®\n\n");
    printf("\n\tProjeto de Eduardo Reche Martins e Diego Rocha Vitali\n\n");
    do {
        printf("\t========================================\n\n");
        printf("\tOPÇÃO 1 - INSERIR CLIENTE\n\n");
        printf("\tOPÇÃO 2 - EXIBIR LISTA COMPLETA\n\n");
        printf("\tOPÇÃO 3 - EXIBIR CONTATO\n\n");
        printf("\tOPÇÃO 4 - BUSCAR CLIENTE POR NOME\n\n");
        printf("\tOPÇÃO 5 - EDITAR CONTATO\n\n");
        printf("\tOPÇÃO 6 - REMOVER CONTATO\n\n");
        printf("\tOPÇÃO 7 - SALVAR E SAIR\n\n");
        printf("\t========================================\n\n");
        printf("\tEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            default:
                printf("bunda");
        }

    } while (opcao != 7);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "acme.h"

int main()
{
    int opcao;
    setlocale(LC_ALL , "Portuguese");

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

    } while (opcao != 7);
    return 0;
}

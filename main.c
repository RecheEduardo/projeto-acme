#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "acme.h"

// Eduardo Reche Martins - GU3054209
// Diego Rocha Vitali - GU3053873

int main()
{
    Lista *li = NULL;
    FILE *f1;

    int x, opcao, id;
    char nome[80];

    CLIENTE cl;

    setlocale(LC_ALL, "Portuguese");

    li = criaLista();

    // Abrir Arquivo Binario e Verificar se ja existe dados salvos
    f1 = fopen("clientes.bin", "rb");
    if (f1 == NULL) {
        printf("\n\t================================================================\n");
        printf("\tArquivo 'clientes.bin' nao encontrado. Um novo arquivo sera criado ao salvar.\n");
        printf("\t================================================================\n");
    } else {
        carregarDados(f1, li);
        fclose(f1);
    }
    if(li == NULL){
        abortaPrograma();
    }

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
                //Verifica Duplicidade antes de Inserir na Lista
                id = cl.ID;
                x = consultaID(li, id, &cl);
                if(x){
                    printf("\n\t========================================\n\n");
                    printf("\tERRO! ID de Cliente ja cadastrado...\n\n");
                    break;
                }
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
                printf("\n\tDigite o nome do cliente buscado: ");
                fgets(nome, sizeof(nome), stdin);
                printf("\n");
                strtok(nome, "\n");
                x = consultaNome(li, nome);
                printf("\n\tNumero total de clientes encontrados: %d\n\n" , x);
                break;

            case 5:
                printf("\n\tDigite o ID do cliente que deseja editar: ");
                scanf("%d" , &id);
                getchar();
                printf("\n");
                x = editarCliente(li, id);
                if(x){
                    printf("\n\t========================================\n\n");
                    printf("\tCliente %d editado com sucesso!\n\n" , x);
                }else{
                    printf("\n\tERRO! Cliente nao foi editado...\n\n");
                }
                break;

            case 6:
                printf("\n\tDigite o ID do cliente que deseja remover: ");
                scanf("%d" , &id);
                getchar();
                x = removeOrdenado(li, id);
                if(x){
                    printf("\n\t========================================\n\n");
                    printf("\tCliente %d removido com sucesso!\n\n" , x);
                }else{
                    printf("\n\tERRO! Cliente nao foi removido...\n\n");
                }
                break;
            case 7:
                f1 = fopen("clientes.bin", "wb");
                if (f1 == NULL) {
                    printf("Erro ao abrir o arquivo para salvar os dados.\n");
                } else {
                    x = salvarClientes(f1, li);
                    if(x == 0){
                        printf("\n\tERRO AO SALVAR DADOS...\n\n");
                        break;
                    };
                    printf("\n\t========================================\n\n");
                    printf("\tDados salvos com sucesso!\n\n");
                    fclose(f1);
                    apagaLista(li);
                    break;
                }

            default:
                printf("\n\n\n\tOpcao Invalida!\n\n");
        }

    } while (opcao != 7);

    return 0;
}
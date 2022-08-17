#include <stdio.h>
#include <stdlib.h>
#include "FuncaoCadastro.h"
#include "FuncaoCaixa.h"
#include <locale.h>
#include <string.h>

/*
Pomba! Sistemas de venda
--------------------------------------------------------------------
			Versão 1.0

->Sistema baseado em texto

->Grava registros em formato de arquivos de texto
 -nome de cada arquivo possui o nome do registro e o código interno
 Ex: joao - 01234
    bolacha - 4125(código serial)
 -internamente registra informações sobre o registro
 Ex:-nome joao
    -Idade 17
    -CPF 012.226.152-25
    -telefone - 44 84621458

    Bolacha
    -código interno
    -validade

->Função de busca de registros já gravados

->função de venda baseada nos registros já inseridos

->Função de conta para cada pessoa registrada
---------------------------------------------------------------------
*/


int main()
{
    int loop1=0;
    int escolha=0;

    printf("----------------------------------------------------------\n");
    printf("Inicializando sistema...\n");
    printf("Inicializando linguagem...\n");
    setlocale(LC_ALL, "Portuguese");
    printf("----------------------------------------------------------\n");

    for(loop1=0;loop1!=-1;)
    {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("Bem vindo ao sistema Itikawa!!!\n");
        printf("----------------------------------------------------------\n");
        printf("1 - Cadastro, Busca e Edição\n");
        printf("2 - Caixa de Vendas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i", &escolha);
        fflush(stdin);

        switch(escolha)
        {
            case 1:
            //Cadastro, Busca e Edição
            printf("----------------------------------------------------------\n");
            printf("Abrindo sistema de Cadastro, Busca e Edição...\n");
            printf("----------------------------------------------------------\n");
            CadastroMenu();
            break;

            case 2:
            //Caixa de Vendas
            printf("----------------------------------------------------------\n");
            printf("Abrindo Caixa de Vendas...\n");
            printf("----------------------------------------------------------\n");
            menuVendas();
            break;

            case 3:
            //Encerrar Programa
            loop1 = -1;
            break;
        }

    }

    printf("----------------------------------------------------------\n");
    printf("O programa está encerrando! Obrigado por utilizar!!!\n");
    printf("----------------------------------------------------------\n");
    return 0;
}

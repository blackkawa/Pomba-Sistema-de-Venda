#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "header.h"

/*
POMBA SISTEMAS DE VENDA

ESTE E UM SISTEMA DE VENDA E COMPRA SIMPLES, CONTENDO UM CONTROLE DE ESTOQUE INTEGRADO

O SISTEMA POSSUI UMA TELA DE CAIXA DE VENDAS E UMA TELA DE CONTROLE DE ESTOQUE

O BANCO DE DADOS É OFFLINE, SENDO DADO POR UM ENDEREÇO DE UMA PASTA LOCAL DO SISTEMA, SENDO
DEFINIDO PELO USUÁRIO, OU USANDO O ENDEREÇO DO SISTEMA POR PADRÃO

O USUÁRIO NECESSITA DE UM LOGIN E SENHA PARA ENTRAR NO SISTEMA, SENDO ESTES DEFINIDOS
PELO ARQUIVO PRESENTE NO ENDEREÇO DA PASTA LOCAL


TERMINAR TELA LOGIN!
*/


int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);

    if(construtor_login()==FALSE)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        return 1;
    }

    gtk_main();

    return 0;
}

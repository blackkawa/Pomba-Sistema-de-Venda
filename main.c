#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "header.h"

/*
POMBA SISTEMAS DE VENDA

ESTE E UM SISTEMA DE VENDA E COMPRA SIMPLES, CONTENDO UM CONTROLE DE ESTOQUE INTEGRADO

O SISTEMA POSSUI UMA TELA DE CAIXA DE VENDAS E UMA TELA DE CONTROLE DE ESTOQUE

O BANCO DE DADOS � OFFLINE, SENDO DADO POR UM ENDERE�O DE UMA PASTA LOCAL DO SISTEMA, SENDO
DEFINIDO PELO USU�RIO, OU USANDO O ENDERE�O DO SISTEMA POR PADR�O

O USU�RIO NECESSITA DE UM LOGIN E SENHA PARA ENTRAR NO SISTEMA, SENDO ESTES DEFINIDOS
PELO ARQUIVO PRESENTE NO ENDERE�O DA PASTA LOCAL


TERMINAR TELA LOGIN!
*/


int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);

    if(construtor_login()==FALSE)
    {
        printf("Erro! Erro n� %i, do tipo: %s", errno, strerror(errno));
        return 1;
    }

    gtk_main();

    return 0;
}

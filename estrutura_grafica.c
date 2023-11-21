#include <gtk/gtk.h>
#include <stdio.h>
#include "header.h"


/*
ESTE ARQUIVO CONTEM TODAS AS DEFINIÇÕES GRÁFICAS DO PROGRAMA, COMO A ESTRUTURA DE MENUS E SINAIS
LIGADOS A ESTES.


*/

struct estrutura_memoria_login *estrutura_login;

int construtor_menuprincipal()
{
    return TRUE;
}

int construtor_menucaixa()
{
    return TRUE;
}

int construtor_menuestoque()
{
    return TRUE;
}

int construtor_login()
{
    GtkBuilder *construtor = NULL;

    if(alojar_login()==FALSE)
       {
           return FALSE;
       }

    printf("Construindo o visual da tela de login...\n\n");
    construtor = gtk_builder_new_from_file("tela_login.glade");

    printf("Averiguando a alocacao das estruturas...\n\n");
    printf("Averiguando o construtor...\n\n");
    if(construtor==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        g_object_unref(construtor);
        return FALSE;
    }

    printf("Averiguando a janela...\n\n");
    if(estrutura_login->janela_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o label_janela...\n\n");
    if(estrutura_login->label_janela==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o box_entrada_login...\n\n");
    if(estrutura_login->box_entrada_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o label_login...\n\n");
    if(estrutura_login->label_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o box_entrada_senha...\n\n");
    if(estrutura_login->box_entrada_senha==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o label_senha...\n\n");
    if(estrutura_login->label_senha==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o box_botoes...\n\n");
    if(estrutura_login->box_botoes==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o botao_esqueceu...\n\n");
    if(estrutura_login->botao_esqueceu==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o botao_login...\n\n");
    if(estrutura_login->botao_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o botao_fechar...\n\n");
    if(estrutura_login->botao_fechar==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o entrada_login...\n\n");
    if(estrutura_login->entrada_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Averiguando o entrada_senha...\n\n");
    if(estrutura_login->entrada_senha==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        desalojar_login();
        return FALSE;
    }

    printf("Criando os widgets...\n\n");
    estrutura_login->janela_login = criar_widget(estrutura_login->janela_login,construtor,"janela_login");

    estrutura_login->box_login = criar_widget(estrutura_login->box_login,construtor,"box_login");

    estrutura_login->label_janela = criar_widget(estrutura_login->label_janela,construtor,"label_janela");

    estrutura_login->box_entrada_login = criar_widget(estrutura_login->box_entrada_login,construtor,"box_entrada_login");

    estrutura_login->label_login = criar_widget(estrutura_login->label_login,construtor,"label_login");

    estrutura_login->box_entrada_senha = criar_widget(estrutura_login->box_entrada_senha,construtor,"box_entrada_senha");

    estrutura_login->label_senha = criar_widget(estrutura_login->label_senha,construtor,"label_senha");

    estrutura_login->box_botoes = criar_widget(estrutura_login->box_botoes,construtor,"box_botoes");

    estrutura_login->botao_esqueceu = criar_widget(estrutura_login->botao_esqueceu,construtor,"botao_esqueceu");

    estrutura_login->botao_login = criar_widget(estrutura_login->botao_login,construtor,"botao_login");

    estrutura_login->botao_fechar = criar_widget(estrutura_login->botao_fechar,construtor,"botao_fechar");
    g_signal_connect(estrutura_login->botao_fechar,"clicked",G_CALLBACK(desalojar_login), NULL);

    estrutura_login->entrada_login = criar_widget(estrutura_login->entrada_login,construtor,"entrada_login");

    estrutura_login->entrada_senha = criar_widget(estrutura_login->entrada_senha,construtor,"entrada_senha");

    g_object_unref(construtor);

    gtk_widget_show(estrutura_login->janela_login);


    return TRUE;
}

int construtor_configuracao()
{
    return TRUE;
}

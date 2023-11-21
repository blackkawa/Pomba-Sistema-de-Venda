#include <stdio.h>
#include <gtk/gtk.h>
#include "header.h"


/*
NESTE ARQUIVO CONSTA OS SINAIS DA ESTRUTURA GRÁFICA, E AS FUNÇÕES LIGADAS A ELES
*/

//funcao para criar os widgets a partir do construtor
GtkWidget* criar_widget(GtkWidget *objeto, GtkBuilder *construtor, char *nome)
{
    objeto = GTK_WIDGET(gtk_builder_get_object(construtor, nome));

    if(objeto==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        return NULL;
    }


    return objeto;
}

int alojar_login()
{
    printf("Alojando o login...\n\n");

    estrutura_login = malloc (sizeof (*estrutura_login));

    estrutura_login->janela_login = malloc (sizeof (*estrutura_login->janela_login));
    estrutura_login->box_login = malloc (sizeof (*estrutura_login->box_login));
    estrutura_login->label_janela = malloc (sizeof (*estrutura_login->label_janela));
    estrutura_login->box_entrada_login = malloc (sizeof (*estrutura_login->box_entrada_login));
    estrutura_login->label_login = malloc (sizeof (*estrutura_login->label_login));
    estrutura_login->box_entrada_senha = malloc (sizeof (*estrutura_login->box_entrada_senha));
    estrutura_login->label_senha = malloc (sizeof (*estrutura_login->label_senha));
    estrutura_login->box_botoes = malloc (sizeof (*estrutura_login->box_botoes));
    estrutura_login->botao_esqueceu = malloc (sizeof (*estrutura_login->botao_esqueceu));
    estrutura_login->botao_login = malloc (sizeof (*estrutura_login->botao_login));
    estrutura_login->botao_fechar = malloc (sizeof (*estrutura_login->botao_fechar));
    estrutura_login->entrada_login = malloc (sizeof (*estrutura_login->entrada_login));
    estrutura_login->entrada_senha = malloc (sizeof (*estrutura_login->entrada_senha));

    if(estrutura_login==NULL)
    {
        printf("Erro! Erro nº %i, do tipo: %s", errno, strerror(errno));
        printf("Tela de login nao alojada \n\n");
        return FALSE;
    }

    printf("Tela de login alojada \n\n");
    return TRUE;
}

void desalojar_login()
{
    gtk_widget_destroy(estrutura_login->janela_login);

    free(estrutura_login->entrada_senha);
    free(estrutura_login->entrada_login);
    free(estrutura_login->botao_fechar);
    free(estrutura_login->botao_login);
    free(estrutura_login->botao_esqueceu);
    free(estrutura_login->box_botoes);
    free(estrutura_login->label_senha);
    free(estrutura_login->box_entrada_senha);
    free(estrutura_login->label_login);
    free(estrutura_login->box_entrada_login);
    free(estrutura_login->label_janela);
    free(estrutura_login->box_login);
    free(estrutura_login->janela_login);
    free(estrutura_login);

    return;
}

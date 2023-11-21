#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*
CABEÇALHO DO PROGRAMA
*/

//estrutura_grafica
int construtor_menuprincipal();
int construtor_menucaixa();
int construtor_menuestoque();
int construtor_login();
int construtor_configuracao();
//funcoes_estrutura_grafica
GtkWidget* criar_widget(GtkWidget *objeto, GtkBuilder *construtor, char *nome);
int alojar_login();
void desalojar_login();
//funcoes_banco_dados
//funcoes_caixa
//funcoes_compravenda
//funcoes_estoque
//sistema_login
//configuracoes_sistema

struct estrutura_memoria_login
{
    GtkWidget *janela_login;
    GtkWidget *box_login;
    GtkWidget *label_janela;
    GtkWidget *box_entrada_login;
    GtkWidget *label_login;
    GtkWidget *box_entrada_senha;
    GtkWidget *label_senha;
    GtkWidget *box_botoes;
    GtkWidget *botao_esqueceu;
    GtkWidget *botao_login;
    GtkWidget *botao_fechar;
    GtkWidget *entrada_login;
    GtkWidget *entrada_senha;
};

extern struct estrutura_memoria_login *estrutura_login;

#endif // HEADER_H_INCLUDED

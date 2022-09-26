#ifndef FUNCAOCADASTRO_H_INCLUDED
#define FUNCAOCADASTRO_H_INCLUDED

#include <string.h>
#include <dirent.h>

#define LINHA_NOME 25
#define LINHA_IDADE 65
#define LINHA_CPF 103
#define LINHA_TELEFONE 86
#define LINHA_NOMEPRODUTO 19
#define LINHA_BARCODE 82
#define LINHA_VALIDADE 91


void NovoCadastro();
void BuscaCadastro();
void AlterarCadastro();
char Encapsulador_Arquivo();
char Desencapsulador_Arquivo();

//Menu principal da função Cadastro
void CadastroMenu()
{
    int loop2=0;
    int escolha2=0;

    for(loop2=0;loop2!=-1;)
    {
        system("cls");
        printf("Este é o Menu do Cadastro!\n");
        printf("1 - Inserir Novo Cadastro\n");
        printf("2 - Buscar Cadastro\n");
        printf("3 - Alterar Cadastro\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%i", &escolha2);
        fflush(stdin);

        switch(escolha2)
        {
            case 1:
            printf("Iniciando Sistema de Novo Cadastro...\n");
            NovoCadastro();
            break;

            case 2:
            printf("Iniciando Sistema de Busca de Cadastros...\n");
            BuscaCadastro();
            break;

            case 3:
            printf("Iniciando Sistema de Alteração de Cadastros...\n");
            AlterarCadastro();
            break;

            case 4:
            printf("Saindo do Sistema de Cadastros...\n");
            loop2 = -1;
            break;
        }

    }



    return;
}

//função que cria um novo cadastro de produto ou usuário
//pronta
void NovoCadastro()
{
    FILE *ponteiro_arquivo;
    //-----------------------------
    //Dados de cadastro de cliente
    char nome[10];
    int idade=0;
    char telefone[11];
    char CPF[12];
    int escolha3;
    //-----------------------------
    //-----------------------------
    //Dados de cadastro de Produto
    char nomeproduto[10];
    int barcode;
    char validade[10];
    float preco;
    //-----------------------------

    printf("Insira qual o tipo do novo cadastro: \n");
    printf("1 - Cliente\n");
    printf("2 - Produto\n");
    scanf("%i", &escolha3);
    fflush(stdin);

    switch(escolha3)
    {
        case 1:

        //Criar novo tipo de Cadastro de Cliente, neste inserindo dados em um arquivo
        printf("Qual o nome do Cliente a ser inserido?: ");
        gets(nome);
        fflush(stdin);

        printf("Qual a idade do Cliente a ser inserido?: ");
        scanf("%i", &idade);
        fflush(stdin);

        printf("Qual o telefone do Cliente a ser inserido?: ");
        gets(telefone);
        fflush(stdin);

        printf("Qual o CPF do Cliente a ser inserido?: ");
        gets(CPF);
        fflush(stdin);

        //Apos a inserção dos dados do cliente pelo usuario, inserir os dados em um arquivo de cadastro.
        Encapsulador_Arquivo(nome);
        ponteiro_arquivo = fopen(nome, "w");
        Desencapsulador_Arquivo(nome);
        //Importante verificar se o arquivo foi possível de ser criado para evitar problemas.
        if(ponteiro_arquivo == NULL)
        {
            printf("Não foi possível criar o arquivo! Erro.");
            system("pause");
            return;
        }
        fprintf(ponteiro_arquivo, "Cadastro de usuário\n");
        fprintf(ponteiro_arquivo, "Nome: %s\n", nome);
        fprintf(ponteiro_arquivo, "Idade: %i\n", idade);
        fprintf(ponteiro_arquivo, "Telefone: %s\n", telefone);
        fprintf(ponteiro_arquivo, "CPF: %s\n", CPF);
        fprintf(ponteiro_arquivo, "Final do Cadastro!");
        fclose(ponteiro_arquivo);

        printf("O cadastro foi concluído com sucesso!");

        break;

        case 2:

        //Criar novo tipo de Cadastro de Produto, inserindo dados em um arquivo.
        printf("Qual o nome do produto a ser inserido?: ");
        gets(nomeproduto);
        fflush(stdin);

        printf("Qual o barcode do produto a ser inserido?: ");
        scanf("%i", &barcode);
        fflush(stdin);

        printf("Qual a validade do produto a ser inserido?: ");
        gets(validade);
        fflush(stdin);

        printf("Qual o preco a ser inserido?: ");
        scanf("%f", &preco);
        fflush(stdin);

        //Apos a inserção dos dados do cliente pelo usuario, inserir os dados em um arquivo de cadastro.
        Encapsulador_Arquivo(nomeproduto);
        ponteiro_arquivo = fopen(nomeproduto, "w");
        Desencapsulador_Arquivo(nomeproduto);
        //Importante verificar se o arquivo foi possível de ser criado para evitar problemas.
        if(ponteiro_arquivo == NULL)
        {
            printf("Não foi possível criar o arquivo! Erro.");
            system("pause");
            return;
        }

        fprintf(ponteiro_arquivo, "Cadastro de Produto\n");
        fprintf(ponteiro_arquivo, "Nome: %s\n", nomeproduto);
        fprintf(ponteiro_arquivo, "Barcode: %i\n", barcode);
        fprintf(ponteiro_arquivo, "Validade: %s\n", validade);
        fprintf(ponteiro_arquivo, "Preço: $%f\n", preco);
        fprintf(ponteiro_arquivo, "Final do Cadastro!");
        fclose(ponteiro_arquivo);
        printf("O cadastro foi concluído com sucesso!");
        system("pause");

        break;
    }


}

void AlterarCadastro()
{
    char busca[30];
    strcpy(busca, "\0");
    char leitura2[50];
    strcpy(leitura2, "\0");
    char buffer[300];
    strcpy(buffer, "\0");
    FILE *ponteiro_arquivo;
    FILE *escrita_arquivo;
    char leituranome[63];
    //-----------------------------
    //Dados de cadastro de cliente
    char nome[10];
    strcpy(nome, "\0");
    char idade[3];
    strcpy(idade, "\0");
    char telefone[11];
    strcpy(telefone, "\0");
    char CPF[12];
    strcpy(CPF, "\0");
    int escolha=0;
    //-----------------------------
    //-----------------------------
    //Dados de cadastro de Produto
    char nomeproduto[10];
    strcpy(nomeproduto, "\0");
    char barcode[10];
    strcpy(barcode, "\0");
    char validade[10];
    strcpy(validade, "\0");
    //-----------------------------

    printf("Qual cadastro você deseja ALTERAR?: ");
    gets(busca);
    fflush(stdin);

    //para que o cadastro seja buscado corretamente pelo sistema, é necessário adicionar o sufixo .cadastro à busca.
    Encapsulador_Arquivo(busca);
    ponteiro_arquivo = fopen(busca, "r");

    //Verificando se encontrou o arquivo
    if(ponteiro_arquivo == NULL)
    {
        printf("O arquivo não foi encontrado! Erro.\n");
        system("pause");
        return;
    }
    //barras para melhor visualização
    printf("----------------------------------------------------------\n");

    while(escolha<5)
    {
        //faz a leitura de uma linha do arquivo
        fgets(leitura2, 50, ponteiro_arquivo);
        //insere a linha no buffer, pois quando escrevemos em um arquivo o apagamos. o buffer serve para nao perdermos os dados
        strcat(buffer, leitura2);
        escolha++;
    }


    //imprime o buffer adquirido do loop
    printf("%s", buffer);

    printf("\n----------------------------------------------------------\n");

    escolha = 0;


    //função de alteração do cadastro:
    printf("\nInsira o que deseja alterar no cadastro: \n");
    printf("1 - nome\n");
    printf("2 - idade\n");
    printf("3 - telefone\n");
    printf("4 - CPF\n");
    printf("5 - nome do produto\n");
    printf("6 - barcode\n");
    printf("7 - validade\n");
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha)
    {
    case 1:
        printf("Insira o novo nome: ");
        fgets(nome, 10, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leituranome, até o campo nome:
        strncpy(leituranome, buffer, LINHA_NOME);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, nome);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_NOME+strlen(nome));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");

        break;
    case 2:
        printf("Insira a nova idade: ");
        fgets(idade, 3, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_IDADE);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, idade);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_IDADE+strlen(idade));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    case 3:
        printf("Insira o novo telefone: ");
        fgets(telefone, 30, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_TELEFONE);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, telefone);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_TELEFONE+strlen(telefone));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    case 4:
        printf("Insira o novo CPF: ");
        fgets(CPF, 30, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_CPF);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, CPF);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_CPF+strlen(nome));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    case 5:
        printf("Insira o novo nome do produto: ");
        fgets(nomeproduto, 30, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_NOMEPRODUTO);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, nomeproduto);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_NOMEPRODUTO+strlen(nome));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    case 6:
        printf("Insira o novo barcode: ");
        fgets(barcode, 10, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_BARCODE);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, barcode);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_BARCODE+strlen(nome));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    case 7:
        printf("Insira a nova validade: ");
        fgets(validade, 30, stdin);
        fflush(stdin);

        //copia a primeira parte do buffer para o leitura 2, até o campo nome:
        strncpy(leituranome, buffer, LINHA_VALIDADE);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //concatena o nome no buffer
        strcat(leituranome, validade);

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", leituranome);
        printf("\n----------------------------------------------------------\n");

        //adiciona o nome novo no buffer
        memcpy(buffer, leituranome, LINHA_VALIDADE+strlen(nome));

        printf("\n----------------------------------------------------------\n");
        printf("%s\n", buffer);
        printf("\n----------------------------------------------------------\n");

        //escreve o buffer no arquivo
        //------------------------------------------
        escrita_arquivo = fopen(busca, "w");

        fprintf(escrita_arquivo, "%s", buffer);

        fclose(escrita_arquivo);
        //-------------------------------------------
        printf("O arquivo foi alterado com sucesso!!!!\n");
        break;
    }


    //fechando o ponteiro para que não haja erro de leak de memória
    fclose(ponteiro_arquivo);

    //barras para melhor visualização
    printf("\n----------------------------------------------------------\n");
    system("pause");

    return;

}

//Função que busca cadastros já previamente criados
//pronta
void BuscaCadastro()
{
    int escolha3=4;
    //---------------------------------------------
    // variáveis para busca de um único arquivo
    char busca[30];
    strcpy(busca, "\0");
    char leitura;
    //---------------------------------------------
    // variáveis para a busca de todos os arquivos
    DIR *diretorio;
    struct dirent *lsdiretorio;
    const char ponto[10] = ".cadastro";
    //---------------------------------------------
    FILE *ponteiro_arquivo;

    printf("Bem vindo ao sistema de busca!\n");
    printf("1 - Listar Todos os Cadastros\n");
    printf("2 - Buscar um Cadastro\n");
    printf("3 - Sair\n");
    printf("Escolha uma das opções: ");
    scanf("%i", &escolha3);
    fflush(stdin);

    switch(escolha3)
    {
        case 1:
        printf("Listando todos os cadastros...\n");

        //abre o diretório em que se encontra o executável
        diretorio = opendir("./");
        //lê todos os nomes de arquivos que se encontram na pasta aberta no diretório
        //este loop passa por todos os arquivos, até encontrar o final
        //o loop funciona da seguinte maneira: o sistema tenta ler o nome do arquivo, caso não consiga, corta o loop
        while ((lsdiretorio = readdir(diretorio)) != NULL)
        {
            //esta função imprime o nome do arquivo escolhido
            //a função strstr compara duas strings, e caso o texto de uma string esteja em outra, retorna um valor
            //neste caso, caso a o if encontre a string .cadastro em algum dos nomes dos arquivos, ele passa o comando para
            //imprimir o nome do arquivo
            if((strstr(lsdiretorio->d_name, ponto)!=NULL))
            {
                printf("----------------------------------------------------------\n");
                printf("%s\n", lsdiretorio->d_name);
                printf("----------------------------------------------------------\n");
            }
        }
        closedir(diretorio);
        break;

        //busca por um único cadastro completado
        case 2:
        printf("Insira o nome do cadastro: ");
        gets(busca);
        fflush(stdin);

        //para que o cadastro seja buscado corretamente pelo sistema, é necessário adicionar o sufixo .cadastro à busca.
        Encapsulador_Arquivo(busca);
        ponteiro_arquivo = fopen(busca, "r");

        //Verificando se encontrou o arquivo
        if(ponteiro_arquivo == NULL)
        {
            printf("O arquivo não foi encontrado! Erro.");
            system("pause");
            return;
        }
        //barras para melhor visualização
        printf("----------------------------------------------------------\n");

        do
        {
            //faz a leitura de um caractere do arquivo
            leitura = fgetc(ponteiro_arquivo);

            //imprime o caractere lido
            printf("%c", leitura);
            //o while faz o loop enquanto o final do arquivo não for encontrando, o sinal EOF
        }while(leitura != EOF);

        //fechando o ponteiro para que não haja erro de leak de memória
        fclose(ponteiro_arquivo);

        //barras para melhor visualização
        printf("\n----------------------------------------------------------\n");
        break;

        case 3:
        printf("Fechando sistema de busca...\n");
        return;
        break;
    }



    system("pause");
    printf("\n");
}

//Prepara o arquivo para ser registrado como .cadastro, adicionando o sufixo .cadastro.
//pronto
char Encapsulador_Arquivo(char arquivo[30])
{
    //Esta função encapsula o nome do arquivo a ser criado e adiciona o sufixo .cadastro, para permitir que o arquivo criado tenha um tipo especifico
    strcat(arquivo, ".cadastro");
    return arquivo[40];
}

//retorna o arquivo sem o sufixo . cadastro
//pronto
char Desencapsulador_Arquivo(char arquivo[40])
{
    char *resultado;
    int tamanho=0;
    char cadastro[10];

    strcpy(cadastro, ".");

    tamanho = strlen(arquivo);
    tamanho = tamanho-9;

    resultado = strtok(arquivo, cadastro);

    return resultado[30];
}


#endif // FUNCAOCADASTRO_H_INCLUDED

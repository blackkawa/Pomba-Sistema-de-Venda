#ifndef FUNCAOCAIXA_H_INCLUDED
#define FUNCAOCAIXA_H_INCLUDED

typedef struct Caixa{
    float aberturaCaixa;
    float TotalCaixa;
    int numeroVendas;
    float registroCaixa[30];
}CaixaAberto;

float AbrirCaixa();
float InicarCompra();

void menuVendas()
{
    float dinheiro;
    int escolha=0;
    int loop=0;
    //-------------------------------------------------------
    struct Caixa* caixaatual;
    caixaatual = (CaixaAberto*) malloc (sizeof(CaixaAberto));
    caixaatual->aberturaCaixa = 0;
    caixaatual->numeroVendas = 0;
    caixaatual->TotalCaixa = 0;
    //-------------------------------------------------------

    system("cls");
    printf("----------------------------------------------------------\n");
    printf("Bem vindo ao menu do Caixa!!!\n");
    printf("----------------------------------------------------------\n");

    for(loop=0;loop!=-1;)
    {
        system("cls");
        printf("Insira a op��o desejada!: \n");
        printf("1 - Abrir Caixa\n");
        printf("2 - Iniciar Compra\n");
        printf("3 - Fechar Caixa\n");
        printf("4 - Sair\n");
        printf("----------------------------------------------------------\n");
        printf("Status do caixa: \n");
        printf("Abertura do Caixa: %g\n", caixaatual->aberturaCaixa);
        printf("Valor total no Caixa: %g\n", caixaatual->TotalCaixa);
        printf("Vendas realizadas hoje: %i\n", caixaatual->numeroVendas);
        printf("----------------------------------------------------------\n");
        scanf("%i", &escolha);
        fflush(stdin);

        switch(escolha){
        case 1:
            caixaatual->aberturaCaixa = AbrirCaixa();
            break;
        case 2:
            caixaatual->TotalCaixa = InicarCompra();
            break;
        case 3:
            printf("----------------------------------------------------------\n");
            printf("O caixa ser� fechado!!!\n");
            printf("----------------------------------------------------------\n");
            printf("Insira qual o valor em dinheiro no caixa: ");
            scanf("%f", &dinheiro);
            printf("----------------------------------------------------------\n");
            printf("O valor total em dinheiro � de: %g\n", dinheiro);
            printf("----------------------------------------------------------\n");
            printf("E o valor total em vendas foi de: %g\n", caixaatual->TotalCaixa);
            printf("----------------------------------------------------------\n");
            printf("Houve uma diferen�a de: %g\n", dinheiro-caixaatual->TotalCaixa);
            printf("----------------------------------------------------------\n");
            system("pause");
            return;
            break;
        case 4:
            free(caixaatual);
            return;
            break;
    }
    }


    return;
}

float AbrirCaixa()
{
    float abertura;

    printf("Com qual valor o caixa ser� aberto?\n");
    scanf("%f", &abertura);

    return abertura;
}
float InicarCompra()
{
    FILE *cadastros;
    int loop=0;
    char cadastro[30];
    float totalCompra=0;
    char leitura;
    char preco[4];
    float valor;

    for(loop=0;loop!=-1;)
    {
        printf("Valor total da compra: %g\n", totalCompra);
        printf("Insira o cadastro do item a ser inclu�do na compra, \nou escreva fechar para fechar a compra: ");
        gets(cadastro);

        if(strcmp(cadastro, "fechar")==0)
        {
            printf("----------------------------------------------------------\n");
            printf("O total da compra � de: %g\n", totalCompra);
            printf("Agora cobre o cliente!\n");
            printf("----------------------------------------------------------\n");
            return totalCompra;
        }

        Encapsulador_Arquivo(cadastro);
        cadastros = fopen(cadastro, "r");

        //Caso o cadastro n�o exista, retorna que n�o foi encontrado
        if(cadastros==NULL)
        {
            printf("O cadastro n�o foi encontrado!!!");
            system("pause");
        }else{
            //encontra a linha com o preco
            do
            {
            //faz a leitura de um caractere do arquivo
            leitura = fgetc(cadastros);

            //O leitor tenta encontrar o simbolo de dinheiro para encontrar o pre�o
            if(leitura=='$')
            {
                fgets(preco, 4, cadastros);
                valor = atof(preco);
                printf("O preco do produto �: %g\n", valor);
                totalCompra = totalCompra+valor;
            }
            //o while faz o loop enquanto o final do arquivo n�o for encontrando, o sinal EOF
        }while(leitura != EOF);

        }

    }
    return 0;
}


#endif // FUNCAOCAIXA_H_INCLUDED

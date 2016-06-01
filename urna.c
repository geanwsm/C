/*********************************************************************
*                  Projeto - Urna de Apuração - ATP                  *
*                                                                    *
*   Autores: Elton Fonseca & Gean Matos                              *
*   Periodo 1                                                        *
*   PUC Minas - Poços de Caldas                                      *
*********************************************************************/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_data
{
    int dia, mes, ano;
} data;

typedef struct s_pessoa
{
    data nascimento;
    char nome[21];
    int cpf;
} pessoa;

typedef struct s_mesario
{
    pessoa p_mesario;
    char senha[7];
    char login[7];
} mesario;

typedef struct s_candidato
{
    int v, nbaux;
    pessoa p_candidato;
    int votos;
    int numero;
    char partido[5];

} candidato;

int main()
{
    int p; //mover as setas e pegar o enter
    int op=1; //setar qual opção foi selecionada (padrão 1)
    int x = 0, y = 0;//coordenadas do posicionaCursor
    int s = 0;//controle do funcao inicial
    int input = 0;//valor do retorno de scanf
    int total_votos = 54000, c_votos = 0, valido, nb;
    float media;
    FILE *exp;
    candidato candidatos[10], cand_aux;
    mesario usuario;

    void OrdenaCandidatos(candidato *candidatos);
    void posicionaCursor(short x, short y);
    void inicial(int x, int y, int saudacao);
    void login(mesario usuario, int x, int y);
    void menu();
    void atualizaCandidato(candidato *candidatos);
    void AtualziaDadosCandidato(int i, candidato *candidatos);
    int atualizaCadastroCandidato(int posicao, int nb, int valido, candidato *candidatos);
    char *scannerUser(int t_user, int indice);

    inicial(x, y, 0);
    do
    {
        exp  = fopen("usuario.txt", "r");
        fseek(exp, 0, SEEK_END);
        if(s == 1)
        {
            inicial(x, y, 1);
            s = 0;
        }
        fflush(stdin);
        p = getch();
        switch(p)
        {
        case 72: // cima
            op=1;
            posicionaCursor(33, 9);
            printf(" ");
            posicionaCursor(33, 8);
            printf(">");
            break;
        case 80: // baixo
            op=2;
            posicionaCursor(33, 8);
            printf(" ");
            posicionaCursor(33, 9);
            printf(">");
            break;
        case 13: // enter
            if(op == 1)
            {
                if(exp == NULL || ftell(exp) == 0)
                {
                    posicionaCursor(x + 23, y + 12);
                    printf("Voce deve cadastrar-se primeiro!");
                    Sleep(1000);
                    s = 1;
                }
                else
                {
                    fseek(exp, 0, SEEK_SET);
                    fread(&usuario, sizeof(mesario), 1, exp);
                    fclose(exp);
                    login(usuario, x, y);
                    menu();
                    y = 7;
                    fclose(exp);
                    exp = fopen("candidatos.txt", "r");
                    fseek(exp, 0, SEEK_END);
                    if(exp != NULL && ftell(exp) != 0)
                    {
                        fseek(exp, 0, SEEK_SET);
                        int i;
                        for(i = 0; i < 10; i++)
                        {
                            fread(&candidatos[i], sizeof(candidato), 1, exp);
                        }
                        nb = candidatos[9].nbaux;
                    }
                    do
                    {
                        fclose(exp);
                        exp = fopen("candidatos.txt", "r");
                        fseek(exp, 0, SEEK_END);
                        if(exp != NULL && ftell(exp) != 0)
                        {
                            fseek(exp, 0, SEEK_SET);
                            int i;
                            for(i = 0; i < 10; i++)
                            {
                                fread(&candidatos[i], sizeof(candidato), 1, exp);
                            }
                        }
                        p = getch();
                        switch(p)
                        {
                        case 72:
                            if(y == 7)
                            {
                                posicionaCursor(13, y);
                                printf(" ");
                                y = 15;
                                posicionaCursor(13, y);
                                printf(">");
                            }
                            else
                            {
                                posicionaCursor(13, y);
                                printf(" ");
                                y -= 1;
                                posicionaCursor(13, y);
                                printf(">");
                            }
                            break;
                        case 80:
                            if(y == 15)
                            {
                                posicionaCursor(13, y);
                                printf(" ");
                                y = 7;
                                posicionaCursor(13, y);
                                printf(">");
                            }
                            else
                            {
                                posicionaCursor(13, y);
                                printf(" ");
                                y += 1;
                                posicionaCursor(13, y);
                                printf(">");
                            }
                            break;
                        case 13:
                            if(y == 7)
                            {
                                if(exp != NULL && ftell(exp) != 0)
                                {
                                    posicionaCursor(22, 19);
                                    printf("Candidatos ja cadastrados");
                                    Sleep(1000);
                                    int k;
                                    for(k = 0; k < 79; k++);
                                    {
                                        posicionaCursor(k, 19);
                                        printf(" ");
                                    }
                                }
                                else if(exp == NULL || ftell(exp) == 0)
                                {
                                    int i;
                                    for(i = 0; i < 10; i++)
                                    {
                                        system("cls");
                                        posicionaCursor(30, 2);
                                        printf("CADASTRO DO CANDIDATO %d", i+1);
                                        posicionaCursor(20, 6);
                                        printf("Nome: ");
                                        strcpy(candidatos[i].p_candidato.nome, scannerUser(1, 21));
                                        do
                                        {
                                            posicionaCursor(20, 7);
                                            printf("Data de Nascimento [dd mm aaa]:                     \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                                            input = scanf("%d %d %d", &candidatos[i].p_candidato.nascimento.dia, &candidatos[i].p_candidato.nascimento.mes, &candidatos[i].p_candidato.nascimento.ano);
                                            fflush(stdin);
                                        }
                                        while(input == 0 || candidatos[i].p_candidato.nascimento.dia > 31 || candidatos[i].p_candidato.nascimento.dia < 1 || candidatos[i].p_candidato.nascimento.mes < 1 || candidatos[i].p_candidato.nascimento.mes > 12 || candidatos[i].p_candidato.nascimento.ano < 1900 || candidatos[i].p_candidato.nascimento.ano > 3000);
                                        do
                                        {
                                            posicionaCursor(20, 8);
                                            printf("CPF:                               \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                                            input = scanf("%d", &candidatos[i].p_candidato.cpf);
                                            fflush(stdin);
                                        }
                                        while(input == 0);
                                        do
                                        {
                                            posicionaCursor(20, 9);
                                            printf("Numero:           \b\b\b\b\b\b\b\b\b\b");
                                            input = scanf("%d", &candidatos[i].numero);
                                            fflush(stdin);
                                        }
                                        while(input == 0);
                                        posicionaCursor(20, 10);
                                        printf("Partido: ");
                                        strcpy(candidatos[i].partido, scannerUser(1, 5));
                                    }
                                    fclose(exp);
                                    exp = fopen("candidatos.txt", "w");
                                    for(i = 0; i < 10; i++)
                                    {
                                        fwrite(&candidatos[i], sizeof(candidato), 1, exp);
                                    }
                                    fclose(exp);
                                }
                                menu();
                            }
                            else if(y == 8)
                            {
                                if(exp != NULL && ftell(exp) != 0)
                                {
                                    if(candidatos[9].v == 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Votos ja cadastrados");
                                        Sleep(1000);
                                        int j;
                                        for(j = 0; j < 70; j++)
                                        {
                                            posicionaCursor(j, 19);
                                            printf(" ");
                                        }
                                    }
                                    else
                                    {
                                        int i;
                                        for(i = 0; i < 10; i++)
                                        {
                                            system("cls");
                                            posicionaCursor(30, 2);
                                            printf("CADASTRO DE VOTOS");
                                            posicionaCursor(20, 6);
                                            printf("Nome: %s", candidatos[i].p_candidato.nome);
                                            posicionaCursor(20, 7);
                                            printf("Numero: %d", candidatos[i].numero);
                                            posicionaCursor(20, 8);
                                            printf("Partido: %s", candidatos[i].partido);
                                            do
                                            {
                                                posicionaCursor(20, 10);
                                                printf("Votos:         \b\b\b\b\b\b\b\b");
                                                fflush(stdin);
                                                input = scanf("%d", &candidatos[i].votos);
                                                if(candidatos[i].votos > total_votos)
                                                {
                                                    posicionaCursor(25, 12);
                                                    printf("Votos Excedentes! Ainda sobram %d", total_votos);
                                                    Sleep(1000);
                                                    int k;
                                                    for(k = 25; k < 70; k++)
                                                    {
                                                        posicionaCursor(k, 12);
                                                        printf(" ");
                                                    }
                                                }
                                            }
                                            while(input == 0 || candidatos[i].votos > total_votos);
                                            total_votos -= candidatos[i].votos;
                                            nb = total_votos;
                                            candidatos[i].v = 1;
                                            candidatos[i].nbaux = nb;
                                        }
                                        fclose(exp);
                                        exp = fopen("candidatos.txt", "w");
                                        for(i = 0; i < 10; i++)
                                        {
                                            fwrite(&candidatos[i], sizeof(candidato), 1, exp);
                                        }
                                        fclose(exp);
                                        OrdenaCandidatos(candidatos);
                                        menu();
                                        y = 7;
                                    }
                                }
                                else if(exp == NULL || ftell(exp) == 0)
                                {
                                    posicionaCursor(22, 19);
                                    printf("Cadastre os candidatos");
                                    int k;
                                    Sleep(1000);
                                    for(k = 22; k < 60; k++)
                                    {
                                        posicionaCursor(k, 19);
                                        printf(" ");
                                    }
                                }
                            }
                            else if(y == 9)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    OrdenaCandidatos(candidatos);
                                    system("cls");
                                    posicionaCursor(30, 2);
                                    printf("OS 3 MAIS VOTADOS");
                                    y = 6;
                                    int i;
                                    for(i = 0; i < 3; i++)
                                    {
                                        posicionaCursor(30, y);
                                        printf("Nome: %s", candidatos[i].p_candidato.nome);
                                        y++;
                                        posicionaCursor(30, y);
                                        printf("Numero: %d", candidatos[i].numero);
                                        y++;
                                        posicionaCursor(30, y);
                                        printf("Partido: %s", candidatos[i].partido);
                                        y++;
                                        posicionaCursor(30, y);
                                        printf("Votos: %d", candidatos[i].votos);
                                        y += 2;
                                    }
                                    y += 2;
                                    posicionaCursor(15, y);
                                    printf("...Aperte enter para voltar ao menu...");
                                    getch();
                                    y = 7;
                                    menu();
                                }
                                else
                                {
                                    if(exp == NULL || ftell(exp) == 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                            else if(y == 10)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    int i;
                                    media = 0;
                                    system("cls");
                                    posicionaCursor(30, 2);
                                    printf("MEDIA DE VOTOS");
                                    posicionaCursor(20, 6);
                                    valido = 0;
                                    for(i = 0; i < 10; i++)
                                    {
                                        valido += candidatos[i].votos;
                                    }
                                    printf("Total de votos validos: %d", valido);
                                    posicionaCursor(20, 8);
                                    printf("Total de votos nulos/brancos: %d", nb);
                                    posicionaCursor(20, 10);
                                    for(i = 0; i < 10; i++)
                                    {
                                        media += candidatos[i].votos;
                                    }
                                    total_votos = 0;
                                    media /= 10;
                                    printf("Media de votos validos: %.2f", media);
                                    posicionaCursor(20, 12);
                                    total_votos = nb + valido;
                                    printf("Total de votos: %d", total_votos);
                                    posicionaCursor(15, 15);
                                    printf("...Aperte enter para voltar ao menu...");
                                    getch();
                                    y = 7;
                                    menu();
                                }
                                else
                                {
                                    if(exp == NULL || ftell(exp) == 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                            else if(y == 11)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    system("cls");
                                    posicionaCursor(30, 2);
                                    printf("CANDIDATOS ABAIXO DA MEDIA");
                                    y = 6;
                                    int i;
                                    for(i = 0; i < 10; i++)
                                    {
                                        if(candidatos[i].votos < media)
                                        {
                                            posicionaCursor(30, y);
                                            printf("Nome: %s", candidatos[i].p_candidato.nome);
                                            y++;
                                            posicionaCursor(30, y);
                                            printf("Numero: %d", candidatos[i].numero);
                                            y++;
                                            posicionaCursor(30, y);
                                            printf("Partido: %s", candidatos[i].partido);
                                            y += 2;
                                        }
                                    }
                                    y += 2;
                                    posicionaCursor(15, y);
                                    printf("...Aperte enter para voltar ao menu...");
                                    getch();
                                    y = 7;
                                    menu();
                                }
                                else
                                {
                                    if(exp == NULL || ftell(exp) == 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }

                            }
                            else if(y == 12)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    system("cls");
                                    posicionaCursor(30, 2);
                                    printf("INFORMACOES DOS CANDIDATOS");
                                    y = 4;
                                    int i;
                                    for(i = 0; i < 10; i++)
                                    {
                                        posicionaCursor(20, y);
                                        printf("Candidato numero %d", i + 1);
                                        y +=2;
                                        posicionaCursor(20, y);
                                        printf("Nome: %s", candidatos[i].p_candidato.nome);
                                        y++;
                                        posicionaCursor(20, y);
                                        printf("CPF: %d", candidatos[i].p_candidato.cpf);
                                        y++;
                                        posicionaCursor(20, y);
                                        printf("Data de Nascimento: %d/%d/%d", candidatos[i].p_candidato.nascimento.dia, candidatos[i].p_candidato.nascimento.mes, candidatos[i].p_candidato.nascimento.ano);
                                        y++;
                                        posicionaCursor(20, y);
                                        printf("Numero: %d", candidatos[i].numero);
                                        y++;
                                        posicionaCursor(20, y);
                                        printf("Partido: %s", candidatos[i].partido);
                                        y++;
                                        posicionaCursor(20, y);
                                        printf("Votos: %d", candidatos[i].votos);
                                        y += 2;
                                    }
                                    y += 2;
                                    posicionaCursor(15, y);
                                    printf("...Aperte enter para voltar ao menu...");
                                    getch();
                                    y = 7;
                                    menu();
                                }
                                else
                                {
                                    if(exp == NULL || ftell(exp) == 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                            else if(y == 13)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    atualizaCandidato(candidatos);
                                    y = 6;
                                    p = 0;
                                    do
                                    {
                                        p = getch();
                                        switch(p)
                                        {
                                        case 72:
                                            if(y == 6)
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");
                                                y = 17;
                                                posicionaCursor(7, y);
                                                printf(">");
                                            }
                                            else if(y == 17)
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");
                                                y = 15;
                                                posicionaCursor(7, y);
                                                printf(">");
                                            }
                                            else
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");
                                                y--;
                                                posicionaCursor(7, y);
                                                printf(">");
                                            }
                                            break;
                                        case 80:
                                            if(y == 17)
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");

                                                y = 6;

                                                posicionaCursor(7, y);
                                                printf(">");
                                            }
                                            else if(y == 15)
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");

                                                y = 17;

                                                posicionaCursor(7, y);
                                                printf(">");
                                            }
                                            else
                                            {
                                                posicionaCursor(7, y);
                                                printf(" ");

                                                y++;

                                                posicionaCursor(7, y);
                                                printf(">");

                                            }
                                            break;
                                        case 13:
                                            if(y == 6)
                                            {
                                                nb = atualizaCadastroCandidato(0,nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 7)
                                            {
                                                nb = atualizaCadastroCandidato(1, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 8)
                                            {
                                                nb = atualizaCadastroCandidato(2, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 9)
                                            {
                                                nb = atualizaCadastroCandidato(3, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 10)
                                            {
                                                nb = atualizaCadastroCandidato(4, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 11)
                                            {
                                                nb = atualizaCadastroCandidato(5, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 12)
                                            {
                                                nb = atualizaCadastroCandidato(6, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 13)
                                            {
                                                nb = atualizaCadastroCandidato(7, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 14)
                                            {
                                                nb = atualizaCadastroCandidato(8, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            else if(y == 15)
                                            {
                                                nb = atualizaCadastroCandidato(9, nb, valido, candidatos);
                                                p = 0;
                                                y = 6;
                                            }
                                            break;
                                        }
                                    }
                                    while(p != 13);
                                    int i;
                                    for(i = 0; i < 10; i++)
                                    {
                                        candidatos[i].nbaux = nb;
                                    }
                                    fclose(exp);
                                    exp = fopen("candidatos.txt", "w");
                                    for(i = 0; i < 10; i++)
                                    {
                                        fwrite(&candidatos[i], sizeof(candidato), 1, exp);
                                    }
                                    posicionaCursor(15, 19);
                                    printf("...Aperte enter para voltar ao menu...");
                                    getch();
                                    y = 7;
                                    menu();
                                }
                                else
                                {
                                    if((exp == NULL || ftell(exp) == 0))
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 1)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                            else if(y == 14)
                            {
                                if((exp != NULL && ftell(exp) != 0) && candidatos[9].v == 1)
                                {
                                    posicionaCursor(22, 19);
                                    printf("Exportando...");
                                    int i;
                                    for(i = 22; i < 36; i++)
                                    {
                                        posicionaCursor(i, 20);
                                        printf("%c", 219);
                                        Sleep(200);
                                    }
                                    fclose(exp);
                                    exp = fopen("Relatorio_da_Apuracao.txt", "w");
                                    fprintf(exp, "\t\t\t\t\t:::::::::::::::::::::::::::\n");
                                    fprintf(exp, "\t\t\t\t\t:: Relatório da Apuração ::\n");
                                    fprintf(exp, "\t\t\t\t\t:::::::::::::::::::::::::::\n\n\n");
                                    fprintf(exp, "\tCANDIDATOS:\n\n");
                                    for(i = 0; i < 10; i++)
                                    {
                                        fprintf(exp, "\tNome: %s\n", candidatos[i].p_candidato.nome);
                                        fprintf(exp, "\tCPF: %d\n", candidatos[i].p_candidato.cpf);
                                        fprintf(exp, "\tData de Nascimento: %d/%d/%d\n", candidatos[i].p_candidato.nascimento.dia, candidatos[i].p_candidato.nascimento.mes, candidatos[i].p_candidato.nascimento.ano);
                                        fprintf(exp, "\tNúmero: %d\n", candidatos[i].numero);
                                        fprintf(exp, "\tPartido: %s\n", candidatos[i].partido);
                                        fprintf(exp, "\tVotos: %d\n\n", candidatos[i].votos);

                                    }
                                    fprintf(exp, "\tESTATISTICAS: \n\n");
                                    fprintf(exp, "\tTotal de Votos: %d\n", total_votos);
                                    fprintf(exp, "\tTotal de Votos Brancos/Nulos: %d\n", nb);
                                    fprintf(exp, "\tTotal de Votos Validos: %d\n\n", valido);
                                    fprintf(exp, "\tDADOS DO MESARIO: \n\n");
                                    fprintf(exp, "\tNome: %s\n", usuario.p_mesario.nome);
                                    fprintf(exp, "\tCPF: %d\n", usuario.p_mesario.cpf);
                                    fprintf(exp, "\tData de Nascimento: %d/%d/%d\n", usuario.p_mesario.nascimento.dia, usuario.p_mesario.nascimento.mes, usuario.p_mesario.nascimento.ano);
                                    fprintf(exp, "\tLogin: %s", usuario.login);
                                    fclose(exp);
                                    y = 7;
                                    p = 0;
                                    menu();
                                }
                                else
                                {
                                    if(exp == NULL || ftell(exp) == 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os candidatos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                    if(candidatos[9].v != 0)
                                    {
                                        posicionaCursor(22, 19);
                                        printf("Cadastre os votos");
                                        int k;
                                        Sleep(1000);
                                        for(k = 22; k < 60; k++)
                                        {
                                            posicionaCursor(k, 19);
                                            printf(" ");
                                        }
                                    }
                                }
                            }
                            else if(y == 15)
                            {
                                fclose(exp);
                                system("cls");
                                exit(0);
                            }
                            break;
                        }
                    }
                    while(1);
                }
            }
            else if (op == 2)
            {
                if(exp == NULL || ftell(exp) == 0)
                {
                    system("cls");
                    posicionaCursor(30,2);
                    printf("CADASTRO DE  MESARIO:");
                    posicionaCursor(20,6);
                    printf("Nome: ");
                    strcpy(usuario.p_mesario.nome, scannerUser(1, 21));
                    do
                    {
                        posicionaCursor(20,7);
                        printf("Data de Nascimento [dd mm aaaa]:           \b\b\b\b\b\b\b\b\b\b");
                        input = scanf("%d %d %d",&usuario.p_mesario.nascimento.dia, &usuario.p_mesario.nascimento.mes, &usuario.p_mesario.nascimento.ano);
                        fflush(stdin);
                    }
                    while(input == 0 || usuario.p_mesario.nascimento.dia > 31 || usuario.p_mesario.nascimento.dia < 1 || usuario.p_mesario.nascimento.mes < 1 || usuario.p_mesario.nascimento.mes > 12 || usuario.p_mesario.nascimento.ano < 1900 || usuario.p_mesario.nascimento.ano > 3000);
                    do
                    {
                        posicionaCursor(20,8);
                        printf("CPF:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                        input = scanf("%d", &usuario.p_mesario.cpf);
                        fflush(stdin);
                    }
                    while(input == 0);
                    posicionaCursor(20,9);
                    printf("Login: ");
                    strcpy(usuario.login, scannerUser(1, 7));
                    posicionaCursor(20,10);
                    printf("Senha: ");
                    strcpy(usuario.senha, scannerUser(2, 7));
                    fclose(exp);
                    exp = fopen("usuario.txt", "w");
                    fwrite(&usuario, sizeof(mesario), 1, exp);
                    fclose(exp);
                    inicial(x, y, 1);
                }
                else
                {
                    posicionaCursor(x + 30, y + 12);
                    printf("Voce ja cadastrou!");
                    Sleep(1000);
                    system("cls");
                    op = 1;
                    inicial(x, y, 1);
                }
            }
            break;
        }
    }
    while(1);
}
void posicionaCursor(short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char *scannerUser(int t_user, int indice)
{
    char dado[indice];
    int i = -1;
    do
    {
        if(i < (indice - 1))
        {
            i++;
        }
        dado[i] = getch();
        if(dado[i] == 8)
        {
            if(i > 0)
            {
                printf("\b \b");
                i -= 2;
            }
            else
            {
                i = -1;
                printf("\a");
            }
        }
        else if(i <  indice - 1 && dado[i] != 13)
        {
            if(t_user == 1)
            {
                printf("%c", dado[i]);
            }
            else
            {
                printf("%c", 42);
            }
        }
        if(i == (indice - 1) && dado[i] != 13)
        {
            printf("\a");
        }
    }
    while(dado[i] != 13);
    if(dado[i] == 13)
    {
        dado[i] = '\0';
    }
    return dado;
}
void inicial(int x, int y, int saudacao)
{
    if(saudacao == 0)
    {
        int i;
        system("cls");
        system("color 1F");
        posicionaCursor(x + 23, y + 10);
        printf("Bem - Vindo a Apuracao de Votos!");
        for(i = 0; i < 32; i++)
        {
            Sleep(100);
            posicionaCursor((x + 23) + i, y + 12);
            printf("%c", 219);
        }
        saudacao = 1;
    }
    system("cls");
    posicionaCursor(x + 30, y + 7);
    printf("::::::::::::::::::::");
    posicionaCursor(x + 30, y + 8);
    printf("::   Logar        ::");
    posicionaCursor(x + 30,y + 9);
    printf("::   Cadastrar-se ::");
    posicionaCursor(x + 30,y + 10);
    printf("::::::::::::::::::::");
    posicionaCursor(x + 33, y + 8);
    printf(">");
}
void login(mesario usuario, int x, int y)
{
    char user[7];
    char pass[7];
    do
    {
        system("cls");
        posicionaCursor(x + 27, y + 8);
        printf("    Login: [      ]\b\b\b\b\b\b");
        posicionaCursor(x + 29, y + 8);
        printf(">");
        posicionaCursor(x + 39, y +8);
        strcpy(user, scannerUser(1, 7));
        posicionaCursor(x + 29, y + 8);
        printf(" ");
        posicionaCursor(x + 27, y + 9);
        printf("    Senha: [      ]\b\b\b\b\b\b");
        posicionaCursor(x + 29, y + 9);
        printf(">");
        posicionaCursor(x + 39, y + 9);
        strcpy(pass, scannerUser(2, 7));
        if(pass[0] == '\0' && user[0] == '\0')
        {
            posicionaCursor(x + 29, y + 12);
            printf("Campos Vazios!");
            Sleep(1000);
        }
        else if(pass[0] == '\0')
        {
            posicionaCursor(x + 29, y + 12);
            printf("Campo senha vazio!");
            Sleep(1000);
        }
        else if(user[0] == '\0')
        {
            posicionaCursor(x + 29, y + 12);
            printf("Campo login vazio!");
            Sleep(1000);
        }
        else if(strcmp(pass, usuario.senha) != 0 || strcmp(user, usuario.login) != 0)
        {
            posicionaCursor(x + 29, y + 12);
            printf("Login ou Senha Incorretos!");
            Sleep(1000);
        }
        posicionaCursor(0, 0);
    }
    while(pass[0] == '\0' || user[0] == '\0' || strcmp(pass, usuario.senha) != 0 || strcmp(user, usuario.login) != 0);
}
void menu()
{
    system("cls");
    posicionaCursor(10,4);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    posicionaCursor(10,5);
    printf("::                            MENU                             ::");
    posicionaCursor(10,6);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    posicionaCursor(10,7);
    printf("::   Cadastro de candidato.                                    ::");//7
    posicionaCursor(10,8);
    printf("::   Cadastrar votos.                                          ::");//8
    posicionaCursor(10,9);
    printf("::   Os 3 candidatos mais votados.                             ::");//9
    posicionaCursor(10,10);
    printf("::   Numero medio de votos.                                    ::");//10
    posicionaCursor(10,11);
    printf("::   Candidatos abaixo da media.                               ::");//11
    posicionaCursor(10,12);
    printf("::   Informacao dos candidatos.                                ::");//12
    posicionaCursor(10,13);
    printf("::   Atualizar dados.                                          ::");//13
    posicionaCursor(10, 14);
    printf("::   Exportar para TXT                                         ::");//14
    posicionaCursor(10,15);
    printf("::   Sair                                                      ::");//15
    posicionaCursor(10,16);
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    posicionaCursor(5,23);
    printf("Setas: Mover o cursor");
    posicionaCursor(5,24);
    printf("Enter: Seleciona opcao.");
    posicionaCursor(13, 7);
    printf(">");
}
void atualizaCandidato(candidato *candidatos)
{
    system("cls");
    posicionaCursor(30, 2);
    printf("ATUALIZAR CANDIDATOS");
    int i;
    int y = 6;
    for(i = 0; i < 10; i++)
    {
        posicionaCursor(10, y);
        printf("Candidato: %s", candidatos[i].p_candidato.nome);
        y++;
    }
    y++;
    posicionaCursor(10, y);
    printf("Sair");
    posicionaCursor(7, 6);
    printf(">");
}
void AtualziaDadosCandidato(int i, candidato *candidatos)
{
    system("cls");
    posicionaCursor(30, 2);
    printf("CANDIDATO NUMERO %d", i + 1);
    posicionaCursor(20, 6);
    printf("Nome: %s", candidatos[i].p_candidato.nome);
    posicionaCursor(20, 7);
    printf("CPF: %d", candidatos[i].p_candidato.cpf);
    posicionaCursor(20, 8);
    printf("Data de Nascimento: %d/%d/%d", candidatos[i].p_candidato.nascimento.dia, candidatos[i].p_candidato.nascimento.mes, candidatos[i].p_candidato.nascimento.ano);
    posicionaCursor(20, 9);
    printf("Numero: %d", candidatos[i].numero);
    posicionaCursor(20, 10);
    printf("Partido: %s", candidatos[i].partido);
    posicionaCursor(20, 11);
    printf("Votos: %d", candidatos[i].votos);
    posicionaCursor(20, 12);
    printf("Sair");
    posicionaCursor(17, 6);
    printf(">");
}

int atualizaCadastroCandidato(int posicao, int nb, int valido, candidato *candidatos)
{
    AtualziaDadosCandidato(posicao, candidatos);

    void OrdenaCandidatos(candidato *candidatos);

    int p;
    int y = 6;
    int input;
    int dif;
    int k;
    candidato cand_aux;
    do
    {
        p = getch();
        switch(p)
        {
        case 72:
            if(y == 6)
            {
                posicionaCursor(17, y);
                printf(" ");
                y = 12;
                posicionaCursor(17, y);
                printf(">");
            }
            else
            {
                posicionaCursor(17, y);
                printf(" ");
                y--;
                posicionaCursor(17, y);
                printf(">");
            }
            break;
        case 80:
            if(y == 12)
            {
                posicionaCursor(17, y);
                printf(" ");
                y = 6;
                posicionaCursor(17, y);
                printf(">");
            }
            else
            {
                posicionaCursor(17, y);
                printf(" ");
                y++;
                posicionaCursor(17, y);
                printf(">");
            }
            break;
        case 13:
            if(y == 6)
            {
                posicionaCursor(20, 17);
                printf("Nome: ");
                strcpy(candidatos[posicao].p_candidato.nome, scannerUser(1, 21));
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
                p = 0;
            }
            else if(y == 7)
            {
                do
                {
                    posicionaCursor(20, 17);
                    printf("CPF:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                    input = scanf("%d", &candidatos[posicao].p_candidato.cpf);
                    fflush(stdin);
                }
                while(input == 0);
                p = 0;
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
            }
            else if(y == 8)
            {
                do
                {
                    posicionaCursor(20, 17);
                    printf("Data de Nascimento [dd mm aaa]:               \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
                    input = scanf("%d %d %d", &candidatos[posicao].p_candidato.nascimento.dia, &candidatos[posicao].p_candidato.nascimento.mes, &candidatos[posicao].p_candidato.nascimento.ano);
                    fflush(stdin);
                }
                while(input == 0 || candidatos[posicao].p_candidato.nascimento.dia > 31 || candidatos[posicao].p_candidato.nascimento.dia < 1 || candidatos[posicao].p_candidato.nascimento.mes < 1 || candidatos[posicao].p_candidato.nascimento.mes > 12 || candidatos[0].p_candidato.nascimento.ano < 1900 || candidatos[0].p_candidato.nascimento.ano > 3000);
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
                p = 0;
            }
            else if(y == 9)
            {
                do
                {
                    posicionaCursor(20, 17);
                    printf("Numero:           \b\b\b\b\b\b\b\b\b\b");
                    input = scanf("%d", &candidatos[posicao].numero);
                }
                while(input == 0);
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
                p = 0;
            }
            else if(y == 10)
            {
                posicionaCursor(20, 17);
                printf("Partido: ");
                strcpy(candidatos[posicao].partido, scannerUser(1, 5));
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
                p = 0;
            }
            else if(y == 11)
            {
                int dif;
                cand_aux.votos = candidatos[posicao].votos;
                do
                {
                    dif = 0;
                    posicionaCursor(20, 17);
                    printf("Votos:         \b\b\b\b\b\b\b\b");
                    fflush(stdin);
                    input = scanf("%d", &candidatos[posicao].votos);
                    dif = candidatos[posicao].votos - cand_aux.votos;
                    if(dif > nb)
                    {
                        posicionaCursor(25, 20);
                        printf("Votos Excedentes! Diferenca maxima %d", nb);
                        Sleep(1000);
                        int l;
                        for(l = 25; l < 70; l++)
                        {
                            posicionaCursor(l, 20);
                            printf(" ");
                        }
                    }
                }
                while(input == 0 || dif > nb);
                nb -= dif;
                y = 6;
                AtualziaDadosCandidato(posicao, candidatos);
                p = 0;
            }
            break;
        }
    }
    while(p != 13);
    OrdenaCandidatos(candidatos);
    atualizaCandidato(candidatos);
    return nb;
}
void OrdenaCandidatos(candidato *candidatos)
{
    int c, i;
    candidato cand_aux;
    do
    {
        c = 0;
        for(i = 0; i < 9; i++)
        {
            if(candidatos[i].votos < candidatos[i + 1].votos)
            {
                strcpy(cand_aux.p_candidato.nome, candidatos[i].p_candidato.nome);
                strcpy(candidatos[i].p_candidato.nome, candidatos[i + 1].p_candidato.nome); //nome
                strcpy(candidatos[i + 1].p_candidato.nome, cand_aux.p_candidato.nome);

                cand_aux.p_candidato.cpf = candidatos[i].p_candidato.cpf;
                candidatos[i].p_candidato.cpf = candidatos[i + 1].p_candidato.cpf; // cpf
                candidatos[i + 1].p_candidato.cpf = cand_aux.p_candidato.cpf;

                cand_aux.p_candidato.nascimento.dia = candidatos[i].p_candidato.nascimento.dia;
                candidatos[i].p_candidato.nascimento.dia = candidatos[i + 1].p_candidato.nascimento.dia; //dia
                candidatos[i + 1].p_candidato.nascimento.dia = cand_aux.p_candidato.nascimento.dia;

                cand_aux.p_candidato.nascimento.mes = candidatos[i].p_candidato.nascimento.mes;
                candidatos[i].p_candidato.nascimento.mes = candidatos[i + 1].p_candidato.nascimento.mes; //mes
                candidatos[i + 1].p_candidato.nascimento.mes = cand_aux.p_candidato.nascimento.mes;

                cand_aux.p_candidato.nascimento.ano = candidatos[i].p_candidato.nascimento.ano;
                candidatos[i].p_candidato.nascimento.ano = candidatos[i + 1].p_candidato.nascimento.ano; //ano
                candidatos[i + 1].p_candidato.nascimento.ano = cand_aux.p_candidato.nascimento.ano;

                cand_aux.numero = candidatos[i].numero;
                candidatos[i].numero = candidatos[i + 1].numero; //numero
                candidatos[i + 1].numero = cand_aux.numero;

                strcpy(cand_aux.partido, candidatos[i].partido);
                strcpy(candidatos[i].partido, candidatos[i + 1].partido); //partido
                strcpy(candidatos[i + 1].partido, cand_aux.partido);

                cand_aux.votos = candidatos[i].votos;
                candidatos[i].votos = candidatos[i + 1].votos;
                candidatos[i + 1].votos = cand_aux.votos;

                c++;
            }
        }
    }
    while(c != 0);
}

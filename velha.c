/*********************************************************************
*                  Projeto - Jogo da velha                           *
*                                                                    *
*   Gean Matos                                                       *
*   Periodo 1                                                        *
*   PUC Minas - Poços de Caldas                                      *
*********************************************************************/

#include <stdio.h>
#include <windows.h>

void posicionaCursor(short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void desenhav (short x, short y, char c)
{

    x=20;
    y=2;
    while(x <= 50)
    {
        posicionaCursor(x, 6);
        printf("%c",c);
        posicionaCursor(x, 11);
        printf("%c",c);
        x++;
    }
    while(y <= 15)
    {
        posicionaCursor(30, y);
        printf("%c%c",c,c);
        posicionaCursor(40, y);
        printf("%c%c",c,c);
        y++;
    }
}

void desenhamenu (int t)
{
    int y=8;

    //system("cls");
    posicionaCursor(30,5);
    printf("::::::::::::::::::");

    posicionaCursor(30,6);
    printf("::     MENU     ::");

    posicionaCursor(30,7);
    printf("::::::::::::::::::");

    if(t == 1)
    {
        posicionaCursor(30,8);
        printf("::    RESTART   ::");
    }
    else
    {
        posicionaCursor(30,8);
        printf("::    START     ::");
    }


    posicionaCursor(30,9);
    printf("::    QUIT      ::");

    posicionaCursor(30,10);
    printf("::::::::::::::::::");
}

void menumodo ()
{
    int y=8;

    system("cls");
    posicionaCursor(30,5);
    printf("::::::::::::::::::");

    posicionaCursor(30,6);
    printf(":: MODO DE JOGO ::");

    posicionaCursor(30,7);
    printf("::::::::::::::::::");

    posicionaCursor(30,8);
    printf("::    1 VS 1    ::");

    posicionaCursor(30,9);
    printf("::    1 VS PC   ::");



    posicionaCursor(30,10);
    printf("::    SCORE     ::");

    posicionaCursor(30,11);
    printf("::::::::::::::::::");
}

void easyhard ()
{
    system("cls");

    posicionaCursor(30,5);
    printf("::::::::::::::::::");

    posicionaCursor(30,6);
    printf("::  DIFICULDADE ::");

    posicionaCursor(30,7);
    printf("::::::::::::::::::");

    posicionaCursor(30,8);
    printf("::     EASY     ::");

    posicionaCursor(30,9);
    printf("::     HARD     ::");

    posicionaCursor(30,10);
    printf("::  IMPOSSIBLE  ::");

    posicionaCursor(30,11);
    printf("::::::::::::::::::");
}

void score (int v1, int v2, int v,int vpc, int vppc, int vvpc)
{
    system("cls");
    posicionaCursor(30,5);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(30,6);
    printf("::        SCORE         ::");

    posicionaCursor(30,7);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(30,8);
    printf(":: PLAYER 1 :: PLAYER 2 ::");

    posicionaCursor(30,9);
    printf("::    [%d]   ::     [%d]  ::",v1,v2);

    posicionaCursor(30,10);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(30,11);
    printf(":: VELHA 1 VS 1  [%d]    ::",v);

    posicionaCursor(30,12);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(30,13);
    printf(":: PC [%d]   :: PLAYER[%d]::",vpc,vppc);

    posicionaCursor(30,14);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(30,15);
    printf(":: VELHA 1 VS PC [%d]    ::",vvpc);

    posicionaCursor(30,16);
    printf("::::::::::::::::::::::::::");

    posicionaCursor(20,23);
    printf("Pressione Enter para retornar ao menu inicial.");
}


int main()
{
    //CASAS DO JOGO DA VELHA

    int c[3][3];

    //AUXILIARES
    int i,j,p,pc,compnome, op=1,vezde=1,jogo=1, turno =0,v1=0,v2=0,v=0,vpc=0, vppc=0, vvpc=0;

    //COORDENADAS
    int x=33, y=8;

    //ALOCAÇÃO DOS NOMES
    char p1[8], p2[8], cpyn [8];

    desenhamenu(2);
    posicionaCursor(33, 8);
    printf(">");


    do{

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
            if(op==1)
            {
                menumodo();
                posicionaCursor(33, 8);
                printf(">");

                p=1;
                x = 33;
                y = 8;

                while(p!= 13)
                {

                    p = getch();


                    switch(p)
                    {
                    case 72: // cima
                        if(y==8)
                        {
                        }
                        else
                        {

                            posicionaCursor(x, y);
                            printf(" ");

                            y = y -1;
                            posicionaCursor(x, y);
                            printf(">");
                        }

                        break;

                    case 80: // baixo
                        if (y == 10)
                        {
                        }
                        else
                        {
                            posicionaCursor(x, y);
                            printf(" ");

                            y = y +1;

                            posicionaCursor(x, y);
                            printf(">");
                        }
                        break;

                    case 13: // enter

                        if(y==8)
                        {
                            op=1;
                        }
                        else if (y==9)
                        {
                            op=2;
                        }
                        else
                        {
                            op=3;
                        }

                        if(op ==3)
                        {
                            score(v1,v2,v,vpc,vppc,vvpc);
                            p = getch();
                            system("cls");
                            desenhamenu(2);
                            posicionaCursor(33, 9);
                            printf(">");
                        }

                        else if(op ==2)
                        {
                            easyhard();
                            posicionaCursor(33, 9);
                            printf(">");
                            op =1;
                            p=0;

                            while (p != 13)
                            {

                                p = getch();


                                switch(p)
                                {
                                case 72: // cima
                                    if(y==8)
                                    {
                                    }
                                    else
                                    {

                                        posicionaCursor(x, y);
                                        printf(" ");

                                        y = y -1;
                                        posicionaCursor(x, y);
                                        printf(">");
                                    }

                                    break;

                                case 80: // baixo
                                    if (y == 10)
                                    {
                                    }
                                    else
                                    {
                                        posicionaCursor(x, y);
                                        printf(" ");

                                        y = y +1;

                                        posicionaCursor(x, y);
                                        printf(">");
                                    }
                                    break;

                                case 13: // enter
                                    if(y==8)
                                    {
                                        op = 1;
                                    }
                                    else if (y== 9)
                                    {
                                        op = 2;
                                    }
                                    else
                                    {
                                        op = 3;
                                    }
                                    //EASY
                                    if(op == 1)
                                    {
                                        for(i=0; i<3; i++){
                                            for(j=0; j<3; j++){
                                                c[i][j]=3;
                                            }
                                        }


                                        system ("cls");
                                        while(jogo == 1)
                                        {

                                            system ("cls");

                                            desenhav(20,2,219);

                                            while (turno < 9)
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");

                                                x=33;
                                                y= 8;

                                                posicionaCursor(x, y);
                                                printf (">");

                                                op = 0;

                                                while (op != 13)
                                                {
                                                    pc = 0;
                                                    op = getch();
                                                    switch(op)
                                                    {
                                                    case 72: // cima

                                                        if(y == 3)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y -=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }

                                                        break;

                                                    case 75: // esquerdo

                                                        if(x == 23)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x -=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 77: // direito

                                                        if(x == 43)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x +=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 80: // baixo

                                                        if(y == 13)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y +=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 13: // enter

                                                        //c[0][0]
                                                        if(x==23 && y==3)
                                                        {
                                                            if (c[0][0]==3)
                                                            {

                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][0] = 0;
                                                            }
                                                            else
                                                            {

                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][1]
                                                        else if(x==33 && y==3)
                                                        {
                                                            if (c[0][1] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][2]
                                                        else if(x==43 && y==3)
                                                        {
                                                            if (c[0][2] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==23 && y==8)
                                                        {
                                                            if (c[1][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==33 && y==8)
                                                        {
                                                            if (c[1][1]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][2]
                                                        else if(x==43 && y==8)
                                                        {
                                                            if (c[1][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][0]
                                                        else if(x==23 && y==13)
                                                        {
                                                            if (c[2][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][1]
                                                        else if(x==33 && y==13)
                                                        {
                                                            if (c[2][1]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][2]
                                                        else if(x==43 && y==13)
                                                        {
                                                            if (c[2][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }


                                                        break;
                                                    }
                                                }
                                                if (pc == 0)
                                                {

                                                    //PRIMEIRA LINHA
                                                    if(c[0][0] == 0 && c[0][1] == 0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[0][2] == 0 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 0 && c[0][2] == 0 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //SEGUNDA
                                                    else if(c[1][0] == 0 && c[1][1] == 0 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");

                                                    }
                                                    else if(c[1][0] == 0 && c[1][2] == 0 && c[1][1] ==3)
                                                    {
                                                        c[1][1] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][1] == 0 && c[1][2] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }

                                                    //TERCEIRA
                                                    else if(c[2][0] == 0 && c[2][1] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][0] == 0 && c[2][2] == 0 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][1] == 0 && c[2][2] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }

                                                    //QUARTA
                                                    else if(c[0][0] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }


                                                    //QUINTA
                                                    else if(c[0][1] == 0 && c[1][0] == 0 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 0 && c[2][1] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][1] ==0 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }


                                                    //SEXTA
                                                    else if(c[0][2] == 0 && c[1][2] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 0 && c[2][2] == 0 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][2] == 0 && c[2][2] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }


                                                    //SETIMA

                                                    else if(c[0][0] == 0 && c[1][0] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[2][2] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][2] ==0 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //OITAVA
                                                    else if(c[0][2] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else
                                                    {
                                                        //PRIMEIRA LINHA
                                                        if(c[0][0] == 1 && c[0][1] == 1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[0][2] == 1 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 1 && c[0][2] == 1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //SEGUNDA
                                                        else if(c[1][0] == 1 && c[1][0] == 1 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");

                                                        }
                                                        else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }

                                                        //TERCEIRA
                                                        else if(c[2][0] == 1 && c[2][1] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][0] == 1 && c[2][2] == 1 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][1] == 1 && c[2][2] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }

                                                        //QUARTA
                                                        else if(c[0][0] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][0] ==1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }


                                                        //QUINTA
                                                        else if(c[0][1] == 1 && c[1][0] == 1 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 1 && c[2][1] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][1] ==1 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }


                                                        //SEXTA
                                                        else if(c[0][2] == 1 && c[1][2] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 1 && c[2][2] == 1 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][2] == 1 && c[2][2] ==1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }


                                                        //SETIMA

                                                        else if(c[0][0] == 1 && c[1][0] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[2][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][2] ==1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //OITAVA
                                                        else if(c[0][2] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][0] ==1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else
                                                        {
                                                            if(c[0][0]==3)
                                                            {
                                                                c[0][0]=1;
                                                                posicionaCursor(25,3);
                                                                printf("O");
                                                            }
                                                            else if(c[0][1]==3)
                                                            {
                                                                c[0][1]=1;
                                                                posicionaCursor(35,3);
                                                                printf("O");
                                                            }
                                                            else if(c[0][2]==3)
                                                            {
                                                                c[0][2]=1;
                                                                posicionaCursor(45,3);
                                                                printf("O");
                                                            }
                                                            else if(c[1][0]==3)
                                                            {
                                                                c[1][0]=1;
                                                                posicionaCursor(25,8);
                                                                printf("O");
                                                            }
                                                            else if(c[1][0]==3)
                                                            {
                                                                c[1][0]=1;
                                                                posicionaCursor(35,8);
                                                                printf("O");
                                                            }
                                                            else if(c[1][2]==3)
                                                            {
                                                                c[1][2]=1;
                                                                posicionaCursor(45,8);
                                                                printf("O");
                                                            }
                                                            else if(c[2][0]==3)
                                                            {
                                                                c[2][0]=1;
                                                                posicionaCursor(25,13);
                                                                printf("O");
                                                            }
                                                            else if(c[2][1]==3)
                                                            {
                                                                c[2][1]=1;
                                                                posicionaCursor(35,13);
                                                                printf("O");
                                                            }
                                                            else if(c[2][2]==3)
                                                            {
                                                                c[2][2]=1;
                                                                posicionaCursor(45,13);
                                                                printf("O");
                                                            }

                                                        }
                                                    }
                                                }

                                                turno ++;

                                                if(c[0][0]==0 && c[0][1]==0 && c[0][2]==0 || c[1][0]==0 && c[1][0]==0 && c[1][2]==0 || c[2][0]==0 && c[2][1]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][0]==0 || c[0][1]==0 && c[1][0]==0 && c[2][1]==0 || c[0][2]==0 && c[1][2]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][2]==0 || c[0][2]==0 && c[1][0]==0 && c[2][0]==0)
                                                {
                                                    turno=10;
                                                    jogo = 0;
                                                    vppc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO JOGADOR!");
                                                }
                                                else if(c[0][0]==1 && c[0][1]==1 && c[0][2]==1 || c[1][0]==1 && c[1][0]==1 && c[1][2]==1 || c[2][0]==1 && c[2][1]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][0]==1 || c[0][1]==1 && c[1][0]==1 && c[2][1]==1 || c[0][2]==1 && c[1][2]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][2]==1 || c[0][2]==1 && c[1][0]==1 && c[2][0]==1)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO PC!");

                                                }
                                                else if( c[0][0]!=3 && c[0][1]!=3 && c[0][2]!=3 && c[1][0]!=3 && c[1][0]!=3 && c[1][2]!=3 && c[2][0]!=3 && c[2][1]!=3 && c[2][2]!=3)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vvpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VELHA!");

                                                }


                                            }


                                        }
                                        //fim do jogo
                                        op = 0;
                                        desenhamenu(1);
                                        posicionaCursor(33, 9);
                                        printf(">");
                                        turno = 0;
                                        jogo = 1;
                                    }
                                    //HARD
                                    else if(op == 2)
                                    {

                                        for(i=0; i<3; i++){
                                            for(j=0; j<3; j++){
                                                c[i][j]=3;
                                            }
                                        }

                                        system ("cls");
                                        while(jogo == 1)
                                        {

                                            system ("cls");

                                            desenhav(20,2,219);

                                            while (turno < 9)
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");

                                                x=33;
                                                y= 8;

                                                posicionaCursor(x, y);
                                                printf (">");

                                                op = 0;

                                                while (op != 13)
                                                {
                                                    pc = 0;
                                                    op = getch();
                                                    switch(op)
                                                    {
                                                    case 72: // cima

                                                        if(y == 3)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y -=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }

                                                        break;

                                                    case 75: // esquerdo

                                                        if(x == 23)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x -=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 77: // direito

                                                        if(x == 43)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x +=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 80: // baixo

                                                        if(y == 13)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y +=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 13: // enter

                                                        //c[0][0]
                                                        if(x==23 && y==3)
                                                        {
                                                            if (c[0][0]==3)
                                                            {

                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][0] = 0;
                                                            }
                                                            else
                                                            {

                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][1]
                                                        else if(x==33 && y==3)
                                                        {
                                                            if (c[0][1] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][2]
                                                        else if(x==43 && y==3)
                                                        {
                                                            if (c[0][2] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==23 && y==8)
                                                        {
                                                            if (c[1][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==33 && y==8)
                                                        {
                                                            if (c[1][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][2]
                                                        else if(x==43 && y==8)
                                                        {
                                                            if (c[1][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][0]
                                                        else if(x==23 && y==13)
                                                        {
                                                            if (c[2][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][1]
                                                        else if(x==33 && y==13)
                                                        {
                                                            if (c[2][1]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][2]
                                                        else if(x==43 && y==13)
                                                        {
                                                            if (c[2][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }


                                                        break;
                                                    }
                                                }
                                                if (pc == 0)
                                                {


                                                        //PRIMEIRA LINHA
                                                        if(c[0][0] == 1 && c[0][1] == 1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[0][2] == 1 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 1 && c[0][2] == 1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //SEGUNDA
                                                        else if(c[1][0] == 1 && c[1][0] == 1 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");

                                                        }
                                                        else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }

                                                        //TERCEIRA
                                                        else if(c[2][0] == 1 && c[2][1] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][0] == 1 && c[2][2] == 1 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][1] == 1 && c[2][2] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }

                                                        //QUARTA
                                                        else if(c[0][0] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][0] ==1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }


                                                        //QUINTA
                                                        else if(c[0][1] == 1 && c[1][0] == 1 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 1 && c[2][1] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][1] ==1 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }


                                                        //SEXTA
                                                        else if(c[0][2] == 1 && c[1][2] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 1 && c[2][2] == 1 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][2] == 1 && c[2][2] ==1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }


                                                        //SETIMA

                                                        else if(c[0][0] == 1 && c[1][0] == 1 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 1 && c[2][2] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][2] ==1 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //OITAVA
                                                        else if(c[0][2] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 1 && c[2][0] ==1 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else
                                                        {
                                                            //PRIMEIRA LINHA
                                                    if(c[0][0] == 0 && c[0][1] == 0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[0][2] == 0 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 0 && c[0][2] == 0 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //SEGUNDA
                                                    else if(c[1][0] == 0 && c[1][0] == 0 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");

                                                    }
                                                    else if(c[1][0] == 0 && c[1][2] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[1][2] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }

                                                    //TERCEIRA
                                                    else if(c[2][0] == 0 && c[2][1] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][0] == 0 && c[2][2] == 0 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][1] == 0 && c[2][2] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }

                                                    //QUARTA
                                                    else if(c[0][0] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }


                                                    //QUINTA
                                                    else if(c[0][1] == 0 && c[1][0] == 0 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 0 && c[2][1] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][1] ==0 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }


                                                    //SEXTA
                                                    else if(c[0][2] == 0 && c[1][2] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 0 && c[2][2] == 0 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][2] == 0 && c[2][2] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }


                                                    //SETIMA

                                                    else if(c[0][0] == 0 && c[1][0] == 0 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 0 && c[2][2] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][2] ==0 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //OITAVA
                                                    else if(c[0][2] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else
                                                    {
                                                            if(c[0][0] ==0 && c[0][1] == 1 && c[0][2] == 0 && c[1][0] == 3 || c[2][0] == 0 && c[2][1] == 1 && c[2][2] == 0 && c[1][0] == 3)
                                                            {
                                                                c[1][0] = 1;
                                                                posicionaCursor(35,8);
                                                                printf("O");
                                                            }
                                                            else if(c[2][0] == 0 && c[1][0] == 1 && c[0][2] ==0 && c[2][2] == 3)
                                                            {
                                                                c[2][2] = 1;
                                                                posicionaCursor(45,13);
                                                                printf("O");
                                                            }
                                                            else if(c[2][2] == 0 && c[1][0] == 1 && c[0][0] ==0 && c[2][0] == 3)
                                                            {
                                                                c[2][0] = 1;
                                                                posicionaCursor(25,13);
                                                                printf("O");
                                                            }

                                                            else
                                                            {
                                                                if(c[1][0]==3)
                                                                {
                                                                    c[1][0]=1;
                                                                    posicionaCursor(35,8);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][0]==3)
                                                                {
                                                                    c[0][0]=1;
                                                                    posicionaCursor(25,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][1]==3)
                                                                {
                                                                    c[0][1]=1;
                                                                    posicionaCursor(35,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][2]==3)
                                                                {
                                                                    c[0][2]=1;
                                                                    posicionaCursor(45,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[1][0]==3)
                                                                {
                                                                    c[1][0]=1;
                                                                    posicionaCursor(25,8);
                                                                    printf("O");
                                                                }

                                                                else if(c[1][2]==3)
                                                                {
                                                                    c[1][2]=1;
                                                                    posicionaCursor(45,8);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][0]==3)
                                                                {
                                                                    c[2][0]=1;
                                                                    posicionaCursor(25,13);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][1]==3)
                                                                {
                                                                    c[2][1]=1;
                                                                    posicionaCursor(35,13);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][2]==3)
                                                                {
                                                                    c[2][2]=1;
                                                                    posicionaCursor(45,13);
                                                                    printf("O");
                                                                }

                                                            }


                                                        }
                                                    }
                                                }

                                                turno ++;

                                                if(c[0][0]==0 && c[0][1]==0 && c[0][2]==0 || c[1][0]==0 && c[1][0]==0 && c[1][2]==0 || c[2][0]==0 && c[2][1]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][0]==0 || c[0][1]==0 && c[1][0]==0 && c[2][1]==0 || c[0][2]==0 && c[1][2]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][2]==0 || c[0][2]==0 && c[1][0]==0 && c[2][0]==0)
                                                {
                                                    turno=10;
                                                    jogo = 0;
                                                    vppc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO JOGADOR!");
                                                }
                                                else if(c[0][0]==1 && c[0][1]==1 && c[0][2]==1 || c[1][0]==1 && c[1][0]==1 && c[1][2]==1 || c[2][0]==1 && c[2][1]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][0]==1 || c[0][1]==1 && c[1][0]==1 && c[2][1]==1 || c[0][2]==1 && c[1][2]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][2]==1 || c[0][2]==1 && c[1][0]==1 && c[2][0]==1)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO PC!");

                                                }
                                                else if( c[0][0]!=3 && c[0][1]!=3 && c[0][2]!=3 && c[1][0]!=3 && c[1][0]!=3 && c[1][2]!=3 && c[2][0]!=3 && c[2][1]!=3 && c[2][2]!=3)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vvpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VELHA!");

                                                }


                                            }


                                        }
                                        //fim do jogo
                                        op = 0;
                                        desenhamenu(1);
                                        posicionaCursor(33, 9);
                                        printf(">");
                                        turno = 0;
                                        jogo = 1;
                                    }
                                    //IMPOSSIBLE
                                    else if(op == 3)
                                    {
                                        for(i=0; i<3; i++){
                                            for(j=0; j<3; j++){
                                                c[i][j]=3;
                                            }
                                        }

                                        system ("cls");
                                        while(jogo == 1)
                                        {

                                            system ("cls");

                                            desenhav(20,2,219);

                                            while (turno < 9)
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");

                                                x=33;
                                                y= 8;

                                                posicionaCursor(x, y);
                                                printf (">");

                                                op = 0;

                                                while (op != 13)
                                                {
                                                    pc = 0;
                                                    op = getch();
                                                    switch(op)
                                                    {
                                                    case 72: // cima

                                                        if(y == 3)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y -=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }

                                                        break;

                                                    case 75: // esquerdo

                                                        if(x == 23)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x -=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 77: // direito

                                                        if(x == 43)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            x +=10;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 80: // baixo

                                                        if(y == 13)
                                                        {
                                                            printf("\a");
                                                        }
                                                        else
                                                        {
                                                            posicionaCursor(x, y);
                                                            printf (" ");
                                                            y +=5;
                                                            posicionaCursor(x, y);
                                                            printf(">");
                                                        }


                                                        break;
                                                    case 13: // enter

                                                        //c[0][0]
                                                        if(x==23 && y==3)
                                                        {
                                                            if (c[0][0]==3)
                                                            {

                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][0] = 0;
                                                            }
                                                            else
                                                            {

                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][1]
                                                        else if(x==33 && y==3)
                                                        {
                                                            if (c[0][1] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[0][2]
                                                        else if(x==43 && y==3)
                                                        {
                                                            if (c[0][2] == 3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[0][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==23 && y==8)
                                                        {
                                                            if (c[1][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][0]
                                                        else if(x==33 && y==8)
                                                        {
                                                            if (c[1][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[1][2]
                                                        else if(x==43 && y==8)
                                                        {
                                                            if (c[1][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[1][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][0]
                                                        else if(x==23 && y==13)
                                                        {
                                                            if (c[2][0]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][0] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][1]
                                                        else if(x==33 && y==13)
                                                        {
                                                            if (c[2][1]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][1] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }

                                                        //c[2][2]
                                                        else if(x==43 && y==13)
                                                        {
                                                            if (c[2][2]==3)
                                                            {
                                                                posicionaCursor(x+2, y);
                                                                printf ("X");

                                                                c[2][2] = 0;
                                                            }
                                                            else
                                                            {
                                                                pc = 1;
                                                                turno --;
                                                                printf("\a");
                                                            }
                                                        }


                                                        break;
                                                    }
                                                }
                                                if (pc == 0)
                                                {


                                                    //PRIMEIRA LINHA
                                                    if(c[0][0] == 1 && c[0][1] == 1 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 1 && c[0][2] == 1 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 1 && c[0][2] == 1 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //SEGUNDA
                                                    else if(c[1][0] == 1 && c[1][0] == 1 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");

                                                    }
                                                    else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 1 && c[1][2] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }

                                                    //TERCEIRA
                                                    else if(c[2][0] == 1 && c[2][1] == 1 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][0] == 1 && c[2][2] == 1 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[2][1] == 1 && c[2][2] == 1 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }

                                                    //QUARTA
                                                    else if(c[0][0] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(25,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 1 && c[2][0] ==1 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }


                                                    //QUINTA
                                                    else if(c[0][1] == 1 && c[1][0] == 1 && c[2][1] ==3)
                                                    {
                                                        c[2][1] = 1;
                                                        posicionaCursor(35,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][1] == 1 && c[2][1] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 1 && c[2][1] ==1 && c[0][1] ==3)
                                                    {
                                                        c[0][1] = 1;
                                                        posicionaCursor(35,3);
                                                        printf("O");
                                                    }


                                                    //SEXTA
                                                    else if(c[0][2] == 1 && c[1][2] == 1 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 1 && c[2][2] == 1 && c[1][2] ==3)
                                                    {
                                                        c[1][2] = 1;
                                                        posicionaCursor(45,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][2] == 1 && c[2][2] ==1 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }


                                                    //SETIMA

                                                    else if(c[0][0] == 1 && c[1][0] == 1 && c[2][2] ==3)
                                                    {
                                                        c[2][2] = 1;
                                                        posicionaCursor(45,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][0] == 1 && c[2][2] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 1 && c[2][2] ==1 && c[0][0] ==3)
                                                    {
                                                        c[0][0] = 1;
                                                        posicionaCursor(25,3);
                                                        printf("O");
                                                    }

                                                    //OITAVA
                                                    else if(c[0][2] == 1 && c[1][0] == 1 && c[2][0] ==3)
                                                    {
                                                        c[2][0] = 1;
                                                        posicionaCursor(25,13);
                                                        printf("O");
                                                    }
                                                    else if(c[0][2] == 1 && c[2][0] == 1 && c[1][0] ==3)
                                                    {
                                                        c[1][0] = 1;
                                                        posicionaCursor(35,8);
                                                        printf("O");
                                                    }
                                                    else if(c[1][0] == 1 && c[2][0] ==1 && c[0][2] ==3)
                                                    {
                                                        c[0][2] = 1;
                                                        posicionaCursor(45,3);
                                                        printf("O");
                                                    }
                                                    else
                                                    {
                                                        //PRIMEIRA LINHA
                                                        if(c[0][0] == 0 && c[0][1] == 0 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 0 && c[0][2] == 0 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 0 && c[0][2] == 0 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //SEGUNDA
                                                        else if(c[1][0] == 0 && c[1][0] == 0 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");

                                                        }
                                                        else if(c[1][0] == 0 && c[1][2] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 0 && c[1][2] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }

                                                        //TERCEIRA
                                                        else if(c[2][0] == 0 && c[2][1] == 0 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][0] == 0 && c[2][2] == 0 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[2][1] == 0 && c[2][2] == 0 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }

                                                        //QUARTA
                                                        else if(c[0][0] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(25,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }


                                                        //QUINTA
                                                        else if(c[0][1] == 0 && c[1][0] == 0 && c[2][1] ==3)
                                                        {
                                                            c[2][1] = 1;
                                                            posicionaCursor(35,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][1] == 0 && c[2][1] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 0 && c[2][1] ==0 && c[0][1] ==3)
                                                        {
                                                            c[0][1] = 1;
                                                            posicionaCursor(35,3);
                                                            printf("O");
                                                        }


                                                        //SEXTA
                                                        else if(c[0][2] == 0 && c[1][2] == 0 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 0 && c[2][2] == 0 && c[1][2] ==3)
                                                        {
                                                            c[1][2] = 1;
                                                            posicionaCursor(45,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][2] == 0 && c[2][2] ==0 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }


                                                        //SETIMA

                                                        else if(c[0][0] == 0 && c[1][0] == 0 && c[2][2] ==3)
                                                        {
                                                            c[2][2] = 1;
                                                            posicionaCursor(45,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][0] == 0 && c[2][2] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 0 && c[2][2] ==0 && c[0][0] ==3)
                                                        {
                                                            c[0][0] = 1;
                                                            posicionaCursor(25,3);
                                                            printf("O");
                                                        }

                                                        //OITAVA
                                                        else if(c[0][2] == 0 && c[1][0] == 0 && c[2][0] ==3)
                                                        {
                                                            c[2][0] = 1;
                                                            posicionaCursor(25,13);
                                                            printf("O");
                                                        }
                                                        else if(c[0][2] == 0 && c[2][0] == 0 && c[1][0] ==3)
                                                        {
                                                            c[1][0] = 1;
                                                            posicionaCursor(35,8);
                                                            printf("O");
                                                        }
                                                        else if(c[1][0] == 0 && c[2][0] ==0 && c[0][2] ==3)
                                                        {
                                                            c[0][2] = 1;
                                                            posicionaCursor(45,3);
                                                            printf("O");
                                                        }
                                                        else
                                                        {
                                                            if(c[0][0] ==0 && c[0][1] == 1 && c[0][2] == 0 && c[1][0] == 3 || c[2][0] == 0 && c[2][1] == 1 && c[2][2] == 0 && c[1][0] == 3)
                                                            {
                                                                c[1][0] = 1;
                                                                posicionaCursor(35,8);
                                                                printf("O");
                                                            }
                                                            else if(c[2][0] == 0 && c[1][0] == 1 && c[0][2] ==0 && c[2][2] == 3)
                                                            {
                                                                c[2][2] = 1;
                                                                posicionaCursor(45,13);
                                                                printf("O");
                                                            }
                                                            else if(c[2][2] == 0 && c[1][0] == 1 && c[0][0] ==0 && c[2][0] == 3)
                                                            {
                                                                c[2][0] = 1;
                                                                posicionaCursor(25,13);
                                                                printf("O");
                                                            }

                                                            else if(c[0][0]==0 && c[0][1] ==3 && c[0][2] == 3 && c[1][0] ==3 && c[1][0] ==3 && c[2][0]==3 && c[2][1] == 3 && c[2][2] == 3|| c[0][2] == 0 && c[0][0]==3 && c[0][1] ==3 && c[1][0] ==3 && c[1][0] ==3 && c[2][0]==3 && c[2][1] == 3 && c[2][2] == 3)
                                                            {
                                                                c[0][1] = 1;
                                                                posicionaCursor(35,3);
                                                                printf("O");
                                                            }
                                                            else if(c[0][0]==3 && c[0][1] ==3 && c[0][2] == 3 && c[1][0] ==3 && c[1][0] ==3 && c[2][0]==0 && c[2][1] == 3  && c[2][2] == 3 || c[0][2] == 3 && c[0][0]==3 && c[0][1] ==3 && c[1][0] ==3 && c[1][0] ==3 && c[2][0]==3 && c[2][1] == 3 && c[2][2] == 0)
                                                            {
                                                                c[2][1] = 1;
                                                                posicionaCursor(35,13);
                                                                printf("O");
                                                            }

                                                            else
                                                            {
                                                                if(c[1][0]==3)
                                                                {
                                                                    c[1][0]=1;
                                                                    posicionaCursor(35,8);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][0]==3)
                                                                {
                                                                    c[0][0]=1;
                                                                    posicionaCursor(25,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][1]==3)
                                                                {
                                                                    c[0][1]=1;
                                                                    posicionaCursor(35,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[0][2]==3)
                                                                {
                                                                    c[0][2]=1;
                                                                    posicionaCursor(45,3);
                                                                    printf("O");
                                                                }
                                                                else if(c[1][0]==3)
                                                                {
                                                                    c[1][0]=1;
                                                                    posicionaCursor(25,8);
                                                                    printf("O");
                                                                }

                                                                else if(c[1][2]==3)
                                                                {
                                                                    c[1][2]=1;
                                                                    posicionaCursor(45,8);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][0]==3)
                                                                {
                                                                    c[2][0]=1;
                                                                    posicionaCursor(25,13);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][1]==3)
                                                                {
                                                                    c[2][1]=1;
                                                                    posicionaCursor(35,13);
                                                                    printf("O");
                                                                }
                                                                else if(c[2][2]==3)
                                                                {
                                                                    c[2][2]=1;
                                                                    posicionaCursor(45,13);
                                                                    printf("O");
                                                                }

                                                            }


                                                        }
                                                    }
                                                }

                                                turno ++;

                                                if(c[0][0]==0 && c[0][1]==0 && c[0][2]==0 || c[1][0]==0 && c[1][0]==0 && c[1][2]==0 || c[2][0]==0 && c[2][1]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][0]==0 || c[0][1]==0 && c[1][0]==0 && c[2][1]==0 || c[0][2]==0 && c[1][2]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][2]==0 || c[0][2]==0 && c[1][0]==0 && c[2][0]==0)
                                                {
                                                    turno=10;
                                                    jogo = 0;
                                                    vppc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO JOGADOR!");
                                                }
                                                else if(c[0][0]==1 && c[0][1]==1 && c[0][2]==1 || c[1][0]==1 && c[1][0]==1 && c[1][2]==1 || c[2][0]==1 && c[2][1]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][0]==1 || c[0][1]==1 && c[1][0]==1 && c[2][1]==1 || c[0][2]==1 && c[1][2]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][2]==1 || c[0][2]==1 && c[1][0]==1 && c[2][0]==1)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VITORIA DO PC!");

                                                }
                                                else if( c[0][0]!=3 && c[0][1]!=3 && c[0][2]!=3 && c[1][0]!=3 && c[1][0]!=3 && c[1][2]!=3 && c[2][0]!=3 && c[2][1]!=3 && c[2][2]!=3)
                                                {
                                                    turno =10;
                                                    jogo = 0;
                                                    vvpc ++;
                                                    system("cls");
                                                    posicionaCursor(30,2);
                                                    printf("VELHA!");

                                                }


                                            }


                                        }
                                        //fim do jogo
                                        op = 0;
                                        desenhamenu(1);
                                        posicionaCursor(33, 9);
                                        printf(">");
                                        turno = 0;
                                        jogo = 1;

                                    }
                                    break;
                                }
                            }
                        }

                        else if(op ==1)
                        {


                                        for(i=0; i<3; i++){
                                            for(j=0; j<3; j++){
                                                c[i][j]=3;
                                            }
                                        }

                            system ("cls");
                            while(jogo == 1)
                            {
                                //RECEBE OS NOMES DOS JOGADORES
                                posicionaCursor(30,3);
                                printf("Nickname Player 1: ");
                                scanf("%s", p1);
                                system("cls");

                                //VERIFICA O TAMANHO DO NOME DO PLAER 1
                                if(strlen(p1) > 8)
                                {

                                    while(strlen(p1) > 8)
                                    {
                                        system("cls");
                                        posicionaCursor(30,3);
                                        printf("NICKNAME INVALIDO!");
                                        posicionaCursor(21,5);
                                        printf( "Maximo de 8 caracteres.");
                                        posicionaCursor(21,7);
                                        printf( "porfavor redigite o nickname do Player 1.");
                                        posicionaCursor(21,9);
                                        printf("Novo nickname: ");
                                        scanf("%s", p1);

                                    }

                                }
                                strcpy(cpyn,p1);

                                system("cls");
                                posicionaCursor(30,3);
                                printf("Nickname Player 2: ");
                                scanf("%s", p2);
                                system("cls");

                                //VERIFICA O TAMANHO DO NOME DO PLAER 2
                                if(strlen(p2) > 8)
                                {


                                    while(strlen(p2) > 8)
                                    {
                                        system("cls");
                                        posicionaCursor(30,3);
                                        printf("NICKNAME INVALIDO!");
                                        posicionaCursor(21,5);
                                        printf( "Maximo de 8 caracteres.");
                                        posicionaCursor(21,7);
                                        printf( "porfavor redigite o nickname do Player 2.");
                                        posicionaCursor(21,9);
                                        printf("Novo nickname: ");
                                        scanf("%s", p2);
                                    }
                                    strcpy(p1,cpyn);
                                }

                                compnome = strcasecmp(p1,p2);

                                //VERIFICA SE OS NOMES SAO IGUAIS
                                if ( compnome == 0 )
                                {
                                    while(compnome == 0)
                                    {
                                        system("cls");
                                        posicionaCursor(30,3);
                                        printf("NICKNAME INVALIDO!");
                                        posicionaCursor(22,5);
                                        printf( "Nao pode haver dois nicknames identicos.");
                                        posicionaCursor(21,7);
                                        printf( "porfavor redigite o nickname do Player 2:");
                                        posicionaCursor(26,9);
                                        printf("Player 1 :%s",p1);
                                        posicionaCursor(26,10);
                                        printf("Player 2 :");
                                        scanf("%s", p2);
                                        compnome = strcasecmp(p1,p2);
                                    }
                                }

                                system ("cls");

                                desenhav(20,2,219);


                                while (turno < 9)
                                {
                                    if (vezde == 1)
                                    {
                                        posicionaCursor(20,0);
                                        printf("                                                                    ");
                                        posicionaCursor(20,0);
                                        printf("Turno de %s:",p1);
                                    }
                                    else
                                    {
                                        posicionaCursor(20,0);
                                        printf("                                                                    ");
                                        posicionaCursor(20,0);
                                        printf("Turno de %s:",p2);
                                    }

                                    posicionaCursor(x, y);
                                    printf (" ");

                                    x=33;
                                    y= 8;

                                    posicionaCursor(x, y);
                                    printf (">");

                                    op = 0;

                                    while (op != 13)
                                    {
                                        op = getch();
                                        switch(op)
                                        {
                                        case 72: // cima

                                            if(y == 3)
                                            {
                                                printf("\a");
                                            }
                                            else
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");
                                                y -=5;
                                                posicionaCursor(x, y);
                                                printf(">");
                                            }

                                            break;

                                        case 75: // esquerdo

                                            if(x == 23)
                                            {
                                                printf("\a");
                                            }
                                            else
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");
                                                x -=10;
                                                posicionaCursor(x, y);
                                                printf(">");
                                            }


                                            break;
                                        case 77: // direito

                                            if(x == 43)
                                            {
                                                printf("\a");
                                            }
                                            else
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");
                                                x +=10;
                                                posicionaCursor(x, y);
                                                printf(">");
                                            }


                                            break;
                                        case 80: // baixo

                                            if(y == 13)
                                            {
                                                printf("\a");
                                            }
                                            else
                                            {
                                                posicionaCursor(x, y);
                                                printf (" ");
                                                y +=5;
                                                posicionaCursor(x, y);
                                                printf(">");
                                            }


                                            break;
                                        case 13: // enter

                                            //c[0][0]
                                            if(x==23 && y==3)
                                            {
                                                if (vezde == 1 && c[0][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[0][0] = 0;
                                                }
                                                else if (c[0][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[0][0] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[0][1]
                                            else if(x==33 && y==3)
                                            {
                                                if (vezde == 1 && c[0][1] == 3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[0][1] = 0;
                                                }
                                                else if (c[0][1]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[0][1] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[0][2]
                                            else if(x==43 && y==3)
                                            {
                                                if (vezde == 1 && c[0][2] == 3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[0][2] = 0;
                                                }
                                                else if (c[0][2] == 3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[0][2] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[1][0]
                                            else if(x==23 && y==8)
                                            {
                                                if (vezde == 1 && c[1][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[1][0] = 0;
                                                }
                                                else if (c[1][0] ==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[1][0] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[1][0]
                                            else if(x==33 && y==8)
                                            {
                                                if (vezde == 1 && c[1][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[1][0] = 0;
                                                }
                                                else if (c[1][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[1][0] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[1][2]
                                            else if(x==43 && y==8)
                                            {
                                                if (vezde == 1 && c[1][2]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[1][2] = 0;
                                                }
                                                else if (c[1][2]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[1][2] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[2][0]
                                            else if(x==23 && y==13)
                                            {
                                                if (vezde == 1 && c[2][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[2][0] = 0;
                                                }
                                                else if (c[2][0]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[2][0] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[2][1]
                                            else if(x==33 && y==13)
                                            {
                                                if (vezde == 1 && c[2][1]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[2][1] = 0;
                                                }
                                                else if (c[2][1]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[2][1] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //c[2][2]
                                            else if(x==43 && y==13)
                                            {
                                                if (vezde == 1 && c[2][2]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("X");

                                                    c[2][2] = 0;
                                                }
                                                else if(c[2][2]==3)
                                                {
                                                    posicionaCursor(x+2, y);
                                                    printf ("O");

                                                    c[2][2] = 1;
                                                }
                                                else
                                                {
                                                    if (vezde == 1)
                                                    {
                                                        vezde = 2;
                                                    }
                                                    else
                                                    {
                                                        vezde = 1;
                                                    }
                                                    turno --;
                                                    printf("\a");
                                                }
                                            }

                                            //ALTERNA ENTRE UM JOGADOR E OUTRO
                                            if (vezde == 1)
                                            {
                                                vezde = 2;
                                            }
                                            else
                                            {
                                                vezde = 1;
                                            }

                                            break;
                                        }
                                    }

                                    turno ++;

                                    if(c[0][0]==0 && c[0][1]==0 && c[0][2]==0 || c[1][0]==0 && c[1][0]==0 && c[1][2]==0 || c[2][0]==0 && c[2][1]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][0]==0 || c[0][1]==0 && c[1][0]==0 && c[2][1]==0 || c[0][2]==0 && c[1][2]==0 && c[2][2]==0 || c[0][0]==0 && c[1][0]==0 && c[2][2]==0 || c[0][2]==0 && c[1][0]==0 && c[2][0]==0)
                                    {
                                        turno=10;
                                        jogo = 0;
                                        v1 ++;
                                        system("cls");
                                        posicionaCursor(30,2);
                                        printf("VITORIA DE %s!",p1);
                                    }
                                    else if(c[0][0]==1 && c[0][1]==1 && c[0][2]==1 || c[1][0]==1 && c[1][0]==1 && c[1][2]==1 || c[2][0]==1 && c[2][1]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][0]==1 || c[0][1]==1 && c[1][0]==1 && c[2][1]==1 || c[0][2]==1 && c[1][2]==1 && c[2][2]==1 || c[0][0]==1 && c[1][0]==1 && c[2][2]==1 || c[0][2]==1 && c[1][0]==1 && c[2][0]==1)
                                    {
                                        turno =10;
                                        jogo = 0;
                                        v2 ++;
                                        system("cls");
                                        posicionaCursor(30,2);
                                        printf("VITORIA DE %s!",p2);

                                    }
                                    else if( c[0][0]!=3 && c[0][1]!=3 && c[0][2]!=3 && c[1][0]!=3 && c[1][0]!=3 && c[1][2]!=3 && c[2][0]!=3 && c[2][1]!=3 && c[2][2]!=3)
                                    {
                                        jogo = 0;
                                        v ++;
                                        system("cls");
                                        posicionaCursor(30,2);
                                        printf("VELHA!");

                                    }

                                }


                            }
                            //fim do jogo
                            op = 1;
                            desenhamenu(1);
                            posicionaCursor(33, 8);
                            printf(">");

                            if(op == 1)
                            {
                                jogo = 1;
                                turno = 0;
                            }
                        }
                    }
                }
            }

            else
            {
                p = 0;
                system("cls");
                posicionaCursor(33, 8);
                printf("VOLTE LOGO!\n\n\n\n\n\n\n\n");
                posicionaCursor(0, 23);
                printf("by: Gean Matos");
                printf("\n\n");
                posicionaCursor(0, 0);
            }
            break;
        }
    }while (p != 0);
}

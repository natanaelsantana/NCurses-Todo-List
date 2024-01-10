#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"
#include "Logos.h"
#include "MenuFunctions.h"

/*
Projeto feito por: Gabriel Santana e Natanael Lima
Data do Início: 12/12/2023
Data do Término:

  Para compilar e executar vá até o diretório correspondente e digite:

    "make"

  "./todolist.x"
*/

int menu(int xmaxstdscr, int ymaxstdscr, WINDOW *janelaEscolhas, WINDOW *janelaLogo)
{

    int escolha, contadorDeMenu = 1;

    keypad(janelaEscolhas, true); // inicia as teclas do teclado.

    wprintw(janelaLogo, "%s", logoMenu);
    mvwprintw(janelaEscolhas, 1, 4, "Sign up");
    mvwprintw(janelaEscolhas, 2, 4, "Sign in");
    mvwprintw(janelaEscolhas, 3, 4, "About the project");
    mvwprintw(janelaEscolhas, 4, 4, "Exit");
    mvwprintw(stdscr, (ymaxstdscr - 2), (xmaxstdscr / 1.3), "Made by: Gabriel Santana and Natanael Lima");

    wrefresh(janelaEscolhas);
    wrefresh(janelaLogo);
    refresh();

    mvwprintw(janelaEscolhas, contadorDeMenu, 2, "->"); // posiciona a seta no inicio
    wrefresh(janelaEscolhas);

    while (1)
    {
        escolha = wgetch(janelaEscolhas);

        switch (escolha)
        {
        case KEY_DOWN:
            mvwprintw(janelaEscolhas, contadorDeMenu, 2, "  "); // apaga a seta
            contadorDeMenu++;
            if (contadorDeMenu > 4)
            {
                contadorDeMenu = 1; //pula a seta para o inicio do menu
            }
            break;
            

        case KEY_UP:
            mvwprintw(janelaEscolhas, contadorDeMenu, 2, "  "); // apaga a seta
            contadorDeMenu--;
            if (contadorDeMenu < 1)
            {
                contadorDeMenu = 4; //pula a seta pro final do menu
            }
            break;

        case 10: //10 = enter
            return contadorDeMenu;
            break;
        }

        mvwprintw(janelaEscolhas, contadorDeMenu, 2, "->");
        wrefresh(janelaEscolhas);
    }
}

    void funcoes(int retorno, WINDOW *janelaEscolhas, WINDOW *janelaLogo)
    {
        switch(retorno)
        {
            case 1:
                mvwprintw(stdscr, 10, 10, "opcao 1 escolhida.");
                wrefresh(stdscr);
                break;
            case 2:
                mvwprintw(stdscr, 10, 10, "opcao 2 escolhida.");
                wrefresh(stdscr);
                break;
            case 3:
                //mvwprintw(stdscr, 10, 10, "opcao 3 escolhida.");
                wclear(stdscr);
                wrefresh(stdscr);
                AboutTheProject();
                wrefresh(stdscr);
                break;
            case 4:
                endwin();
                exit(0);
                break;  
        }
    }

int main()
{

    int xmaxstdscr, ymaxstdscr, retorno;

    initscr(); // inicia o modo curses
    cbreak();  // teclas de controle geram sinais de interrupção, diferente do raw() onde elas n geram.
    noecho();
    getmaxyx(stdscr, ymaxstdscr, xmaxstdscr);

    WINDOW *janelaEscolhas = newwin(6, 24, (ymaxstdscr / 2.1), (xmaxstdscr / 2.3)); // newwin(altura,largura (colunas), coordenada y em relação a stdscr, coordenada x em relaçãoa stdscr)
    box(janelaEscolhas, 0, 0);
    refresh();

    WINDOW *janelaLogo = newwin(7, 50, (ymaxstdscr / 8), (xmaxstdscr / 2.6));
    refresh();

    retorno = menu(xmaxstdscr, ymaxstdscr, janelaEscolhas, janelaLogo);
    funcoes(retorno, janelaEscolhas, janelaLogo);

    refresh(); // passa as informações que estavam no stdscr para a tela de fato (altera somente as atualizações)
    getch();   // espera entrada do usuário

    endwin(); // finaliza o modo curses.

    return 0;
}

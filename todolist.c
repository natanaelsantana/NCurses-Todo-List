#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"
#include "Logos.h"

/*
Projeto feito por: Gabriel Santana e Natanael Lima
Data do Início: 12/12/2023
Data do Término:

  Para compilar e executar vá até o diretório correspondente e digite:

    "make"

  "./testes.x"
*/

int main()
{

    int xmaxstdscr, ymaxstdscr, escolha, contadorDeMenu = 1;

    initscr(); // inicia o modo curses
    cbreak();  // teclas de controle geram sinais de interrupção, diferente do raw() onde elas n geram.
    noecho();
    getmaxyx(stdscr, ymaxstdscr, xmaxstdscr);

    WINDOW *janelaEscolhas = newwin(5, 24, (ymaxstdscr / 2.1), (xmaxstdscr / 2.3)); // newwin(altura,largura (colunas), coordenada y em relação a stdscr, coordenada x em relaçãoa stdscr)
    box(janelaEscolhas, 0, 0);
    refresh();

    WINDOW *janelaLogo = newwin(7, 50, (ymaxstdscr / 8), (xmaxstdscr / 2.6));
    refresh();

    keypad(janelaEscolhas, true);

    wprintw(janelaLogo, logoMenu);
    mvwprintw(janelaEscolhas, 1, 4, "Sign up");
    mvwprintw(janelaEscolhas, 2, 4, "Sign in");
    mvwprintw(janelaEscolhas, 3, 4, "About the project");
    mvwprintw(stdscr, (ymaxstdscr - 2), (xmaxstdscr / 18), "Exit");
    mvwprintw(stdscr, (ymaxstdscr - 2), (xmaxstdscr / 1.3), "Made by: Gabriel Santana and Natanael Lima");

    wrefresh(janelaEscolhas);
    wrefresh(janelaLogo);
    refresh();
    
    mvwprintw(janelaEscolhas, contadorDeMenu, 2,"->"); //posiciona a seta no inicio
    wrefresh(janelaEscolhas);

    while (1)
    {
        escolha = wgetch(janelaEscolhas);

        switch (escolha)
        {
        case KEY_DOWN:
            mvwprintw(janelaEscolhas, contadorDeMenu, 2, "  "); //apaga a seta
            contadorDeMenu++;
            if (contadorDeMenu > 3)
            {
                contadorDeMenu = 1;
            }
            break;;

        case KEY_UP:
            mvwprintw(janelaEscolhas, contadorDeMenu, 2, "  "); //apaga a seta
            contadorDeMenu--;
            if (contadorDeMenu < 1)
            {
                contadorDeMenu = 3;
            }
            break;

        /*case KEY_ENTER:

            break;
        */
        default:
            mvprintw(stdscr, 20, 10, "Tecla errada bro");
            wrefresh(stdscr);
            continue;
        }

        mvwprintw(janelaEscolhas, contadorDeMenu, 2,"->");
        wrefresh(janelaEscolhas);
    }

    refresh(); // passa as informações que estavam no stdscr para a tela de fato (altera somente as atualizações)
    getch();   // espera entrada do usuário

    endwin(); // finaliza o modo curses.

    return 0;
}
#include "stdio.h"
#include "ncurses.h"

const char *texto1 = "Gravidade: mede o impacto de um problema ou demanda\n"
                     "para os demais processos de negocio.\n"
                     "Se essa operacao nao for feita imediatamente, quais serao as consequencias?\n"
                     "Os niveis podem ser:\n"
                     "1 - Sem gravidade\n"
                     "2 - Pouco grave\n"
                     "3 - Grave\n"
                     "4 - Muito grave\n"
                     "5 - Extremamente grave\n";

const char *texto2 = "";

const char *texto3 = "";

int main(){

    initscr();
    cbreak();
    noecho();

    int xmax, ymax;

    getmaxyx(stdscr, ymax, xmax);

    WINDOW *janelaGravidade = newwin(10, 90, (ymax / 2.1), (xmax / 2.3));
    box(janelaGravidade,0,0);
    refresh();

    //mvwprintw(stdscr,10,20,"teste");
    mvwprintw(janelaGravidade,1,3, "%s", texto1);
    

    wrefresh(janelaGravidade);
    wrefresh(stdscr);
    getch();
    endwin();

    return 0;
}
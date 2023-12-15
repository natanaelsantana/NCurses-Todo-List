#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"

/*
Projeto feito por: Gabriel Santana e Natanael Lima
Data do Início: 12/12/2023
Data do Término:

  Para compilar e executar vá até o diretório correspondente e digite:

  gcc teste.c -o testes.x -lncurses
  ./testes.x
*/

int main()
{

  int xmax, ymax;
  initscr(); // inicia o modo curses
  cbreak();     // teclas de controle geram sinais de interrupção, diferente do raw() onde elas n geram.
  noecho();
  getmaxyx(stdscr, ymax, xmax);

  //printw("x: %d y: %d", xmax, ymax);

  //newwin(7, (xmax - 6), (ymax - 9), 3);

  WINDOW * janela = newwin(7, (xmax - 6), (ymax - 9), 3);

  mvprintw((ymax/8), (xmax/2.25), "Insira a logo aqui");
  mvprintw((ymax/2),(xmax/2.25),"Fazer Cadastro\n");
  mvprintw((ymax/2) + 1.5,(xmax/2.25), "Sobre o projeto");
  mvprintw((ymax-2), (xmax/18),"Sair");
  mvprintw((ymax-2),(xmax/1.3),"Feito por: Gabriel Santana e Natanael Lima");

  refresh(); // passa as informações que estavam no stdscr para a tela de fato (altera somente as atualizações)
  getch();
  endwin(); // finaliza o modo curses

  return 0;

}

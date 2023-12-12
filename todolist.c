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

  mvprintw((ymax/4), (xmax/2), "Insira a logo aqui");
  printw("Fazer Cadastro");
  printw("Feito por: Gabriel Santana e Natanael Lima");

  refresh(); // passa as informações que estavam no stdscr para a tela de fato (altera somente as atualizações)
  getch();
  endwin(); // finaliza o modo curses

  return 0;
}

#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"

/*
Projeto feito por: Gabriel Santana e Natanael Lima
Data do Início: 12/12/2023
Data do Término:
*/


int main(){
    initscr(); //inicia o modo curses
    raw(); //teclas de controle não geram sinais de interrupção, diferente do cbreak() onde elas geram.
    printw("Teste");
    refresh(); //passa as informações que estavam no stdscr para a tela de fato (altera somente as atualizações)
    endwin();  //finaliza o modo curses
  return 0;
}

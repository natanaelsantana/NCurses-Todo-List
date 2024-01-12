#include "stdio.h"
#include "ncurses.h"


typedef struct user{

    char login [50];
    char senha [50];
    //char hash[50]; estudar hash depois

}user;

void cadastro()
{
    int ch, i = 0;
    struct user user; //declara a variavel user do tipo struct user

    mvprintw(10,10,"login:");
    for(i = 0; (ch = getch()) != '\n'  && i < sizeof(user.login) - 1; i++)
    {
        user.login[i] = ch;
        printw("%c", ch);
        refresh();
    }

    user.login[i] = '\0'; //terminação no final da string login

    mvprintw(11,10,"senha:");
    for(i = 0; (ch = getch()) != '\n' && i < sizeof(user.senha) - 1; i++)
    {
        user.senha[i] = ch;
        printw("*");
        refresh();
    }    
    user.senha[i] = '\0';

    mvprintw(12,10,"Login: %s\n", user.login);
    mvprintw(13,10,"Senha: %s\n", user.senha);
    refresh();

}

int main(){

    initscr(); //inicia o modo curses
    noecho();
    cbreak();

    cadastro();
    getch();
    endwin();
    return 0;
}
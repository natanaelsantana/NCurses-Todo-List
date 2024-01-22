#include "stdio.h"
#include "stdlib.h"
#include <ncurses/ncurses.h>
#include "Logos.h"


typedef struct user{

    char login [50];
    char senha [50];
    //char hash[50]; estudar hash depois

}user;

void cadastro(WINDOW *janelaLogo, WINDOW *janelaLogin)
{
    int ch, i = 0;
    struct user user; //declara a variavel user do tipo struct user

    keypad(stdscr,true);

    box(janelaLogin,0,0);

    wprintw(janelaLogo, "%s", logoMenu);
    wrefresh(janelaLogo);
    refresh();

    mvwprintw(janelaLogin,1,1,"login:");
    wrefresh(janelaLogin);
    refresh();

    for (i = 0; (ch = getch()) != '\n' && i < sizeof(user.login) - 1;)
    {
        if (ch == KEY_BACKSPACE)
        {
            if (i > 0)
            {
                i--;
                mvwprintw(janelaLogin, 1, 7 + i, " ");
                wrefresh(janelaLogin);
                refresh();
                mvwprintw(janelaLogin, 10, 10 + i, " ");
                wrefresh(janelaLogin);
                refresh(); //tentar entender o caractere remanescente
            }
        }
        else
        {
            user.login[i] = ch;
            wprintw(janelaLogin, "%c", ch);
            wrefresh(janelaLogin);
            i++;
        }
    }
    user.login[i] = '\0'; //terminação no final da string login

    mvwprintw(janelaLogin,2,1,"senha:");
    wrefresh(janelaLogin);
    refresh();

    for(i = 0; (ch = getch()) != '\n' && i < sizeof(user.senha) - 1; i++)
    {
        if(ch > 32 && ch < 126)
        {
        user.senha[i] = ch;
        wprintw(janelaLogin,"*");
        wrefresh(janelaLogin);
        refresh();
        }
        else if (i != 0)
        {
            user.senha[i--] = ' ';
            mvprintw(11,10 + i, " ");
        }
        
    }
        
    user.senha[i] = '\0';
    

    mvprintw(12,10,"Login: %s\n", user.login);
    mvprintw(13,10,"Senha: %s\n", user.senha);
    refresh();                                    

}

int Register () {

    initscr(); //inicia o modo curses
    noecho();
    cbreak();

    int xmaxstdscr,ymaxstdscr;
    getmaxyx(stdscr,ymaxstdscr,xmaxstdscr);


    WINDOW *janelaLogo;
    janelaLogo = newwin(7, 50, (ymaxstdscr / 8), (xmaxstdscr / 2.6));
    refresh();

    WINDOW *janelaLogin;
    janelaLogin = newwin(4, 30, (ymaxstdscr / 2.1), (xmaxstdscr / 2.3));
    refresh();

    cadastro(janelaLogo,janelaLogin);

    wclear(janelaLogin);
    wrefresh(janelaLogin);
    endwin();
    return 0;
}
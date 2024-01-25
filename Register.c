#include "stdio.h"
#include "stdlib.h"
#include <ncurses/ncurses.h>
#include "Logos.h"
#include <ctype.h>

typedef struct user
{

    char login[50];
    char senha[50];
    // char hash[50]; estudar hash depois

} user;

struct user cadastro(WINDOW *janelaLogo, WINDOW *janelaLogin)
{

    int ch, i = 0;
    struct user user; // declara a variavel user do tipo struct user

    keypad(stdscr, true);

    box(janelaLogin, 0, 0);

    wprintw(janelaLogo, "%s", logoMenu);
    wrefresh(janelaLogo);
    refresh();
    mvwprintw(janelaLogin, 1, 1, "login:");
    wrefresh(janelaLogin);
    refresh();

    for (i = 0; (ch = getch()) != '\n' && i < sizeof(user.login) - 1;)
    {
        if (ch == KEY_BACKSPACE)
        {
            if (i > 0)
            {
                i--;
                user.login[i] = '\0'; // remove o caractere da string de login

                // limpa a linha inteira
                wmove(janelaLogin, 1, 7);
                // Função responável pela limpeza da linha inteira a partir do cursos
                wclrtoeol(janelaLogin);

                // imprime a string de login atualizada
                mvwprintw(janelaLogin, 1, 7, "%s", user.login);
                wrefresh(janelaLogin);
                refresh();
            }
        }
        else
        {
            if (isalpha(ch) || isdigit(ch)) // verifica se o caractere é alfabético ou numérico
            {
                user.login[i] = ch;
                wprintw(janelaLogin, "%c", ch);
                wrefresh(janelaLogin);
                i++;
            }
        }
    }
    user.login[i] = '\0'; // terminação no final da string login

    mvwprintw(janelaLogin, 2, 1, "senha:");
    wrefresh(janelaLogin);
    refresh();

    for (i = 0; (ch = getch()) != '\n' && i < sizeof(user.senha) - 1;)
    {
        if (ch == KEY_BACKSPACE)
        {
            if (i > 0)
            {
                i--;
                user.senha[i] = '\0'; // remove o caractere da string de login

                // limpa a linha inteira
                wmove(janelaLogin, 2, 7);
                // Função responável pela limpeza da linha inteira a   partir do cursos
                wclrtoeol(janelaLogin);

                // imprime a string de login atualizada
                for (int j = 0; j < i; j++)
                {
                    mvwprintw(janelaLogin, 2, 7 + j, "*");
                }
                wrefresh(janelaLogin);
                refresh();
            }
        }
        else
        {
            if (isalpha(ch) || isdigit(ch)) // verifica se o caractere é alfabético ou numérico
            {
                user.senha[i] = ch;
                wprintw(janelaLogin, "*");
                wrefresh(janelaLogin);
                i++;
            }
        }
    }

    user.senha[i] = '\0';

    mvprintw(12, 10, "Login: %s\n", user.login);
    mvprintw(13, 10, "Senha: %s\n", user.senha);
    refresh();

    return user;
}

int Register()
{

    initscr();            // inicia o modo curses
    raw();                // Desabilita buffering de linha
    keypad(stdscr, TRUE); // Habilita leitura de teclas especiais
    noecho();
    cbreak();

    int xmaxstdscr, ymaxstdscr;
    getmaxyx(stdscr, ymaxstdscr, xmaxstdscr);

    WINDOW *janelaLogo;
    janelaLogo = newwin(7, 50, ymaxstdscr / 8, xmaxstdscr / 2.6);
    refresh();

    WINDOW *janelaLogin;
    janelaLogin = newwin(4, 30, ymaxstdscr / 2.1, xmaxstdscr / 2.3);
    refresh();

    struct user User = cadastro(janelaLogo, janelaLogin);

    // Aqui ficará a função que coloca os dados em um banco de Dados
    FILE *arquivo = fopen("dados.txt", "w+");

    if (arquivo == NULL)
    {
        printf("erro ao abrir arquivo");
        return 0;
    }

    // Escreve o login e a senha no arquivo
    fprintf(arquivo, "Login: %s\n", User.login);
    fprintf(arquivo, "Senha: %s\n", User.senha);

    // Fecha o arquivo
    fclose(arquivo);

    wclear(janelaLogin);
    wrefresh(janelaLogin);
    endwin();
    return 0;
}
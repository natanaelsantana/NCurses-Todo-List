#include "stdio.h"
#include "stdlib.h"
#include <ncurses/ncurses.h>
#include "Logos.h"
#include <ctype.h>
#include <openssl/evp.h>
#include <string.h>
#include "MenuFunctions.h"

void encrypt(char senha[50], char hash[128])
{
    const unsigned char salt[] = "50"; // deve ser único para cada usuário
    unsigned char temp_hash[64];

    // A função PKCS5 pega a senha de entrada e usa o algoritmo contigo em EVP_sha256() para realizar o hash, que possui  tamanho de 64 bytes
    if (!PKCS5_PBKDF2_HMAC(senha, strlen(senha), salt, strlen((char *)salt), 10000, EVP_sha256(), 64, temp_hash))
    {
        fprintf(stderr, "Erro ao criar o hash da senha\n");
    }

    for (int i = 0; i < 64; i++)
    {
        sprintf(&hash[i * 2], "%02x", temp_hash[i]);
    }
}

typedef struct user
{
    char login[50];
    char senha[128];
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

    encrypt(User.senha, User.senha);

    inserirUsuario(User.login, User.senha);

    wclear(janelaLogin);
    wrefresh(janelaLogin);
    endwin();
    return 0;
}
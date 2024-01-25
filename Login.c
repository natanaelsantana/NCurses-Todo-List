#include "stdio.h"
#include "stdlib.h"
#include <ncurses/ncurses.h>
#include "Logos.h"
#include <ctype.h>
#include "string.h"
#include "MenuFunctions.h"

typedef struct user
{

    char login[50];
    char senha[128];
    // char hash[50]; estudar hash depois

} user;

// Função para verificar o login
int verificar_login(user *usuario)
{
    user usuario_arquivo;

    // Abre o arquivo para leitura
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    // Lê o login e a senha do arquivo
    fscanf(arquivo, "Login: %s\n", usuario_arquivo.login);
    fscanf(arquivo, "Senha: %s\n", usuario_arquivo.senha);

    // Fecha o arquivo
    fclose(arquivo);

    // Compara o login e a senha com os dados inseridos pelo usuário
    if (strcmp(usuario->login, usuario_arquivo.login) == 0 &&
        strcmp(usuario->senha, usuario_arquivo.senha) == 0)
    {
        return 1; // Login bem-sucedido
    }
    else
    {
        return 0; // Login falhou
    }
}

void Login()
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

    if (verificar_login(&User))
    {
        mvprintw(14, 10, "Login bem-sucedido!\n");
    }
    else
    {
        mvprintw(14, 10, "Login falhou!\n");
    }
    refresh();

    wclear(janelaLogin);
    wrefresh(janelaLogin);
    endwin();
    return;
}
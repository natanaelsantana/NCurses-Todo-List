#include "stdio.h"
#include "ncurses.h"
#include "Logos.h"

const char *texto1[] = {
    "Gravidade: mede o impacto de um problema ou demanda",
    "para os demais processos de negocio.",
    "Se essa operacao nao for feita imediatamente,",
    "quais serao as consequencias?",
    "",
    "Os niveis de Gravidade sao:",
    "",
    "1 - Sem gravidade",
    "2 - Pouco grave",
    "3 - Grave",
    "4 - Muito grave",
    "5 - Extremamente grave"};

const char *texto2[] = {
    "Urgencia: tente sempre responder se um problema pode esperar.",
    "Em alguns casos, ele e extremamente importante,",
    "mas nao precisa de solução imediata.",
    "portanto, deve ser resolvido posteriormente.",
    "",
    "Os niveis de urgencia sao:",
    "",
    "1 - pode esperar",
    "2 - pouco urgente",
    "3 - urgente, deve ter atenção rapida",
    "4 - muito urgente, deve ser a prioridade zero do momento",
    "5 - urgentissimo e inadiavel, necessidade de acao imediata"};

const char *texto3[] = {
    "Tendência: avalia a tendência do problema se agravar",
    "caso demore a ser solucionado e avalia se essa 'piora'",
    "será brusca ou lenta.",
    "",
    "",
    "Os niveis de Tendencia sao:",
    "",
    "1 - manterá a estabilidade",
    "2 - deve piorar em longo prazo",
    "3 - possibilidade de piorar em médio prazo",
    "4 - possibilidade de piorar em curto prazo",
    "5 - piora imediata",
};

void AboutTheProject()
{
    initscr();
    cbreak();
    noecho();

    int xmaxstdscr, ymaxstdscr;

    getmaxyx(stdscr, ymaxstdscr, xmaxstdscr);

    WINDOW *janelaGravidade = newwin(15, 54, (ymaxstdscr/2), (xmaxstdscr / 20));
    //box(janelaGravidade, 0, 0);
    refresh();

    WINDOW *janelaUrgencia = newwin(14,64, (ymaxstdscr/2), (xmaxstdscr/3));
    //box(janelaUrgencia,0,0);
    refresh();

    WINDOW *janelaTendencia= newwin(14,60, (ymaxstdscr/2), (xmaxstdscr/1.5));
    //box(janelaTendencia, 0,0);
    refresh();

    WINDOW *janelaLogoAbt = newwin(15, 100, (ymaxstdscr / 8), (xmaxstdscr / 3));
    refresh();

    for (int i = 0; i < 12; i++)
    {
        mvwprintw(janelaGravidade, i + 1, 1, "%s", texto1[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        mvwprintw(janelaUrgencia, i + 1, 1, "%s", texto2[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        mvwprintw(janelaTendencia, i + 1, 1, "%s", texto3[i]);
    }

    wprintw(janelaLogoAbt, "%s", logoAboutTheProject);


    wrefresh(janelaLogoAbt);
    wrefresh(janelaGravidade);
    wrefresh(janelaUrgencia);
    wrefresh(janelaTendencia);
    wrefresh(stdscr);
    getch();
    endwin();

    
}
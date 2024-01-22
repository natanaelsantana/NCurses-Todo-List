#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*A ideia é simples, o cálculo é realizado da seguinte forma: 
G x U x T = Grau Critico 

O valor do Grau Crítico Indicara a sequência das atividades a serem feitas, quanto maior resultado 
maior o resultado, maior a colocação na sequência 
cada número terá sua própria cor
com até 4 cores diferentes para cada grau:

1 - vermelho 
2- Laranja 
3 - Amarelo 
4 em diante - Verde

*/

int ValorGut (int G, int U, int T) {

    int resultado = G * U * T;
    return resultado; 
}

typedef struct {
    char nome[100];
    int resultado;
}Tarefa;


/*N é a quantidade de tarefas, a cada adição ou subtração de um novo componente
o valor de n deve ser atualizado, fornecendo um controle dinâmico das tarefas

o algoritmo se trata de um bubblesort
ele passa por todos os elementos do array várias vezes
em cada passagem ele compara cada item da lista com o elemento do lado
*/
void Sequencia(Tarefa t[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (t[j].resultado < t[j + 1].resultado) {
                // Troca as posições se estiverem fora de ordem
                Tarefa temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}


int main() {
    // Criar um array de tarefas
    Tarefa tarefas[5]; // Suponhamos que temos 5 tarefas

    // Preencher as tarefas com valores de G, U, T (pode ser feito manualmente ou através de input)
    strcpy(tarefas[0].nome, "Tarefa A");
    tarefas[0].resultado = ValorGut(3, 4, 2);

    strcpy(tarefas[1].nome, "Tarefa B");
    tarefas[1].resultado = ValorGut(2, 5, 1);
    strcpy(tarefas[2].nome, "Tarefa c");
    tarefas[2].resultado = ValorGut(5, 5, 5);

    strcpy(tarefas[3].nome, "Tarefa D");
    tarefas[3].resultado = ValorGut(1, 1, 1);
    strcpy(tarefas[4].nome, "Tarefa E");
    tarefas[4].resultado = ValorGut(2, 3, 4);

    // Preencher as tarefas restantes...

    // Antes de organizar
    printf("Tarefas antes da organizacao:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - Resultado: %d\n", tarefas[i].nome, tarefas[i].resultado);
    }

    // Chamar a função de organização
    Sequencia(tarefas, 5);

    // Após organização
    printf("\nTarefas depois da organizacao:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - Resultado: %d\n", tarefas[i].nome, tarefas[i].resultado);
    }

    system("pause");    return 0;
}
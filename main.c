#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include <unistd.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct lnode* List;
typedef struct Cartao cart;

typedef struct Cartao{
    int nrid;
    int prio;
    char date[10];
    char msg[50];
};
typedef struct lnode {
    cart info;
    List next;
}List_node;
List newlist (void){
    List aux;
    aux = (List) malloc (sizeof (List_node));
    if (aux != NULL) {
        aux->info.nrid = 0;
        aux->info.prio = 0;
        aux->info.date[0];
        aux->next = NULL;
    }
    return aux;
}

int main() {
    List to_do = newlist();
    List doing = newlist();
    List done = newlist();
    char* nome = malloc(10*sizeof(char));
    printf("Insira o Nome: \n");
    scanf("%s",nome);
    printf("\n");
    printf("1 - Inserir uma nova tarefa na lista To Do, defina a prioridade \n");
    printf("2 - Mover uma tarefa da lista To Do para Doing \n");
    printf("3 - Alterar a pessoa responsável por um cartão em Doing\n");
    printf("4 - Terminar uma tarefa\n");
    printf("5 - Reabrir tarefa\n");


    return 0;
}


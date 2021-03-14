#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "Lists.h"
#define TRUE 1
#define FALSE 0
typedef struct Cartao card;
/*typedef struct Cartao{
    int nrid;
    int prio;
    char date[10];
    char msg[50];
};*/
void insert(List to_do,int nid){
    card to_insert;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Insira a prioridade da tarefa (0-10): ");
    scanf("%d",&to_insert.prio);
    printf("Insira uma descrição da tarefa: ");
    scanf("%s",to_insert.msg);
    to_insert.nrid = nid;
    to_insert.date = t;
    list_insert(to_do,to_insert);
    while(to_do->next!=NULL){
        printf("nrid: %d",to_do->info.nrid);
        printf("prio: %d",to_do->info.prio);
        printf("msg: %s",to_do->info.msg);
        to_do = to_do->next;
    }
}
void move(List to_do,List doing){

}
void selection(List to_do,List doing,List done,int nid){
    int opt = 0;
    printf("1 - Inserir uma nova tarefa na lista To Do, defina a prioridade \n");
    printf("2 - Mover uma tarefa da lista To Do para Doing \n");
    printf("3 - Alterar a pessoa responsável por um cartão em Doing\n");
    printf("4 - Terminar uma tarefa\n");
    printf("5 - Reabrir tarefa\n");
    printf("6 - Visualizar o quadro\n");
    printf("7 - Visualizar apenas as suas tarefas\n");
    printf("8 - Visualizar o quadro (Ordenação por data de criação)\n");
    printf("9 - Sair e guardar alterações\n");
    printf("\n");
    printf("Escolha uma opção: ");
    scanf("%d",&opt);
    printf("\n");
    system("clear");
    switch(opt){
        case 1:
            insert(to_do,nid);
            nid++;
            break;
        case 2:
            move(to_do,doing);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
    }

}

int main() {
    int nid=0;
    List to_do = list_new();
    List doing = list_new();
    List done = list_new();
    char* nome = malloc(10*sizeof(char));
    printf("Insira o Nome: \n");
    scanf("%s",nome);
    printf("\n");
    selection(to_do,doing,done,nid);
    return 0;
}


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

/* while(to_do->next!=NULL){
     to_do = to_do->next;
     printf("nrid: %d\n",to_do->info.nrid);
     printf("prio: %d\n",to_do->info.prio);
     printf("msg: %s\n",to_do->info.msg);
     printf("data: %s\n",to_do->info.date);
 }*/

//typedef struct Cartao card;
/*typedef struct Cartao{
    int nrid;
    int prio;
    time_t date;
    char msg[50];
};*/

void insert(List to_do,int nid){// FEITO
    card to_insert;
    struct tm * tm;
    time_t t;
    int kwokd;
    char data[20];
    time(&t);
    tm = localtime(&t);
    strftime(data, 20, "%d-%m-%y", tm);
    printf("Insira a prioridade da tarefa (0-10): ");
    scanf("%d",&to_insert.prio);
    printf("Insira uma descrição da tarefa: ");
    scanf("%s",to_insert.msg);
    to_insert.nrid = nid;
    strcpy(to_insert.date, data);
    list_insert(to_do,to_insert);
}

void view (List to_do, List doing, List done){
    printf("+---------+---------+--------+\n");
    printf("|  To Do  |  Doing  |  Done  |\n");
    printf("+---------+---------+--------+\n");
    while(to_do->next!=NULL || doing->next!=NULL || done->next!=NULL) {
        //printf("+");
        if (to_do->next!=NULL) {
            to_do = to_do->next;
            printf("| nrid:%d |\n", to_do->info.nrid);
            printf("| msg:%s |\n", to_do->info.msg);
        }
        if (doing->next != NULL){
            doing = doing->next;
            printf("| nrid: %d  |\n", doing->info.nrid);
            printf("| msg: %s |\n", doing->info.msg);
        }
        if (done->next!=NULL){
            done = done->next;
            printf("| nrid: %d |\n", done->info.nrid);
            printf("| msg: %s |\n", done->info.msg);
        }
        printf("+---------+---------+--------+\n");
    }
}
void move(List to_do,List doing,List done){ // FEITO
    int opt = 0;
    printf("1 - Ver o Quadro\n");
    printf("2 - Escolher com base no id\n");
    scanf("%d",&opt);
    if(opt==1){
        view(to_do,doing,done);
    }
        int id;
        char nome[10],data[20];
        printf("Insira o id do cartao: ");
        scanf("%d",&id);
        printf("%d\n", id);
        card temp;
        temp.nrid = id;
        temp = list_search(to_do,temp)->info;
        list_kill(to_do,temp);
        printf("Insira o nome: ");
        scanf("%s",nome);
        printf("\n");
        strcpy(temp.pessoa, nome);
        printf("Indique uma data prazo: ");
        scanf("%s",data);
        printf("\n");
        strcpy(temp.date, data);
        list_insert(doing,temp);
}

int selection(List to_do,List doing,List done,int nid){
    int opt = 0;
    printf("1 - Inserir uma nova tarefa na lista To Do\n");
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
    switch(opt){
        case 1:
            insert(to_do,nid);
            return opt;
        case 2:
            move(to_do,doing,done);
            return opt;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            view(to_do,doing,done);
            return opt;
        case 7:
            break;
        case 8:
            break;
        case 9:
            //guardar
            return 9;
        default:
            printf("Opção Inválida");
            break;
    }
    return 0;
}

int main() {
    int nid=0;
    List to_do = list_new();
    List doing = list_new();
    List done = list_new();
    int n=0;
    while (n != 9){
        n=0;
        n = selection(to_do,doing,done,nid);
        nid++;
    }
    return 0;
}


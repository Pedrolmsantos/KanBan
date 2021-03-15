#include <time.h>
typedef struct lnode* List;
typedef struct Cartao card;
typedef struct Cartao{
    int nrid;
    int prio;
    //time_t date;
    char date[20];
    char prazo[20];
    char msg[50];
    char pessoa[10];
}Cartao;
typedef struct lnode {
    card info;
    List next;
} List_node;

List list_new(void){
    List aux;
    aux = (List) malloc (sizeof (List_node));
    if (aux != NULL) {
        aux->info.nrid = 0;
        aux->info.prio = 0;
        aux->next = NULL;
    }
    return aux;
}
int list_empty(List lista){
    return (lista->next == NULL ? 1 : 0);
}
List list_nodkill(List lista){
    List temp_ptr;
    while (list_empty (lista) == 0) {
        temp_ptr = lista;
        lista= lista->next;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

void list_searchtok(List lista, card chave, List *ant, List *atual){
    *ant = lista;
    *atual = lista->next;
    while ((*atual) != NULL && (*atual)->info.nrid < chave.nrid){
        *ant = *atual;
        if (((*atual)->next) == NULL) {
            break;
        }
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.nrid != chave.nrid)
        *atual = NULL;
}
List list_search(List lista, card it){
    List ant;
    List atual;
    list_searchtok (lista, it, &ant, &atual);
    return (atual);
}
void list_kill(List lista, card it){
    List ant1;
    List atual1;
    list_searchtok (lista, it, &ant1, &atual1);
    if (atual1 != NULL) {
        ant1->next = atual1->next;
        free (atual1);
    }
}
void list_insert(List lista, card it){
    List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok (lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}

void list_print(List lista){
    List l = lista->next; /* Salta o header */
    while (l){
        printf("%s\n", l->info.msg);
        printf("%d ", l->info.prio);
        l=l->next;
    }
}



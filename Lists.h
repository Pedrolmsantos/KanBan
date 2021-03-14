#include <time.h>
typedef struct lnode* List;
typedef struct Cartao cart;
typedef struct Cartao{
    int nrid;
    int prio;
    time_t date;
    char msg[50];
};
typedef struct lnode {
    cart info;
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

void list_searchtok(List lista, cart chave, List *ant, List *atual){
    *ant = lista; *atual = lista->next;
    while ((*atual) != NULL && (*atual)->info.nrid < chave.nrid){
        *ant = *atual;
        *atual = (*atual)->next;
    }
    if ((*atual) != NULL && (*atual)->info.msg != chave.msg)
        *atual = NULL;
}
List list_search(List lista, cart it){
    List ant;
    List atual;
    list_searchtok (lista, it, &ant, &atual);
    return (atual);
}
void list_kill(List lista, cart it){
    List ant1;
    List atual1;
    list_searchtok (lista, it, &ant1, &atual1);
    if (atual1 != NULL) {
        ant1->next = atual1->next;
        free (atual1);
    }
}
void list_insert(List lista, cart it){
   /* List no;
    List ant, inutil;
    no = (List) malloc (sizeof (List_node));
    if (no != NULL) {
        no->info = it;
        list_searchtok (lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }*/
    List no = (List) malloc (sizeof (List_node));
    no->next = NULL;
    if(list_empty(lista))
        lista->next=no;
    else{
        List tmp = lista->next;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = no;
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



#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
} Bool;

typedef struct __LISTE__ {
    int value;
    struct __LISTE__ *next;
} LIST, *List;

//Les prototypes 
List new_list(void);
Bool is_empty(List);
List  push_back(List, int);
List push_front(List, int);
void print_list(List);
List pop_back(List);
List pop_front(List);

int main() {
    LIST *liste;
    liste = new_list();
    if(is_empty(liste)) printf("La liste est vide \n");

    liste = push_back(liste, 5);
    liste = push_front(liste, 10);
    liste = push_back(liste, 0);
    liste = push_back(liste, -5);

    print_list(liste);

    printf(".......\n");
    liste = pop_front(liste);
    liste = pop_back(liste);

    print_list(liste);

    if(is_empty(liste)) printf("Liste toujours vide \n");

    return 0;
}

List new_list() {
    return NULL;
}

Bool is_empty(List li) {
    if(li == NULL) return true;

    return false;
}

List push_back(List li, int x) {
    LIST *element = malloc(sizeof(*element));

    if(element == NULL) {
        fprintf(stderr, "Erreur d'allocation \n");
        exit(EXIT_FAILURE);
    }
    element->value = x;
    element->next = NULL;

    if(li == NULL) {
        return element;
    }

    LIST *temp = li;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = element;

    return li;
}

List push_front(List li, int x) {
    LIST *element = malloc(sizeof(*element));

    if(element == NULL) {
        fprintf(stderr, "Erreur d'allocation \n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = li;

    return element;
}

void print_list(List li) {
    while(!is_empty(li)) {
        printf("[%d] ", li->value);
        li = li->next;
    }
    printf("\n");
}

List pop_back(List li) {

    if(is_empty(li)) return NULL;
    
    if (li->next == NULL) {
        free(li);
        return new_list();
    }

    LIST *before_end = li;
    LIST *end = li->next;

    while(end->next != NULL) {
        before_end = end;
        end = end->next;
    }

    before_end->next = NULL; 

    free(end);

    return li;
}

List pop_front(List li) {
    if(is_empty(li)) return NULL;

    if(li->next == NULL) {
        free(li);
        return new_list();
    }

    LIST *temp = li->next;

    free(li);

    return temp;
}
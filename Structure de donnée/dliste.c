#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
} Bool;

typedef struct __NODE__ {
    int value;
    struct __NODE__ *back;
    struct __NODE__ *next;
} NODE;

typedef struct __DLIST__ {
    int taille;
    NODE *begin;
    NODE *end;
} *Dlist;

//Les prototypes 
Dlist new_dlist(void);
Bool is_empty(Dlist);
Dlist insert_front(Dlist, int);
Dlist insert_back(Dlist, int);
Dlist delete_front(Dlist);
Dlist delete_back(Dlist);
void print_dlist(Dlist);
Dlist clear_dlist(Dlist);

int main() {
    Dlist listeD = new_dlist();

    if(is_empty(listeD)) printf("La listeD est vide\n");

    listeD = insert_front(listeD, 3);
    listeD = insert_back(listeD, 10);
    print_dlist(listeD);

    listeD = clear_dlist(listeD);

    if(is_empty(listeD)) {
        printf("La listeD est a nouveau vide\n");
    } else {
        printf("La listeD contient des elements\n");
    }

    return 0;
}

Dlist new_dlist(void) {
    return NULL;
}

Bool is_empty(Dlist li) {
    if(li == NULL) return true;

    return false;
}

Dlist insert_front(Dlist li, int x) {
    NODE *element = malloc(sizeof(*element));

    if(element == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(1);
    }

    element->value = x;
    element->back = NULL;
    element->next = NULL;

    if(li == NULL) {
        li = malloc(sizeof(*li));

        if(li == NULL) {
            fprintf(stderr, "Erreur d'allocation\n");
            exit(1);
        }
        li->taille = 0;
        li->begin = element;
        li->end = element;
    } else {
        li->begin->back = element;
        element->next = li->begin;
        li->begin = element;
    }
    li->taille++;

    return li;
}

Dlist insert_back(Dlist li, int x) {
    NODE *element = malloc(sizeof(*element));

    if(element == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(1);
    }
    element->value = x;
    element->back = NULL;
    element->next = NULL;

    if(li == NULL) {
        li = malloc(sizeof(*li));

        li->taille = 0;
        li->begin = element;
        li->end = element;
    } else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    
    li->taille++;

    return li;
}

Dlist delete_front(Dlist li) {
    if(li == NULL) return new_dlist();

    if(li->begin == li->end) {
        free(li);
        return new_dlist();
    }

    NODE *temp = li->begin;

    li->begin = temp->next;
    temp->back = NULL;
    temp->next = NULL;
    li->begin->back = NULL;
    free(temp);

    return li;
}

Dlist delete_back(Dlist li) {
    if(li == NULL) return new_dlist();

    if(li->begin == li->end) {
        free(li);
        return new_dlist();
    }

    NODE *temp = li->end;

    li->end = temp->back;
    temp->back = NULL;
    temp->next = NULL;
    li->end->next = NULL;
    free(temp);
    
    return li;
}

void print_dlist(Dlist li) {
    if(li == NULL) {
        printf("Rien a afficher, la listeD est deja vide\n");
        return;
    }

    NODE *temp = li->begin;

    while(temp != NULL) {
        printf("[%d] ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

Dlist clear_dlist(Dlist li) {
    while(!is_empty(li))
        li = delete_front(li);

    return new_dlist();
}
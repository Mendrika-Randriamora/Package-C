#include <stdio.h>
#include <stdlib.h>

typedef struct __PILE__{
    int value;
    struct __PILE__ *next;
} PILE, *Pile;

typedef enum {
    false,
    true
} Bool;

Pile new_stack(void);
Pile push_stack(Pile, int);
Bool is_empty(Pile);
void print_stack(Pile);
Pile pop_stack(Pile);
Pile clear_stack(Pile);
int top_stack(Pile);
int stack_length(Pile);

int main() {
    PILE *pile;

    pile = new_stack();
    if(is_empty(pile)) printf("La pile est vide\n");

    pile = push_stack(pile, 4);
    if(is_empty(pile)) printf("La pile est vide\n");

    pile = push_stack(pile, 8);
    print_stack(pile);

    printf("....\nLe sommet de la pile est : %d\n", top_stack(pile));
    printf("....\nLa longueur de la pile est : %d\n", stack_lenght(pile));

    printf("....\nOn enleve un element de la pile\n");
    pile = pop_stack(pile);
    print_stack(pile);

    printf("....\nLe sommet de la pile est : %d\n", top_stack(pile));
    printf("....\nLa longueur de la pile est : %d\n", stack_lenght(pile));

    pile = clear_stack(pile);
    if(is_empty(pile)) printf("La pile est a nouveau vide\n");

    return 0;
}

//Cree un nouveau pile
Pile new_stack(void) {
    return NULL;
}

//Pour savoir si la pile est vide
Bool is_empty(Pile st) {
    if(st == NULL) return true;

    return false;
}

//Ajouter un element a notre pile
Pile push_stack(Pile st, int x) {
    PILE *element;
    element = malloc(sizeof(*element));

    if(element == NULL) {
       // fprintf(stderr, "Probleme d'allocation"); 
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = st;

    return element;
}

//Afficher les elements de la pile
void print_stack(Pile st) {
    if(is_empty(st)) {
        printf("Rien a afficher, la pile est vide\n");
        return;
    }

    while(!is_empty(st)) {
        printf("[%d]\n", st->value);
        st = st->next;
    }
}

//Depiler un element de la pile
Pile pop_stack(Pile st) {
    PILE *element = malloc(sizeof(PILE));

    if(is_empty(st)) return new_stack();

    element = st->next;
    free(st);

    return element; 
}

//Vider la pile
Pile clear_stack(Pile st) {
    PILE *element = malloc(sizeof(PILE));

    if(is_empty(st)) return new_stack();

    element = st->next;
    free(st);

    return clear_stack(element);
}

//Verifier le sommet 
int top_stack(Pile st) {
    if(is_empty(st)) return -1;
    return st->value;
}

//Verifier la longueur de la pile
int stack_length(Pile st){
    int count = 0;

    if(is_empty(st)) return -1;

    while(!is_empty(st)) {
        count++;
        st = st->next;
    }

    return count;
}
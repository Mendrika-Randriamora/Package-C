#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false,
    true
} Bool;

typedef struct __NODE__ {
    int value;
    struct __NODE__ *next;
}NODE;

typedef struct __QUEUE__ {
    NODE *first;
    NODE *last;
} QUEUE;

//Les prototypes
void init_queue(QUEUE*);
Bool is_empty(QUEUE*);
void push_queue(QUEUE*, int);
void pop_queue(QUEUE*);
void top_queue(QUEUE*);
void clear_queue(QUEUE*);
void print_queue(QUEUE*);

int main() {
    QUEUE *file = malloc(sizeof(QUEUE));

    init_queue(file);

    if(is_empty(file)) printf("La file est vide \n");

    push_queue(file, 2);
    push_queue(file, 4);
    push_queue(file, 6);
    push_queue(file, 8);

    pop_queue(file);

    print_queue(file);

    return 0;
}

void init_queue(QUEUE *fl) {
    fl->first = NULL;
    fl->last = NULL;
}

Bool is_empty(QUEUE *fl) {
    if(fl->first == NULL && fl->last == NULL) return true;

    return false;
}

void push_queue(QUEUE *fl, int x) {
    NODE *newNode = malloc(sizeof(*newNode));

    if(newNode == NULL) {
        fprintf(stderr, "Erreur d'allocation \n");
        exit(1);
    }

    newNode->value = x;
    newNode->next = NULL;

    if(is_empty(fl)) {
        fl->first = newNode;
        fl->last = newNode;
    } else {
        fl->last->next = newNode;
        fl->last = newNode;
    }
}

void pop_queue(QUEUE *fl) {
    NODE *temp = malloc(sizeof(*temp));

    if(temp == NULL) {
        fprintf(stderr, "Erreur d'allocation \n");
        exit(1);
    }

    temp = fl->first;
    
    if(fl->first == fl->last) {
        fl->first = NULL;
        fl->last = NULL;
    } else {
        fl->first = fl->first->next;
    }
    free(temp);
}

void top_queue(QUEUE *fl) {
    printf("La tete de file est %d\n", fl->first->value);
}

void clear_queue(QUEUE *fl) {

    if(is_empty(fl)) {
        printf("Rien a effacher, la file est deja vide \n");
        return;
    }

    while(!is_empty(fl)) {
        pop_queue(fl);
    }
}

void print_queue(QUEUE *fl) {
    if(is_empty(fl)) printf("File vide \n");

    while(!is_empty(fl)) {
        printf("[%d]", fl->first->value);
        fl->first = fl->first->next;
    }
    printf("\n");
}
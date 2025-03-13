#include <stdio.h>
#include <stdlib.h>

typedef struct __TREE__ {
    int value;
    struct __TREE__ *left;
    struct __TREE__ *right;
    struct __TREE__ *parent;
}Tree;

//Les prototypes
Tree *new_tree(int);
Tree *join_tree_left(Tree*, Tree*);
Tree *join_tree_right(Tree*, Tree*);
void print_tree_prefix(Tree *tr);

int main() {
    Tree *arbre1 = new_tree(3);
    Tree *arbre2 = new_tree(7);
    Tree *arbre3 = new_tree(10);
    Tree *arbre4 = new_tree(20);

    arbre1 = join_tree_left(arbre1, arbre2);
    arbre1 = join_tree_right(arbre1, arbre3);
    arbre2 = join_tree_left(arbre2, arbre4);

    print_tree_prefix(arbre1);

    free(arbre1);
    free(arbre2);
    free(arbre3);
    free(arbre4);

    return 0;
}

//Creation d'un arbre
Tree *new_tree(int x) {
    Tree *tr = malloc(sizeof(*tr));

    if(tr == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(1);
    }

    tr->value = x;
    tr->left = NULL;
    tr->right = NULL;
    tr->parent = NULL;

    return tr;
}

//Joindre les arbres dans la branche gauche
Tree *join_tree_left(Tree *tree_parent, Tree *left) {
    Tree *temp = tree_parent; //On ecrase pas tree_parent

    if(temp == NULL) {
        fprintf(stderr,"Erreur d'allocation dynamique \n");
        exit(EXIT_FAILURE);
    }

    left->parent = temp;
    temp->left = left;

    return temp;
}

//Joindre les arbres dans la branche droite
Tree *join_tree_right(Tree *tree_parent, Tree *right) {
    Tree *temp = tree_parent; //On ecrase pas tree_parent

    if(temp == NULL) {
        fprintf(stderr,"Erreur d'allocation dynamique \n");
        exit(EXIT_FAILURE);
    }

    right->parent = temp;
    temp->right = right;

    return temp;
}


void print_tree_prefix(Tree *tr)
{
	if(tr == NULL)
		return;

	if(tr->parent != NULL)
    	printf("(%d) -> %d\n", tr->parent->value, tr->value);
    else
    	printf("(%d)\n", tr->value);

    if(tr->left != NULL)
    	print_tree_prefix(tr->left);

    if(tr->right != NULL)
    	print_tree_prefix(tr->right);
}
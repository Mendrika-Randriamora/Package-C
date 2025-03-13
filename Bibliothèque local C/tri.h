#ifndef __TRI_H__
#define __TRI_H__

void triBulle(int array[], int n);
void fusion(int tableau[], int gauche, int milieu, int droite);
void triFusion(int tab[], int gauche, int droite);
int partition(int tab[], int bas, int haut);
void triRapide(int tab[], int bas, int haut);
void triInsertion(int array[], int n);

#endif
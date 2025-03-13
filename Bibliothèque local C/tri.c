#include <stdio.h>
#include <stdlib.h>
#include "tri.h"

void triBulle(int array[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1 /*i <= n - 2*/; i++) //max
    {
        for(j = 0; j < n - 1; j++) //echange
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
//------------------------------------------------------------------
void fusion(int tableau[], int gauche, int milieu, int droite)
{
    int i, j, k;
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    //cr�ation des tableaux temporaires
    int *G = (int *)malloc(n1 * sizeof(int));
    int *D = (int *)malloc(n2 * sizeof(int));

    //Copier les donn�es dans les tableaux temporaires
    for(i = 0; i < n1; i++)
        G[i] = tableau[gauche + i];
    for(j = 0; j < n2; j++)
        D[j] = tableau[milieu + 1 + j];// la deuxieme sous-tableau commence � milieu + 1

    //Fusionner les tableaux temporaires dans tableau[gauche..droite]
    i = 0;
    j = 0;
    k = gauche;

    while(i < n1 && j < n2)
    {
        if(G[i] <= D[j])
        {
            tableau[k] = G[i];
            i++;
        }else
        {
            tableau[k] = D[j];
            j++;
        }
        k++;
    }

    //Copier les �l�ments restant de G[]
    while(i < n1)
    {
        tableau[k] = G[i];
        i++;
        k++;
    }

    //Copier les �l�ments restant de D[]
    while(j < n2)
    {
        tableau[k] = D[j];
        j++;
        k++;
    }

    //Lib�rer la memoire des tableaux temporaires
    free(G);
    free(D);
}

void triFusion(int tab[], int gauche, int droite)
{
    if(gauche < droite)
    {
        int milieu = (gauche + droite) / 2;
        triFusion(tab, gauche, milieu);
        triFusion(tab, milieu + 1, droite);
        fusion(tab, gauche, milieu, droite);
    }
}
//------------------------------------------------------
int partition(int tab[], int bas, int haut)
{
    int pivot = tab[haut];// dernier �l�ment comme pivot
    int i = bas - 1; // contraire de la place du prochain pivot, i depart -1
    for(int j = bas; j < haut; j++)
    {
        if(tab[j] < pivot)
        {
            i++;
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
    int temp = tab[i + 1];
    tab[i + 1] = tab[haut]; // soit pivot ou tab[haut]
    tab[haut] = temp;// tsy maintsy tab[haut]

    return i + 1;

}

void triRapide(int tab[], int bas, int haut)
{
    if(bas < haut)
    {
        int i_pivot = partition(tab, bas, haut);
        triRapide(tab, bas, i_pivot - 1);
        triRapide(tab, i_pivot + 1, haut);
    }
}
//------------------------------------------------------
void triInsertion(int array[], int n)
{
    int i, j, cle;
    for(i = 1; i < n; i++)
    {
        cle = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > cle)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = cle;

    }
}

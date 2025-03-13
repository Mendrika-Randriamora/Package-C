#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "recherche.h"

int rechercheLineaire(int tab[], int n, int cible)
{
    for(int i = 0; i < n; i++)
    {
        if(tab[i] == cible)
            return i;
    }

    return - 1;
}
//------------------------------------------------
int rechercheBinaire(int tab[], int n, int cible)
{
    int gauche = 0;
    int droite = n - 1;

    while(gauche < droite)
    {
        int milieu = gauche + (droite - gauche)/2;
        if(tab[milieu] == cible)
            return milieu;
        else if(tab[milieu] < cible)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }

    return -1;
}
//--------------------------------------------------
int rechercheInterpolee(int tab[], int n, int cible)
{
   int bas = 0;
   int haut = n - 1;

   while(bas <= haut && cible >= tab[bas] && cible <= tab[haut])
   {
       int pos;
       pos = bas + ((cible - tab[bas]) / (tab[haut] - tab[bas])) * (haut - bas);

       if(tab[pos] == cible)
        return pos;
       else if(tab[pos] < cible)
        bas = pos + 1;
       else
        haut = pos - 1;
   }

   return -1;
}
//------------------------------------------------------
int rechercheParSaut(int tab[], int n, int cible)
{
    int tailleBloc = sqrt(n);
    int i = 0;

    while(i < n && tab[i] < cible)
        i = i + tailleBloc;

    int deb = (i > 0) ? (i - tailleBloc) : i;

    for(int j = deb; j <= min(i, n); j++)
    {
        if(tab[j] == cible)
            return j;
    }

   return -1;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "physique.h"
int nourriture(Coordonnees* tab_pommes, Coordonnees* snake_entier, int size, int pom, int *nbpommes_mangees, int* score)
{
    int i;
    int taille = size;
    for(i = 0 ; i < pom ; i++)
    {
        if(snake_entier[taille-1].x == tab_pommes[i].x && snake_entier[taille-1].y == tab_pommes[i].y)
        {
          tab_pommes[i].x = 100000;
          tab_pommes[i].y = 100000;
          taille=taille+2;
          *nbpommes_mangees = *nbpommes_mangees + 1;
          *score = *score + 5;
        }
    }
    return taille;
}

int collision(Coordonnees* snake_entier, Coordonnees* tab_obs, int size, int obs, int m, int n)
{
    int i;
    int coli;
    for(i = 0 ; i < obs ; i++)
    {
        if(snake_entier[size-1].x == tab_obs[i].x && snake_entier[size-1].y == tab_obs[i].y)
        {
            coli = 1;
        }
    }
    for(i = 0 ; i < size-3 ; i++)
    {
        if(snake_entier[size-1].x == snake_entier[i].x && snake_entier[size-1].y == snake_entier[i].y)
        {
          coli = 1;
        }
    }
    if(snake_entier[size-1].x > n*20 || snake_entier[size-1].x < 0 || snake_entier[size-1].y > m*20 || snake_entier[size-1].y < 0)
    {
        coli = 1;
    }
    return coli;
}

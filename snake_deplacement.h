#ifndef SNAKE_DEPLACEMENT_H
#define SNAKE_DEPLACEMENT_H
#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

void deplacement_droite(Coordonnees* snake_entier,int size,int m, int n);
void deplacement_haut(Coordonnees* snake_entier,int size,int m, int n);
void deplacement_bas(Coordonnees* snake_entier,int size,int m, int n);
void deplacement_gauche(Coordonnees* snake_entier,int size,int m, int n);

#endif

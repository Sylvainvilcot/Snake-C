#ifndef PHYSIQUE_H
#define PHYSIQUE_H

#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "generation_pommes_obstacles.h"


int nourriture(Coordonnees* tab_pommes, Coordonnees* snake_entier, int size, int pom, int *nbpommes_mangees, int* score);
int collision(Coordonnees* snake_entier, Coordonnees* tab_obs, int size, int obs, int m, int n);

#endif

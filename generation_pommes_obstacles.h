#ifndef GENERATION_POMMES_OBSTACLES_H
#define GENERATION_POMMES_OBSTACLES_H

#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
  int x;
  int y;
};

void pommier(Coordonnees* tab_pommes,int pom, int m, int n);
void obstacle(Coordonnees* tab_obs, Coordonnees* tab_pommes,int pom,int obs,int m, int n);
void test_obs(Coordonnees* tab_obs, Coordonnees* tab_pommes, int m, int n, int pom, int obs);

#endif

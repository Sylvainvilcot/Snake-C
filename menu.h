#ifndef MENU_H
#define MENU_H
#include "generation_pommes_obstacles.h"
int menu_dep(int m, int n, int score, int niveau);
void menu_opt(int* n, int* m, int* size, int* pom, int t1, int obs, Coordonnees* snake_entier, Coordonnees* tab_pommes, Coordonnees* tab_obs);

#endif

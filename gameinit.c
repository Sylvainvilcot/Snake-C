#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameinit.h"
#include "generation_pommes_obstacles.h"


void init_snake(Coordonnees* snake_entier, int size, int m, int n)
{
  int i;
  for(i = 0 ; i < size ; i++)
  {
   snake_entier[i].x = (m*20)/2;
   snake_entier[i].y= (n*20)/2;
  }
}

void game(int size, int t1, int pom, int obs, int n, int m, Coordonnees* snake_entier, Coordonnees* tab_pommes, Coordonnees* tab_obs)
{
  int i;
  FermerGraphique();
  InitialiserGraphique();
  CreerFenetre(50,50,n*20,m*20+50);
  
  init_snake(snake_entier,size,n,m);

  ChoisirCouleurDessin(CouleurParComposante(164,245,131));
  RemplirRectangle(0,0,n*20,m*20);
  ChoisirCouleurDessin(CouleurParComposante(78,42,0));

  pommier(tab_pommes, pom, m, n);

  for(i=0;i<pom;i++)
  {
    ChoisirCouleurDessin(CouleurParNom("red"));
    RemplirRectangle(tab_pommes[i].x,tab_pommes[i].y,20,20);
  }

  obstacle(tab_obs,tab_pommes,pom,obs,m,n); 
  test_obs(tab_obs,tab_pommes,m,n,pom,obs);

  for(i=0;i<obs;i++)
  {
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(tab_obs[i].x,tab_obs[i].y,20,20);
  }

  ChoisirCouleurDessin(CouleurParComposante(78,42,0));
  RemplirRectangle(snake_entier[size-1].x,snake_entier[size-1].y,20,20);
}

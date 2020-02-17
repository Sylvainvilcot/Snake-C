#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "affichage_score.h"



void score_f(int* score, int m, int n)
{
  char afficher[30];
  sprintf(afficher,"Score : %d",*score);
  ChoisirCouleurDessin(CouleurParComposante(0,0,0));
  EcrireTexte(50,m*20 + 40,afficher, 2);
}

void niveau_f(int* niveau, int m, int n)
{
  char afficher[30];
  sprintf(afficher,"Niveau  : %d",*niveau);
  ChoisirCouleurDessin(CouleurParComposante(0,0,0));
  EcrireTexte(n*20-200,m*20 + 40,afficher, 2);
}

void nb_pommes(int* nbpommes_mangees, int* pom, int m, int n)
{
  char afficher[30];
  sprintf(afficher,"Pommes : %d/%d",*nbpommes_mangees,*pom);
  ChoisirCouleurDessin(CouleurParComposante(0,0,0));
  EcrireTexte(n*10-100,m*20 + 40,afficher, 2);
}

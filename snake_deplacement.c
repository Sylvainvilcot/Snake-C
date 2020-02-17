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
void deplacement_droite(Coordonnees* snake_entier,int size,int m, int n)
{
  int i;
  for(i = 0 ; i < size-1 ; i++)
  {
    snake_entier[i].x=snake_entier[i+1].x;
    snake_entier[i].y=snake_entier[i+1].y;
  }
  snake_entier[size-1].x=snake_entier[size-1].x+20;
}

void deplacement_haut(Coordonnees* snake_entier,int size,int m, int n)
{
  int i;
  for(i = 0 ; i < size-1 ; i++)
  {
    snake_entier[i].x=snake_entier[i+1].x;
    snake_entier[i].y=snake_entier[i+1].y;
  }
  snake_entier[size-1].y=snake_entier[size-1].y-20;
}

void deplacement_bas(Coordonnees* snake_entier,int size,int m, int n)
{
  int i;
  for(i = 0 ; i < size-1 ; i++)
  {
    snake_entier[i].x=snake_entier[i+1].x;
    snake_entier[i].y=snake_entier[i+1].y;
  }
  snake_entier[size-1].y=snake_entier[size-1].y+20;
}

void deplacement_gauche(Coordonnees* snake_entier,int size,int m, int n)
{
  int i;
  for(i = 0 ; i < size-1 ; i++)
  {
    snake_entier[i].x=snake_entier[i+1].x;
    snake_entier[i].y=snake_entier[i+1].y;
  }
  snake_entier[size-1].x=snake_entier[size-1].x-20;
}

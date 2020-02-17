#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "affichage_score.h"
#include "gameinit.h"
#include "generation_pommes_obstacles.h"
#include "menu.h"
#include "physique.h"
#include "snake_deplacement.h"

int main(int argc, char* argv[])
{
  int size = 10;
  int x, y=0;
  int t1=150000,t3, tmp=0, pom = 5, obs = 0;
  unsigned int timer1=0, timer2=0, touche;
  int nbpommes_mangees = 0;
  int score = 0;
  int i, n = 60, m = 40;
  int taille = size;
  int fixed_size = size;
  int tempo = 0;
  int tempor=0;
  int pause = 0;
  int niveau=1;
  Coordonnees* snake_entier = malloc(sizeof(Coordonnees) * size);
  Coordonnees* tab_pommes = malloc(sizeof(Coordonnees) * pom);
  Coordonnees* tab_obs = malloc(sizeof(Coordonnees) * obs);


  timer1=Microsecondes();
  srand(time(NULL));


  InitialiserGraphique();
  CreerFenetre(50,50,1200,800);

    if(y==0)
      y=menu_dep(m,n,score,niveau);
    if(y==1)
    {
      game(size, t1, pom, obs, n, m, snake_entier, tab_pommes, tab_obs);
    }
    if(y==2)
    {
      menu_opt(&n,&m,&size,&pom,t1,obs,snake_entier,tab_pommes,tab_obs);
    }
    if(y==3)
    {
      free(tab_pommes);
      free(tab_obs);
      free(snake_entier);
      FermerGraphique();
      exit(0);
    }


    /*printf("Size : %d\n",size);
    printf("Pom : %d\n",pom);
    printf("obs : %d\n",obs);*/

  while(1) 
  {
    if(nbpommes_mangees == pom)
    {
      pom++;
      obs++;
      t1=t1-400;
      niveau++;
      size = fixed_size;
      nbpommes_mangees = 0;
      pause=1;
      x=0;
      /*printf("Size : %d\n",size);
      printf("Pom : %d\n",pom);
      printf("obs : %d\n",obs);*/
      snake_entier = realloc(snake_entier, size * sizeof(Coordonnees));
      tab_pommes = realloc(tab_pommes, pom * sizeof(Coordonnees));
      tab_obs = realloc(tab_obs, obs * sizeof(Coordonnees));
      game(size, t1, pom, obs, n, m, snake_entier, tab_pommes, tab_obs);
    }

    if(ToucheEnAttente()==1)
    {
      touche = Touche();
      if(touche == XK_space)
      {
        tempor++;
        pause = 1;
      }
      if(touche == XK_Escape)
      {
        exit(0);
      }
      if(touche == XK_Left && x !=2)
      {
        x = 1;
      }
      if(touche == XK_Right && x !=1)
      {
        x = 2;
      }
      if(touche == XK_Up && x !=4)
      {
        x = 3;
      }
      if(touche == XK_Down && x !=3)
      {
        x = 4;
      }
      if(tempor%2 == 0)
      {
         pause = 0;
      }
    }
    ChoisirCouleurDessin(CouleurParComposante(0,107,12));

    for(i=0;i<n+1;i++)
    {
      DessinerSegment(i*20,0,i*20,m*20);
    }

    for(i=0;i<m+1;i++)
    {
      DessinerSegment(0,i*20,n*20,i*20);
    }
    ChoisirCouleurDessin(CouleurParComposante(164,245,131));
    RemplirRectangle(0,m*20+1,n*20,m*20+50);

    timer2=Microsecondes();
    t3=(timer2-timer1);

    ChoisirCouleurDessin(CouleurParComposante(78,42,0));
    score_f(&score, m ,n);
    niveau_f(&niveau, m ,n);
    nb_pommes(&nbpommes_mangees,&pom,m,n);

    if(t3/t1 > tmp && pause == 0)
    {
      taille = nourriture(tab_pommes,snake_entier,size, pom, &nbpommes_mangees, &score);
      if(taille > size)
      {
        snake_entier = realloc(snake_entier, taille * sizeof(Coordonnees));
        for(i = 1 ; i < taille-1 ; i++)
        {
          snake_entier[taille-i].x = snake_entier[taille-(i+2)].x;
          snake_entier[taille-i].y = snake_entier[taille-(i+2)].y;
        }
        size = taille;
      }

      ChoisirCouleurDessin(CouleurParComposante(164,245,131));

      for(i=0;i<size;i++)
      {
        RemplirRectangle(snake_entier[i].x,snake_entier[i].y,20,20);
      }

      if(x == 1)
        {
          deplacement_gauche(snake_entier,size,m,n);
            tempo=1;
        }
      if(x == 2)
        {
          deplacement_droite(snake_entier,size,m,n);
            tempo=1;
        }
      if(x == 3)
      {
        deplacement_haut(snake_entier,size,m,n);
        tempo=1;
      }
      if(x == 4)
        {
        deplacement_bas(snake_entier,size,m,n);
          tempo=1;
        }
      if(tempo == 1)
      {
          if(collision(snake_entier,tab_obs, size, obs, m, n) == 1)
          {
            y=menu_dep(m,n,score,niveau);
            if(y==1)
            {
              pom=5;
              obs=0;
              size=10;
            }
           if(y==2)
            {
              menu_opt(&n,&m,&size,&pom,t1,obs,snake_entier,tab_pommes,tab_obs);
            }
            if(y==3)
            {
              free(snake_entier);
              free(tab_pommes);
              free(tab_obs);
              FermerGraphique();
              exit(0);
            }
            nbpommes_mangees = 0;
            score=0;
            niveau=1;
            pause=1;
            x=0;
            snake_entier = realloc(snake_entier, sizeof(Coordonnees) * size);
            tab_pommes = realloc(tab_pommes,sizeof(Coordonnees) * pom);
            tab_obs = realloc(tab_obs, obs * sizeof(Coordonnees));
            game(size, t1, pom, obs, n, m, snake_entier, tab_pommes, tab_obs);
          }
        }
      for(i=0;i<size;i++)
      {
        ChoisirCouleurDessin(CouleurParComposante(78,42,0));
        RemplirRectangle(snake_entier[i].x,snake_entier[i].y,20,20);
      }
      tmp=t3/t1;
    }
  }
  return 0;
}
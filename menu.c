#include <time.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include "affichage_score.h"
#include "menu.h"

int menu_dep(int m, int n, int score, int niveau)
{
  int x=0;
  FermerGraphique();
  InitialiserGraphique();
  CreerFenetre(50,50,n*20,m*20+50);
  ChoisirCouleurDessin(CouleurParComposante(200,200,131));
  RemplirRectangle(0,0,n*20,m*20+50);
  ChoisirCouleurDessin(CouleurParComposante(124,108,89));
  RemplirRectangle(330,500,500,100);
  RemplirRectangle(330,300,500,100);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(555,360,"PLAY",2);
  EcrireTexte(535,560,"OPTIONS",2);
  EcrireTexte(20,750,"QUITTER",2);
  score_f(&score, m ,n);
  niveau_f(&niveau, m ,n);

  SourisCliquee();
  while(x==0)
  {
    if(SourisCliquee()==1)
    {
      if(_X>=330 && _X<=830 && _Y>=300 && _Y<=400)
      {
        x=1;
      }
      if(_X>=330 && _X<=830 && _Y>=500 && _Y<=600)
      {
        x=2;
      }
      if(_X>=20 && _X<=110 && _Y<=750 && _Y>=730)
      {
        x=3;
      }
    }
  }
  return x;
}



void menu_opt(int* n, int* m, int* size, int* pom, int t1, int obs, Coordonnees* snake_entier, Coordonnees* tab_pommes, Coordonnees* tab_obs)
{
  int tmp=0;
  ChoisirCouleurDessin(CouleurParComposante(200,200,131));
  RemplirRectangle(0,0,1200,800);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(450,160,"TAILLE FENETRE (DEFAUT : TAILLE 4)",2);
  EcrireTexte(450,360,"NOMBRE POMMES (DEFAUT : 5)", 2);
  EcrireTexte(450,560,"TAILLE SERPENT (DEFAUT : 10)",2);

  ChoisirCouleurDessin(CouleurParComposante(124,108,89));
  RemplirRectangle(410,200,50,50);
  RemplirRectangle(500,200,50,50);
  RemplirRectangle(590,200,50,50);
  RemplirRectangle(680,200,50,50);
  RemplirRectangle(770,200,50,50);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(430,235,"1",2);
  EcrireTexte(520,235,"2",2);
  EcrireTexte(610,235,"3",2);
  EcrireTexte(700,235,"4",2);
  EcrireTexte(790,235,"5",2);

  ChoisirCouleurDessin(CouleurParComposante(124,108,89));
  RemplirRectangle(410,400,50,50);
  RemplirRectangle(500,400,50,50);
  RemplirRectangle(590,400,50,50);
  RemplirRectangle(680,400,50,50);
  RemplirRectangle(770,400,50,50);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(430,435,"3",2);
  EcrireTexte(520,435,"4",2);
  EcrireTexte(610,435,"5",2);
  EcrireTexte(700,435,"6",2);
  EcrireTexte(790,435,"7",2);

  ChoisirCouleurDessin(CouleurParComposante(124,108,89));
  RemplirRectangle(410,600,50,50);
  RemplirRectangle(500,600,50,50);
  RemplirRectangle(590,600,50,50);
  RemplirRectangle(680,600,50,50);
  RemplirRectangle(770,600,50,50);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(430,635,"7",2);
  EcrireTexte(520,635,"10",2);
  EcrireTexte(610,635,"15",2);
  EcrireTexte(700,635,"18",2);
  EcrireTexte(790,635,"22",2);

  ChoisirCouleurDessin(CouleurParComposante(124,108,89));
  RemplirRectangle(517,730,150,40);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(550,760,"CONFIRM",2);

  SourisCliquee();
  while(tmp==0)
  {
    if(SourisCliquee()==1)
    {
      if(_X>=410 && _X<=460 && _Y>=200 && _Y<=250)
      {
        *n=30;
        *m=20;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(430,235,"1",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(520,235,"2",2);
        EcrireTexte(610,235,"3",2);
        EcrireTexte(700,235,"4",2);
        EcrireTexte(790,235,"5",2);
      }
      if(_X>=500 && _X<=550 && _Y>=200 && _Y<=250)
      {
        *n=50;
        *m=30;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(520,235,"2",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,235,"1",2);
        EcrireTexte(610,235,"3",2);
        EcrireTexte(700,235,"4",2);
        EcrireTexte(790,235,"5",2);
      }
      if(_X>=590 && _X<=640 && _Y>=200 && _Y<=250)
      {
        *n=50;
        *m=40;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(610,235,"3",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(520,235,"2",2);
        EcrireTexte(430,235,"1",2);
        EcrireTexte(700,235,"4",2);
        EcrireTexte(790,235,"5",2);
      }
      if(_X>=680 && _X<=730 && _Y>=200 && _Y<=250)
      {
        *n=60;
        *m=40;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(700,235,"4",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(610,235,"3",2);
        EcrireTexte(520,235,"2",2);
        EcrireTexte(430,235,"1",2);
        EcrireTexte(790,235,"5",2);
      }
      if(_X>=770 && _X<=820 && _Y>=200 && _Y<=250)
      {
        *n=70;
        *m=40;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(790,235,"5",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(610,235,"3",2);
        EcrireTexte(520,235,"2",2);
        EcrireTexte(430,235,"1",2);
        EcrireTexte(700,235,"4",2);
      }
      if(_X>=410 && _X<=460 && _Y>=400 && _Y<=450)
      {
        *pom=3;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(430,435,"3",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(520,435,"4",2);
        EcrireTexte(610,435,"5",2);
        EcrireTexte(700,435,"6",2);
        EcrireTexte(790,435,"7",2);
      }
      if(_X>=500 && _X<=550 && _Y>=400 && _Y<=450)
      {
        *pom=4;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(520,435,"4",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,435,"3",2);
        EcrireTexte(610,435,"5",2);
        EcrireTexte(700,435,"6",2);
        EcrireTexte(790,435,"7",2);
      }
      if(_X>=590 && _X<=640 && _Y>=400 && _Y<=450)
      {
        *pom=5;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(610,435,"5",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,435,"3",2);
        EcrireTexte(520,435,"4",2);
        EcrireTexte(700,435,"6",2);
        EcrireTexte(790,435,"7",2);
      }
      if(_X>=680 && _X<=730 && _Y>=400 && _Y<=450)
      {
        *pom=6;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(700,435,"6",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,435,"3",2);
        EcrireTexte(520,435,"4",2);
        EcrireTexte(610,435,"5",2);
        EcrireTexte(790,435,"7",2);
      }
      if(_X>=770 && _X<=820 && _Y>=400 && _Y<=450)
      {
        *pom=7;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(790,435,"7",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,435,"3",2);
        EcrireTexte(520,435,"4",2);
        EcrireTexte(610,435,"5",2);
        EcrireTexte(700,435,"6",2);
      }
      if(_X>=410 && _X<=460 && _Y>=600 && _Y<=650)
      {
        *size=7;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(430,635,"7",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(520,635,"10",2);
        EcrireTexte(610,635,"15",2);
        EcrireTexte(700,635,"18",2);
        EcrireTexte(790,635,"22",2);
      }
      if(_X>=500 && _X<=550 && _Y>=600 && _Y<=650)
      {
        *size=10;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(520,635,"10",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,635,"7",2);
        EcrireTexte(610,635,"15",2);
        EcrireTexte(700,635,"18",2);
        EcrireTexte(790,635,"22",2);
      }
      if(_X>=590 && _X<=640 && _Y>=600 && _Y<=650)
      {
        *size=15;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(610,635,"15",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,635,"7",2);
        EcrireTexte(520,635,"10",2);
        EcrireTexte(700,635,"18",2);
        EcrireTexte(790,635,"22",2);
      }
      if(_X>=680 && _X<=730 && _Y>=600 && _Y<=650)
      {
        *size=18;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(700,635,"18",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,635,"7",2);
        EcrireTexte(520,635,"10",2);
        EcrireTexte(610,635,"15",2);
        EcrireTexte(790,635,"22",2);
      }
      if(_X>=770 && _X<=820 && _Y>=600 && _Y<=650)
      {
        *size=22;
        ChoisirCouleurDessin(CouleurParNom("red"));
        EcrireTexte(790,635,"22",2);
        ChoisirCouleurDessin(CouleurParNom("black"));
        EcrireTexte(430,635,"7",2);
        EcrireTexte(520,635,"10",2);
        EcrireTexte(610,635,"15",2);
        EcrireTexte(700,635,"18",2);
      }
      if(_X>=517 && _X<=667 && _Y>=730 && _X<=770)
      {
        tmp=1;
      }
    }
  }
}

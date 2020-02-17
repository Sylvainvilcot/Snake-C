#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "generation_pommes_obstacles.h"

void pommier(Coordonnees* tab_pommes,int pom, int m, int n)
{
    int i;
    for( i = 0 ; i < pom ; i++)
    {
        tab_pommes[i].x = rand()%n*20;
        tab_pommes[i].y = rand()%m*20;
    }
}

void obstacle(Coordonnees* tab_obs, Coordonnees* tab_pommes,int pom,int obs,int m, int n)
{
    int i;
    for( i = 0 ; i < obs ; i++)
    {
        tab_obs[i].x = rand()%n*20;
        tab_obs[i].y = rand()%m*20;
    }
}

void test_obs(Coordonnees* tab_obs, Coordonnees* tab_pommes, int m, int n, int pom, int obs)
{
    int i,j;
    for(i = 0 ; i < pom ; i++)
    {
        for(j = 0 ; j < obs ; j++)
        {
            if(tab_obs[j].x==tab_pommes[i].x && tab_obs[j].y==tab_pommes[i].y)
            {
              pommier(tab_pommes,pom,m,n);
            }
            if(tab_obs[j].x==n/2 && tab_obs[j].y==m/2)
            {
              obstacle(tab_obs, tab_pommes,pom,obs,m,n);
            }
        }
    }
}

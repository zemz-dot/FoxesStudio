#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "IA.h"


void intialiser(Objet *perso ,Objet *zombie)
{
  perso->img=IMG_Load("1.png") ;
  perso->pos.x=50 ;
  perso->pos.y=50 ;

  zombie->img=IMG_Load("zombie.png") ;
  zombie->pos.x=600 ;
  zombie->pos.y=50 ;

}


void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
 SDL_WM_SetCaption("Amin Hlel : collision trigo", NULL);
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
 SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
 SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
 SDL_Flip(screen) ;

}



float calculer_distance (Objet *objet1,Objet *objet2)
{
  float D ;

  D=sqrt( pow( (objet1->c.x) - (objet2->c.x) ,2 ) + pow ( (objet1->c.y) - (objet2->c.y) , 2  ) ) ;

  return D ;
}


int verif_collision ( Objet *objet1,Objet *objet2,float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=objet1->c.rayon + objet2->c.rayon ;

  if(abs(D2-D1)<50 )
    collision= 1 ;

  return collision ;
}

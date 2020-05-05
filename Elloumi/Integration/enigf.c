#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "game.h"

void init_enigme(enigme * e)
{
	e->p.x=50;
	e->p.y=50;	
	e->img=NULL;


}

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"Enigme/%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;

}
 
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"Enigme/1.jpg")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"Enigme/2.jpg")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"Enigme/3.jpg")==0)
 	{
 		solution =3;	
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;

	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 1;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}
 
 int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en )
 {
  int x ; 
 	if (r==s)
 	{

         x=1 ; 
 	}
 	else
 	{
 
        x=0 ; 
        
 	}
return x ; 
 }
 

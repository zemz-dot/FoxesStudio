#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"game.h"



void animation_entite_droite(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond)
{

SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

SDL_BlitSurface(E->spriteright,&rects[E->curframe],screen,&E->dst);
 E->curframe++;
SDL_Flip(screen) ; 
SDL_Delay(50) ;




if(E->curframe==E->maxframe)
{
E->curframe=0;
}





}

/*void animation_entite(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond)
{
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_BlitSurface(E->spriteright,&rects[E->curframe],screen,&E->dst);
 E->curframe--;
SDL_Flip(screen) ;
SDL_Delay(600) ;
 
if(E->curframe==1)
{
E->curframe=E->maxframe;
}
}*/



/*void animation_entite(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond,int continuer)
{int i=0;int k=0;
if(k==0)
     {if(E->frame.x!=E->maxframe)
                          
                      { E->frame.x = E->curframe*(Sint16)E->frame.w;
			
			
                         SDL_BlitSurface(Background,&positionFond,screen,NULL);
                          SDL_BlitSurface(E->spriteright,&rects[E->curframe],screen,&E->dst);
                           E->curframe++;
                          SDL_Flip(screen);
			
                       
                          SDL_Delay(500);}
     else k=1;
}
if(k==1)
{if(i==E->maxframe)
                       {
                            i=0;
                       } 
 else k=0;
}
                         
              
                     
}*/

/*void animation_entite(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond)
{
E->curframe+=1;
	if(E->curframe>E->maxframe)
	{
		E->curframe=0;
	}
E->frame.x=E->curframe*E->frame.w;
SDL_Delay(15);
}*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"


void scrolling(SDL_Surface *ecran,SDL_Surface *imageDeFond ,int continuer,SDL_Rect positionFond)
     {
    positionFond.x = 0;
    positionFond.y = 0;
    positionFond.h =1080;
    positionFond.w =1920;

    
    imageDeFond = IMG_Load("map.png");
   
  SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
              
    SDL_Flip(ecran);
    
 
    SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // Flèche droite
            	
                if  ( positionFond.x<=5760)
       
            positionFond.x += 100;
     
            
       
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
            
                
    SDL_Flip(ecran);

                break;

            case SDLK_LEFT: // Flèche gauche
            	if ( positionFond.x>=0)
        
            positionFond.x -= 100;
     
         
                SDL_BlitSurface(imageDeFond,&positionFond, ecran, NULL);
				
                
    SDL_Flip(ecran);

                break;
              

        }

        break;    
        }

       
        
    SDL_Flip(ecran);
    }
}

   

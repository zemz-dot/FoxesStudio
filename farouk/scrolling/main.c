#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
int main()
{
SDL_Surface *ecran=NULL;
SDL_Surface *imageDeFond=NULL;
int continuer=1;
SDL_Rect positionFond;
SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement Backgroung", NULL);  
 
 scrolling(ecran,imageDeFond , continuer, positionFond);


SDL_FreeSurface(imageDeFond);
 SDL_Quit();

    return EXIT_SUCCESS;
}

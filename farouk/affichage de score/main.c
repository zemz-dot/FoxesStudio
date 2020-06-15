#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "score.h"

int main()
{ 
	SDL_Surface *screen;
        int i;
       score s;
int run =1;
 SDL_Init ( SDL_INIT_VIDEO ) ;
screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );

 init_score( &s);
 while (run)
{
//SDL_FillRect(screen,	NULL,SDL_MapRGB(screen->format,0,0,0));
 i=afficherscore(&s,screen  );
SDL_Flip(screen);
}
  SDL_FreeSurface(screen);
      SDL_Quit();
return 0;
}

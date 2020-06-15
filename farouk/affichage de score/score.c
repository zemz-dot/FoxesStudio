#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "score.h"
void init_score( score *s)
{
s->ps.x=0;
s->ps.y=0;
s->fond1=NULL;
}
int afficherscore(score *s,SDL_Surface *screen  )
{  char img[30];
int i;
   for(i=0;i<11;i++)
{

sprintf(img,"s%d.png",i);
s->fond1=IMG_Load(img);
SDL_FillRect(screen,	NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_BlitSurface(s->fond1,NULL, screen,&s->ps);
SDL_Delay(4000);
SDL_Flip(screen);
}

return i;
}

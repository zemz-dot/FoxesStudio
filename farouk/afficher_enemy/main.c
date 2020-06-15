#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"game.h"

int  main()
{

SDL_Surface*screen;
SDL_Rect positionecran;
SDL_Event event;

char pause ;
int done=1;
enemy E;

initialiser_enemy(E);

/*if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)

{
printf("Unable to set video mode :%s\n",SDL_GetError());
return 1;
}

positionecran.x=0;
positionecran.y=0;*/

afficher_enemy(E,screen);













}

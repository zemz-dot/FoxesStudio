#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"game.h"






int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}

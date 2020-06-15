#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>



typedef struct
{

SDL_Rect  position_enemy;
SDL_Surface * image_enemy;


} enemy;

typedef struct 
{
        SDL_Surface * temps;
	SDL_Rect position_temps;

	int heure;
	
	int minute;
	
	int seconde;
	
	 
	TTF_Font *police;

	int tempsactuel;
	int tempsprecedent;
	

	
}temps;

void initialiser_enemy(enemy E);
int afficher_enemy(enemy E,SDL_Surface*screen);


















































#endif /* FONCTIONS_H_ */

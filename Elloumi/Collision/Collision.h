#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int collisionbb( SDL_Rect posj , SDL_Rect posobj ) ; 
int collisiontrigoinscrit ( SDL_Rect posj , SDL_Rect posobj ) ; 
int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj );



#endif /* FONCTIONS_H_ */

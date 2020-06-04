#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int collisionbb( SDL_Rect posj , SDL_Rect posobj ) ; 
int collisionpp ( SDL_SURFACE *background_mask,int x, int y) ; 
int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj );



#endif /* FONCTIONS_H_ */

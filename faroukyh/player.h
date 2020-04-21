#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "structs.h"

extern Gestion jeu;
extern Personnage player;
extern Input input;

/* Prototype des fonctions externes que nous allons utiliser ensuite */
extern SDL_Surface *loadImage(char *name);

#endif // PLAYER_H_INCLUDED

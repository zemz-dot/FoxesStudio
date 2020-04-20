#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "jeu.h"
#include "constantes.h"



SDL_Rect positionJoueur;//position de notre link

void jouer(SDL_Surface* ecran){


SDL_Surface *link[4]={NULL}; //puisque on a 4 position de la perssonage
SDL_Surface *linkActuel =NULL;//est ce que le link est dans telle ou telle position est il devant derriere a droite ou a gauche ...


SDL_Event event ;
int continuer=1
int i=0 , j=0;

link[bas]=IMG_Load("link1.bmp");
linkActuel=link[BAS];

positionJoueur.x=3;
positionJoueur.y=3;


while(continuer){

SDL_WaitEevent(&event);
switch(event.type);
{
case SDL_Quit:
continuer=0;
break;
}

SDL_FillRect(ecran,NULL,SDL_xMapRGB(ecran->format,255,255,255));//ca c'est un exemple , cest un arriere plan blanc mais nous on va mettre  notre arriere paln de notre jeu

position.x=positionJoueur.x*TAILLE_BLOC;//position de joueur sur l axe des abssices
position.y=positionJoueur.yTAILLE_BLOC;//position de joueur sur laxe des ordonnees

SDL_Blitsurface(linkActuel,NULL,ecran, &position);
SDL_Flip(ecran);
}

for (i=0;i<4;i++){
SDL_FreeSurface(link[i]);
}
}


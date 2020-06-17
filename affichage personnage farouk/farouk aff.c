#include"fonction.h"


void affichage(personnage joueur){
SDL_Surface * screen;
int i;


    SDL_SetColorKey(joueur.perso[i], SDL_SRCCOLORKEY, SDL_MapRGB(joueur.perso[i]->format, 0, 0, 255));
    SDL_BlitSurface(joueur.perso[i], NULL, screen, &joueur.pos) ;


}

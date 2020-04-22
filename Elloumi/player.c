#include "player.h"
   void initializePlayer(void)
{

    /* Charge le sprite de notre héros */
    player.sprite = loadImage("graphics/walkright.png");

    //Indique l'état et la direction de notre héros
    player.direction = RIGHT;
    player.etat = IDLE;

    //Réinitialise le timer de l'animation et la frame
    player.frameNumber = 0;
    player.frameTimer = TIME_BETWEEN_2_FRAMES;

    /* Coordonnées de démarrage de notre héros */
    player.x = 0;
    player.y = 0;

    /* Hauteur et largeur de notre héros */
    player.w = PLAYER_WIDTH;
    player.h = PLAYER_HEIGTH;

    //Variables nécessaires au fonctionnement de la gestion des collisions
    player.timerMort = 0;
    player.onGround = 0;
   
    //Nombre de monstres (à déplacer plus tard dans initialzeGame())
    jeu.nombreMonstres = 0;

    //On recharge la map
    loadMap("map/map1.txt");

}

void drawplayer()
{
    /* Rectangle de destination à blitter */
	SDL_Rect dest;

    // On soustrait des coordonnées de notre héros, ceux du début de la map, pour qu'il colle
    //au scrolling :
	dest.x = player.x - map.startX;
	dest.y = player.y - map.startY;
	dest.w = PLAYER_WIDTH;
	dest.h = PLAYER_HEIGTH;

	/* Rectangle source à blitter */
	SDL_Rect src;

    //Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
    //la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
	src.x = player.frameNumber * PLAYER_WIDTH;
	src.y = 0;
	src.w = PLAYER_WIDTH;
	src.h = PLAYER_HEIGTH;

	/* Blitte notre héros sur l'écran aux coordonnées x et y */

	SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}

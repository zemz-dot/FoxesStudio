//fonction pour l affichage de notre Personnage
void drawplayer()
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    dest.w = PLAYER_WIDTH;//définir la hauteur et la largeur de notre Personnage.
    dest.h = PLAYER_HEIGTH;//définir la hauteur et la largeur de notre Personnage

    /* Rectangle source à blitter */
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre Personnage sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}

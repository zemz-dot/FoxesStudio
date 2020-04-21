 void draw(void)
{

    /* Affiche le fond (background) aux coordonnées (0,0) */
    drawImage(map.background, 0, 0);

    /* Affiche la map de tiles */
    drawMap();

    /* Affiche le joueur */
    drawplayer();

    /* Affiche l'écran */
    SDL_Flip(jeu.screen);

    /* Delai */

    SDL_Delay(1);

}

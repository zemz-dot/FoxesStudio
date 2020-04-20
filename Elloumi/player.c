
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

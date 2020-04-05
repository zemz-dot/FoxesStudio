   void initializePlayer(void)
  {

    /* Charge le sprite de notre héros */
    player.sprite = loadImage("graphics/walkright.png");

    //Indique l'état et la direction de notre héros
    player.direction = RIGHT,LEFT,UP,DOWN;
    player.etat = WALK;

    player.frameNumber = 0;
    player.frameTimer = TIME_BETWEEN_2_FRAMES;

    player.x = 0;
    player.y = 0;
   
    player.w = PLAYER_WIDTH;
    player.h = PLAYER_HEIGTH;

    player.timerMort = 0;
    player.onGround = 0;

  }

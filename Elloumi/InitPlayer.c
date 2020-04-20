   void initializePlayer(void)
  {

    player.sprite = loadImage("graphics/walkright.png");

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

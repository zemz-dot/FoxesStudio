  void mapCollision(Hero *entity)
 {

    int i, x1, x2, y1, y2;

  


    if(entity->h > TILE_SIZE)
        i = TILE_SIZE;
    else
        i = entity->h;


    for (;;)
    {

        x1 = (entity->x + entity->dirX) / TILE_SIZE;
        x2 = (entity->x + entity->dirX + entity->w - 1) / TILE_SIZE;

   .

        y1 = (entity->y) / TILE_SIZE;
        y2 = (entity->y + i - 1) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
         

            if (entity->dirX > 0)
            {


                if (map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
                {
                   

                    entity->x = x2 * TILE_SIZE;

                    entity->x -= entity->w + 1;

                    entity->dirX = 0;

                }

            }

        

            else if (entity->dirX < 0)
            {

                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE)
                {

                    entity->x = (x1 + 1) * TILE_SIZE;

                    entity->dirX = 0;
                }


            }

        }

        if (i == entity->h)
        {
            break;
        }

        i += TILE_SIZE;

        if (i > entity->h)
        {
            i = entity->h;
        }
    }

    if(entity->w > TILE_SIZE)
        i = TILE_SIZE;
    else
        i = entity->w;


    for (;;)
    {
        x1 = (entity->x) / TILE_SIZE;
        x2 = (entity->x + i) / TILE_SIZE;

        y1 = (entity->y + entity->dirY) / TILE_SIZE;
        y2 = (entity->y + entity->dirY + entity->h) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (entity->dirY > 0)
            {

                if (map.tile[y2][x1] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
                {
                   
                    entity->y = y2 * TILE_SIZE;
                    entity->y -= entity->h;

                    entity->dirY = 0;

                    entity->onGround = 1;
                }

            }

            else if (entity->dirY < 0)
            {

                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE)
                {

                    entity->y = (y1 + 1) * TILE_SIZE;

                    entity->dirY = 0;

                }

            }
        }

        if (i == entity->w)
        {
            break;
        }

        i += TILE_SIZE;

        if (i > entity->w)
        {
            i = entity->w;
        }
    }

    
    entity->x += entity->dirX;
    entity->y += entity->dirY;

   
    if (entity->x < 0)
    {
        entity->x = 0;
    }

    else if (entity->x + entity->w >= map.maxX)
    {
        entity->x = map.maxX - entity->w - 1;
    }

  
    if (entity->y > map.maxY)
    {
        entity->timerMort = 60;
    }
}
  void updatePlayer(void)
 {

   
  if (player.timerMort == 0)
  {
    player.dirX = 0;

  
    player.dirY += GRAVITY_SPEED;


    if (player.dirY >= MAX_FALL_SPEED)
    {
        player.dirY = MAX_FALL_SPEED;
    }

 
     if (input.left == 1)
    {
        player.dirX -= PLAYER_SPEED;

        if(player.direction == RIGHT)
        {
            player.direction = LEFT;
            player.sprite = loadImage("graphics/walkleft.png");
        }
    }

    else if (input.right == 1)
    {
        player.dirX += PLAYER_SPEED;

        if(player.direction == LEFT)
        {
            player.direction =  RIGHT;
            player.sprite = loadImage("graphics/walkright.png");
        }

    }


    if (input.jump == 1 && player.onGround)
    {
        player.dirY = -JUMP_HEIGHT;
        player.onGround = 0;

    }

 
    mapCollision(&player);
    centerScrollingOnPlayer();

  }

    if (player.timerMort > 0)
    {
        player.timerMort--;

        if (player.timerMort == 0)
        {
            /* Si on est mort */
            initializePlayer();
        }
    }

  }

 

 void update(void)
{

     if (input.left == 1)
    {
        map.startX -= TILE_SIZE;

        if (map.startX < 0)
        {
            map.startX = 0;
        }
    }

    else if (input.right == 1)
    {
        map.startX += TILE_SIZE;

        if (map.startX + SCREEN_WIDTH >= map.maxX)
        {
            map.startX = map.maxX - SCREEN_WIDTH;
        }
    }

    if (input.up == 1)
    {
        map.startY -= TILE_SIZE;

        if (map.startY < 0)
        {
            map.startY = 0;
        }
    }

    else if (input.down == 1)
    {
        map.startY += TILE_SIZE;

        if (map.startY + SCREEN_HEIGHT >= map.maxY)
        {
            map.startY = map.maxY - SCREEN_HEIGHT;
        }
    }

}

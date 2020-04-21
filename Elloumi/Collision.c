  //Fonction de gestion des collisions
 #include "Collision.h"
   int collide(GameObject *player, GameObject *boxes)
 {
    if ((player->x >= boxes->x + boxes->w)
    || (player->x + player->w <= boxes->x)
    || (player->y >= boxes->y + boxes->h)
    || (player->y + player->h <= boxes->y)
    )
        return 0;
    else if (player->y + player->h <= boxes->y + boxes->h || player->x + player->w <= boxes->x + boxes->w)
    {
        player->dirY = 0;
	player->dirX = 0;
        return 1;
    }
   
}
         

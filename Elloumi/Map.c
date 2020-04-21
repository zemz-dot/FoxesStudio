#include "map.h"  
void mapCollision(Hero *entity)
 {

    int i, x1, x2, y1, y2;

  
//decouper notre sprite en bloc de tiles 
    //pour voir quelle tiles est susceptible de recouvrir 
    //donnant la valeur TILE_SIZE à i pour qu'on trouve le x du joueur 
    

    if(entity->h > TILE_SIZE)
        i = TILE_SIZE;
    else //ou cas inferieur on lui donnera la vraie valeur de la taille du sprite 
        i = entity->h;

//boucle infinie pour calculer les tiles ! 
    for (;;)
    { 
      //on va calculer les coins du tiles à gauche et à droite où il touche 

        x1 = (entity->x + entity->dirX) / TILE_SIZE;
        x2 = (entity->x + entity->dirX + entity->w - 1) / TILE_SIZE;

   .//même chose avec Y et on va tester tout la hauteur de notre sprite grace à variable i 

        y1 = (entity->y) / TILE_SIZE;
        y2 = (entity->y + i - 1) / TILE_SIZE;
 //test du mouvement initiés dans updateplayer grace aux vecteurs dirX,dirY  qu'on se situe bien  sur les limites de l'ecran 
        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
         
        //mouvement à droite
            if (entity->dirX > 0)
            {


                if (map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
                {
                   

                    entity->x = x2 * TILE_SIZE;

                    entity->x -= entity->w + 1;

                    entity->dirX = 0;

                }

            }

        
//à gauche 
            else if (entity->dirX < 0)
            {
   
                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE)
                {

                    entity->x = (x1 + 1) * TILE_SIZE;

                    entity->dirX = 0;
                }


            }

        }
 //on sort de la boucle  si on a testé les tiles  le long de la hauteur du sprite
        if (i == entity->h)
        {
            break;
        }
//sinon , on teste les tiles supérieures en se limitant à la hauteur du sprite 
        i += TILE_SIZE;

        if (i > entity->h)
        {
            i = entity->h;
        }
    }
//et on recommence la même chose avec le mouvement vertical 
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
            //déplacement EN BAS 
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
               //deplacement vers LE haut

                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE)
                {

                    entity->y = (y1 + 1) * TILE_SIZE;

                    entity->dirY = 0;

                }

            }
        }
// on teste la largeur du sprite 
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
//Maintenant, on applique les vecteur de mouvement si le sprite n'est pas bloqué 
    
    entity->x += entity->dirX;
    entity->y += entity->dirY;

   //on contraint son déplacement aux limites de l'ecran  ! 
    if (entity->x < 0)
    {
        entity->x = 0;
    }

    else if (entity->x + entity->w >= map.maxX)
    {
        entity->x = map.maxX - entity->w - 1;
    }

  
}
void updatePlayer(void)
{

 
   //Si le timer vaut 0, c'est que tout va bien, sinon, on le décrémente jusqu'à 0, et là,
   //on réinitialise.
   //C'est pour ça qu'on ne gère le joueur que si ce timer vaut 0.
  if (player.timerMort == 0)
  {

    //On réinitialise notre vecteur de déplacement latéral (X)

   
	player.dirX = 0;

    // La gravité fait toujours tomber le perso : on incrémente donc le vecteur Y
	player.dirY += GRAVITY_SPEED;

  

    //Voilà, au lieu de changer directement les coordonnées du joueur, on passe par un vecteur
    //qui sera utilisé par la fonction mapCollision(), qui regardera si on peut ou pas déplacer
    //le joueur selon ce vecteur et changera les coordonnées du player en fonction.
 	if (input.left == 1)
	{
		player.dirX -= PLAYER_SPEED;

        //On teste le sens pour l'animation : si le joueur allait dans le sens contraire
        //précédemment, il faut recharger le spritesheet pour l'animation.
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

 

    //On rajoute notre fonction de détection des collisions qui va mettre à jour les coordonnées
  
    mapCollision(&player);
    centerScrollingOnPlayer();

  }

    //Gestion de l'echec  quand le héros fait un erreur :
    //Si timerMort est différent de 0, c'est qu'il faut réinitialiser le joueur.
    //On ignore alors ce qui précède et on joue cette boucle (un wait en fait) jusqu'à ce que
    // timerMort == 1. A ce moment-là, on le décrémente encore -> il vaut 0 et on réinitialise
    if (player.timerMort > 0)
	{
		player.timerMort--;

		if (player.timerMort == 0)
		{
			//si le joueur fait un erreur 
			initializePlayer();
		}
	}

}
 
 

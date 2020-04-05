  void mapCollision(Hero *entity)
 {

    int i, x1, x2, y1, y2;

    /* D'abord, on place le joueur en l'air jusqu'à temps d'être sûr qu'il touche le sol */

    entity->onGround = 0;

    /* Ensuite, on va tester les mouvements horizontaux en premier (axe des X) */
    //On va se servir de i comme compteur pour notre boucle. En fait, on va découper notre sprite
    //en blocs de tiles pour voir quelles tiles il est susceptible de recouvrir.
    //On va donc commencer en donnant la valeur de Tile_Size à i pour qu'il teste la tile où se trouve
    //le x du joueur mais aussi la suivante SAUF dans le cas où notre sprite serait inférieur à
    //la taille d'une tile. Dans ce cas, on lui donnera la vraie valeur de la taille du sprite
    //Et on testera ensuite 2 fois la même tile. Mais comme ça notre code sera opérationnel quelle que
    //soit la taille de nos sprites !
   
    if(entity->h > TILE_SIZE)
        i = TILE_SIZE;
    else
        i = entity->h;

    //On lance alors une boucle for infinie car on l'interrompra selon les résultats de nos calculs

    for (;;)
    {
        //On va calculer ici les coins de notre sprite à gauche et à droite pour voir quelle tile ils
        //touchent.

        x1 = (entity->x + entity->dirX) / TILE_SIZE;
        x2 = (entity->x + entity->dirX + entity->w - 1) / TILE_SIZE;

        //Même chose avec y, sauf qu'on va monter au fur et à mesure pour tester toute la hauteur
        //de notre sprite, grâce à notre fameuse variable i.

        y1 = (entity->y) / TILE_SIZE;
        y2 = (entity->y + i - 1) / TILE_SIZE;

        //De là, on va tester les mouvements initiés dans updatePlayer grâce aux vecteurs
        //dirX et dirY, tout en testant avant qu'on se situe bien dans les limites de l'écran.

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            //Si on a un mouvement à droite

            if (entity->dirX > 0)
            {

                //On vérifie si les tiles recouvertes sont solides

                if (map.tile[y1][x2] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
                {
                    // Si c'est le cas, on place le joueur aussi près que possible
                    // de ces tiles, en mettant à jour ses coordonnées. Enfin, on réinitialise
                    //son vecteur déplacement (dirX).

                    entity->x = x2 * TILE_SIZE;

                    entity->x -= entity->w + 1;

                    entity->dirX = 0;

                }

            }

            //Même chose à gauche

            else if (entity->dirX < 0)
            {

                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y2][x1] > BLANK_TILE)
                {

                    entity->x = (x1 + 1) * TILE_SIZE;

                    entity->dirX = 0;
                }


            }

        }

        //On sort de la boucle si on a testé toutes les tiles le long de la hauteur du sprite.
        if (i == entity->h)
        {
            break;
        }

        //Sinon, on teste les tiles supérieures en se limitant à la heuteur du sprite.
        i += TILE_SIZE;

        if (i > entity->h)
        {
            i = entity->h;
        }
    }

    //On recommence la même chose avec le mouvement vertical (axe des Y)
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

                /* Déplacement en bas */
                if (map.tile[y2][x1] > BLANK_TILE || map.tile[y2][x2] > BLANK_TILE)
                {
                    //Si la tile est solide, on y colle le joueur et
                    //on le déclare sur le sol (onGround).
                    entity->y = y2 * TILE_SIZE;
                    entity->y -= entity->h;

                    entity->dirY = 0;

                    entity->onGround = 1;
                }

            }

            else if (entity->dirY < 0)
            {

                /* Déplacement vers le haut */

                if (map.tile[y1][x1] > BLANK_TILE || map.tile[y1][x2] > BLANK_TILE)
                {

                    entity->y = (y1 + 1) * TILE_SIZE;

                    entity->dirY = 0;

                }

            }
        }

        //On teste la largeur du sprite (même technique que pour la hauteur précédemment)
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

    /* Maintenant, on applique les vecteurs de mouvement si le sprite n'est pas bloqué */
    entity->x += entity->dirX;
    entity->y += entity->dirY;

    //Et on contraint son déplacement aux limites de l'écran, comme avant.
    if (entity->x < 0)
    {
        entity->x = 0;
    }

    else if (entity->x + entity->w >= map.maxX)
    {
        entity->x = map.maxX - entity->w - 1;
    }

    //Maintenant, s'il sort de l'écran par le bas (chute dans un trou sans fond), on lance le timer
    //qui gère sa mort et sa réinitialisation (plus tard on gèrera aussi les vies).
    if (entity->y > map.maxY)
    {
        entity->timerMort = 60;
    }
}
  void updatePlayer(void)
 {

   //On rajoute un timer au cas où notre héros mourrait lamentablement en tombant dans un trou...
   //Si le timer vaut 0, c'est que tout va bien, sinon, on le décrémente jusqu'à 0, et là,
   //on réinitialise.
   //C'est pour ça qu'on ne gère le joueur que si ce timer vaut 0.
  if (player.timerMort == 0)
  {

    //On réinitialise notre vecteur de déplacement latéral (X), pour éviter que le perso
    //ne fonce de plus en plus vite pour atteindre la vitesse de la lumière ! ;)
    //Essayez de le désactiver pour voir !
    player.dirX = 0;

    // La gravité fait toujours tomber le perso : on incrémente donc le vecteur Y
    player.dirY += GRAVITY_SPEED;

    //Mais on le limite pour ne pas que le joueur se mette à tomber trop vite quand même
    if (player.dirY >= MAX_FALL_SPEED)
    {
        player.dirY = MAX_FALL_SPEED;
    }

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

    //Et voici la fonction de saut très simple :
    //Si on appuie sur la touche saut (C par défaut) et qu'on est sur le sol, alors on attribue une valeur
    //négative au vecteur Y
    //parce que sauter veut dire se rapprocher du haut de l'écran et donc de y=0.
    if (input.jump == 1 && player.onGround)
    {
        player.dirY = -JUMP_HEIGHT;
        player.onGround = 0;

    }

    //On rajoute notre fonction de détection des collisions qui va mettre à jour les coordonnées
    //de notre super lapin, puis on centre le scrolling comme avant.
    mapCollision(&player);
    centerScrollingOnPlayer();

  }

    //Gestion de la mort quand le héros tombe dans un trou :
    //Si timerMort est différent de 0, c'est qu'il faut réinitialiser le joueur.
    //On ignore alors ce qui précède et on joue cette boucle (un wait en fait) jusqu'à ce que
    // timerMort == 1. A ce moment-là, on le décrémente encore -> il vaut 0 et on réinitialise
    //le jeu avec notre bonne vieille fonction d'initialisation ;) !
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

 

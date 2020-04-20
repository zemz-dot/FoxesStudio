#include "structs.h"

  extern GameObject monster[];
  extern Gestion jeu;
  extern GameObject player;

  /* Prototypes des fonctions utilisées */
  extern SDL_Surface *loadImage(char *name);
  extern void mapCollision(GameObject *entity);
  extern int collide(GameObject *player, GameObject *monster);

#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

 /* Structure pour gérer notre personnage */

   typedef struct Personnage
   {
       //Sprite du personnage (
       SDL_Surface *sprite;

       /* Coordonnées du Personnage */
       int x, y;

   } Personnage;


#endif // STRUCTS_H_INCLUDED

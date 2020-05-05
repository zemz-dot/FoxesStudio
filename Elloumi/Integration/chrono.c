#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "game.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>


SDL_Surface * afficher_chrono(SDL_Surface *ecran , SDL_Surface *Background , SDL_Rect p , int running  )
{

 SDL_Surface  *texte = NULL ; 
    SDL_Rect position,positionecran;
    SDL_Event event;
int n ; 
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0,fps=0,fpm=0,fph=0;
    char temps[30] = ""; /* Tableau de char suffisamment grand */
   // float delta;
    float dt;




    /* Chargement de la police */
    police = TTF_OpenFont("arial.ttf", 25);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    //texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);
    //texte = TTF_RenderText_Solid(police, temps, couleurNoire);
    texte = TTF_RenderText_Blended(police, temps, couleurNoire);

    while (n )
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                n = 0;
                break;
        }



        tempsActuel = SDL_GetTicks();
          dt=tempsActuel - tempsPrecedent;
         
      if ( dt >= 1000) /* Si 1000 ms au moins se sont écoulées */
        {
          compteur += 1000; /* On rajoute 1000 ms au compteur */

          fps=compteur/1000;
           
               
             if (fps>59)
                 { fpm=(fps/60);
                  // fps=fps-(60*fpm);
                   
                   if(fpm>59)
                      fph=(fpm/60);
                  
                  
                 }
             
           
           

              
            sprintf(temps,"Temps: %d :%d :%d",fph,fpm,fps-(60*fpm)/*compteur*/); /* On écrit dans la chaîne "temps" le nouveau temps */
          // SDL_FreeSurface(texte); /* On supprime la surface précédente */


           //texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
              // texte = TTF_RenderText_Solid(police, temps, couleurNoire);
             texte = TTF_RenderText_Blended(police, temps, couleurNoire);


            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }



    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    //SDL_Quit();

return texte ; 
}

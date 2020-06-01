#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "collison.h"




SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0 ;

    //determine position
    char* pPosition = ( char* ) pSurface->pixels ;

    //offset by y
    pPosition += ( pSurface->pitch * y ) ;

    //offset by x
    pPosition += ( pSurface->format->BytesPerPixel * x ) ;

    //copy pixel data
    memcpy ( &col, pPosition, pSurface->format->BytesPerPixel ) ;

    //convert color
    SDL_GetRGB ( col, pSurface->format, &color.r, &color.g, &color.b ) ;
    return ( color ) ;
}

int collision(SDL_Surface * BackGround_Menu, SDL_Rect *position_perso, SDL_Surface *perso)
{
int coll=0;

    SDL_Color col1 = GetPixel( BackGround_Menu, position_perso->x + perso->w-30, position_perso->y );
    if(col1.r ==0 && col1.g == 0 && col1.b == 0)
    {
        coll=1;
    }
    
return coll;
}

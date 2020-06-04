#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Obj.h"
#include "ObjPP.h"
#include "Collision.h"

int main()
{
SDL_Surface *screen ,*back1,*back2,*back3 ; 
Objet Obj, Obj1 ; 
SDL_Event event ; 
int done=0 , x,xx=0 ,tc=0 ; 
perso.x=360;
perso.y=200;

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
screen= SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_HWSURFACE  |  SDL_DOUBLEBUF);
if(screen == NULL ) {
printf("Can not set video mode : \n ); 
}

	back1=IMG_Load( "mapmini1.png" );
	back2=IMG_Load( "mapmini2.png" );
	back3=IMG_Load( "C.png" );
	SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

	SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
	SDL_BlitSurface ( back3,  NULL ,  screen , &Obj );

	SDL_Flip ( screen ); 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255)); 

    initialiserObj( &Obj ,"C.png" ,  0 ,  0 ) ; 
    affichageObj (Obj ,screen) ;
    initialiserObj( &Obj1 ,"F.png" ,  500 ,  200 ) ; 
    affichageObj (Obj1 ,screen) ;
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

Obj.position.x-=10 ; 
xx=detectCollPP(back2,perso);
if(xx==1)
{
Obj.position.x+=10;
printf("Hello");
}
SDL_BlitSurface(back2,NULL,screen,NULL);
SDL_BlitSurface(back1,NULL,screen,NULL);
SDL_BlitSurface(back3,NULL,screen,&Obj);

SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
SDL_Flip(screen);

break ; 

case SDLK_RIGHT : 

Obj.position.x+=10 ; 
xx=detectCollPP (back2,perso) ;
if(xx==1)
{
perso.x-=10 ; 
}
SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );


SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
SDL_Flip ( screen ); 
break ; 
case SDLK_UP : 

Obj.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_DOWN : 

Obj.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 


                 
			 }
x=collisionbb(Obj.position,Obj1.position) ;
tc=CollisionTrigoCir(Obj.position,Obj1.position);
if(x==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }
     else   if(tc==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }
return 0 ; 
}

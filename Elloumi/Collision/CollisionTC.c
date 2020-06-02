#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>
#include "game.h"
 #include <math.h>
 
 int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj )
 {
	 int r1,r2,x ; //Rayons du cercle 
	 
	       r1=(sqrt(pow(posj.h,2)+pow(posj.w,2)))/2     ;
      r2=(sqrt(pow(posobj.h,2)+pow(posobj.w,2)))/2 ;
	 
 if   ( (posobj.x+(posobj.w/2))-(posj.x+(posj.w/2)) <= r1 + r2 && (posj.x <= posobj.x+(posobj.w/2)+r2 ) && (posj.y+posj.h > ((posobj.y+(posobj.h/2)) - r2 ) ) )
     {
		x=1 ; ; //Collision faite
	 }
   else x=0 ; 
return x ; 
	 
	 
}

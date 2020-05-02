#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "game.h"
 #include <stdbool.h>


void setrects(SDL_Rect* clip , int LI , int HI , int frames ) 
{
int i ; 

clip[0].x=0 ;
clip[0].y=0;
clip[0].w=LI;
clip[0].h=HI; 
for (i=1;i<frames;i++) 
{
clip[i].x=clip[i-1].x+LI;
clip[i].y=0;
clip[i].w=LI;
clip[i].h=HI;
}
}


void animate(SDL_Surface *screen , SDL_Surface *sprite ,SDL_Surface *sprite2,SDL_Surface *sprite3,  SDL_Surface *Background , SDL_Rect positionFond , int running)
{
SDL_Surface *Level=NULL , *t=NULL  , *screen1 ; 
int frame=0 , frame1=0; 
SDL_Rect rect , rects[4] ,rect2[6],rect3[8],rect4[7],  dst , rect1 ,pos , perso , p  ; 
int n , positionini=0 , c ;
int run , r , alea=0 , s , sol , up=0 , right=0 , left=0 ;
char image [30] ;   
object obj , obj1 , obj2 , obj3 ; 
ent E[6] ;  
enigme  e;

    srand(time(NULL));

init_enigme(&e) ; 
initialiser_entite(E,6);

initialiserObj(&obj,"F.png",350,571) ; 
initialiserObj(&obj1,"F.png",450,571) ;
initialiserObj(&obj2,"F.png",1800,571) ; 
initialiserObj(&obj3,"F.png",1600,571) ; 


p.x=200 ; 
p.y=0 ;
p.h=720 ; 


dst.x=0 ; 
dst.y=535 ;
dst.h=117 ; 
dst.w=78 ; 

rect.x=0;
rect.y=535;
rect.h=117 ; 
rect.w=78 ; 

pos.x=300;
pos.y=500;
pos.h=220 ; 
pos.w=100 ; 



sprite = IMG_Load("sprite.png") ;

sprite2 = IMG_Load("sprite2.png") ; 
sprite3 = IMG_Load("sprite3.png") ; 
setrects(rects,78,117,5); 
setrects(rect2,153,139,6);
setrects(rect3,96,111,E[2].maxframe);
setrects(rect4,102,148,E[3].maxframe);


SDL_EnableKeyRepeat(1,1) ; 
while(!running)
{
	    run=1,r=0 ;
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        running = 1;

                                        break;


     case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
running=0 ;  
break ; 
case SDLK_RIGHT :
left=0 ; 
right=1 ; 
rect.x+=10 ; 
 
 if (( rect.x>=640 )||(rect.x>=1280))
{
 positionFond.x+=640;
rect.x=0 ; 

}

if ( positionFond.x>=640 )
{
dst.x=rect.x+positionFond.x ;  
}
else 
{dst.x=rect.x ;}


break ;
case SDLK_LEFT : 
right=0 ; 
left=1 ;  
rect.x-=10 ; 
 if ( rect.x==0 )
{
 positionFond.x-=640;
rect.x=640-rect.x ; 

}


if ( positionFond.x>=640 )
{
dst.x=rect.x+positionFond.x ;  
}
else 
{dst.x=rect.x ;}
    
break ;

case SDLK_UP : 
if(right==1)   
{
if (rect.x>=640)
{
 positionFond.x+=640;
rect.x=0 ; 

}
while((rect.y>400)&&(up==0))
{
rect.x+=40 ; 
 rect.y-=30 ;  
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4){
frame=0;
}
}
if(rect.y<=400)
{
up=1 ;
rect.x+=40 ;  
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4) 
{
frame=0;
}
}
while ((rect.y<535)&&(up==1)) 
{
rect.y+=30 ; 
rect.x+=40 ; 
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4) 
{
frame=0;
}

} 
if(rect.y==535) 
{
up=0 ; 
}
if ( positionFond.x>=640 )
{
dst.x=rect.x+positionFond.x ;  
}
else 
{dst.x=rect.x ;}

}
  

  
else if(left==1)   
{
if ( rect.x==0 )
{
 positionFond.x-=640;
rect.x=640-rect.x ; 

}
while((rect.y>400)&&(up==0))
{
rect.x-=40 ; 
 rect.y-=30 ;  
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4){
frame=0;
}
}
if(rect.y<=400)
{
up=1 ;
rect.x-=40 ;  
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4) 
{
frame=0;
}
}
while ((rect.y<535)&&(up==1)) 
{
rect.y+=30 ; 
rect.x-=40 ; 
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4) 
{
frame=0;
}

} 
if(rect.y==535) 
{
up=0 ; 
}
if ( positionFond.x>=640 )
{
dst.x=rect.x+positionFond.x ;  
}
else 
{dst.x=rect.x ;}

}
break ;


}








						}


affichageObj(obj2,Background) ; 
c=collisionbb(dst,obj2.position) ;
if (c)
{
     
generate_afficher ( screen , image ,&e,&alea) ;
s=solution_e (image);
			
do
{
			
r=resolution (&running,&run);


			}

while((r>3 || r<1)&&run!=0) ;
	
	sol=afficher_resultat (screen,s,r,&e) ;		

if (sol)
{

run=0 ; 
rect.x+=250 ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4){
frame=0;
}

}

else 
{

SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ; 

affichageObj(obj,Background) ; 
SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;
 SDL_Delay(150) ;
frame++;
if(frame==4){
frame=0;
}
}





					}









}

if((dst.x>800)&&(dst.x<1280)) 
{
animation_entite_droite(&E[0],rect2,screen,Background, positionFond);
enemy_va_x(&E[0]) ;
}


if(right==1)
{
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ;  

affichageObj(obj,Background) ; 


SDL_BlitSurface(sprite2,&rects[frame],screen,&rect);
SDL_Flip(screen) ;

SDL_Delay(150) ; 
frame++;
if(frame==4){
frame=0;
}
}
else if (left==1) 
{
SDL_BlitSurface(Background,&positionFond,screen,NULL);
SDL_Flip(screen) ;  

affichageObj(obj,Background) ; 


SDL_BlitSurface(sprite,&rects[frame],screen,&rect);
SDL_Flip(screen) ;

SDL_Delay(150) ; 
frame++;
if(frame==4){
frame=0;
}
}





}


}





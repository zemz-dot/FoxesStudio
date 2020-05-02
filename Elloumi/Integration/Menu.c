#include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <SDL/SDL_mixer.h>
#include "game.h"  
  int  main () 
  {
	  
 SDL_Surface  * screen , *Background , *Pressed1 , *Pressed2 , *Pressed3 , *Pressed4 , *Pressed5 , *scroll , *Quuit , *Cadrspae1 , *Cadre1 , *Cadre2 , *Level=NULL , *sprite=NULL , *sprite2=NULL , *sprite3=NULL , *t=NULL ;
 SDL_Surface *sound0 , *sound1 , *sound2 , *sound3 , *sound4 , *sound5 , *sound6 , *sound7 , *sound8 , *sound9 ; 
 SDL_Surface *credit1 , *credit2 , *credit3 , *credit4 ,*credit5 , *credit6 , *credit7 ,*credit8 , *credit9 ; 
 SDL_Rect dst , dst1 , dst3 , rect; 
 SDL_Event event ; 
 Mix_Chunk *scrolling , *pressing ;
Mix_Music *song ; 

      int  done  =  0 , running=1 ; 
      int i=1 ; 
      int k=0 , c =0 , j=0 , menu=1 , continuer=0 ; 
      int x , y , Quit=0 ; 
      
       if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0 ,  0 ,  255 )); 
     Background  =  IMG_Load( "Background.jpg" ); 
     if  ( Background  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  = 1280 ; 
     dst3.h  =  720 ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen );  
     Quuit  =  IMG_Load( "Quit.png" );
     Cadre1  =  IMG_Load( "cadre1.png" );
     Cadre2  =  IMG_Load( "cadre2.png" );
     Pressed1  =  IMG_Load( "ng.png" ); 
     Pressed2  =  IMG_Load( "cnt.png" ); 
     Pressed3  =  IMG_Load( "opt.png" ); 
     Pressed4  =  IMG_Load( "credits.png" ); 
     Pressed5  =  IMG_Load( "exit.png" ); 
     scroll  =  IMG_Load( "scroll.png" ); 
     sound0  =  IMG_Load( "0.jpg" ); 
     sound1  =  IMG_Load( "1.jpg" ); 
     sound2  =  IMG_Load( "2.jpg" ); 
     sound3  =  IMG_Load( "3.jpg" ); 
     sound4  =  IMG_Load( "4.jpg" ); 
     sound5  =  IMG_Load( "5.jpg" );     
     sound6  =  IMG_Load( "6.jpg" ); 
     sound7  =  IMG_Load( "7.jpg" ); 
     sound8  =  IMG_Load( "8.jpg" ); 
     sound9  =  IMG_Load( "9.jpg" ); 
     credit1  =  IMG_Load( "Credits/1.jpg" ); 
     credit2  =  IMG_Load( "Credits/2.jpg" ); 
     credit3  =  IMG_Load( "Credits/3.jpg" ); 
     credit4  =  IMG_Load( "Credits/4.jpg" ); 
     credit5  =  IMG_Load( "Credits/5.jpg" ); 
     credit6  =  IMG_Load( "Credits/6.jpg" ); 
     credit7  =  IMG_Load( "Credits/7.jpg" ); 
     credit8  =  IMG_Load( "Credits/8.jpg" ); 
     credit9  =  IMG_Load( "Credits/9.jpg" ); 
    Level  =  IMG_Load( "map.png" ); 
                  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
     { 
		 printf("Error \n ") ; 
		 }
     pressing = Mix_LoadWAV("S.wav") ;
     scrolling = Mix_LoadWAV("C.wav") ;
     song  = Mix_LoadMUS("G.MP3") ;
     Mix_PlayMusic(song,-1) ; 
      SDL_EnableKeyRepeat(100,100) ; 

      while  ( ! done )  { 
         while  (SDL_PollEvent ( & event ))  { 
             switch  ( event . type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
                 
             case SDL_KEYDOWN : 
                     switch( event.key.keysym.sym )
                        {
					             case  SDLK_ESCAPE : 

     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ;
        if (c==1)
     {
		 j-- ;
	 }
     i=1 ; 
     c=0 ; 
     menu=1 ; 
 
SDL_EnableKeyRepeat(100,100) ; 

     break ; 
     
     
         case SDLK_DOWN :
if (menu==1) 
{
 if (i==1) 
     { 

     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  277 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
     i++ ; 
 }
 else if (i==2) 
 {
	      dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  322 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i++ ; 
}
 else if (i==3) 
 {
	     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  373 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i++ ; 
}
 else if (i==4) 
 {
	         dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  417 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i++ ; 
}
else if (i==5) 
 {
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  460 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i=1 ; 
}
}

 while ( c==1)
 { 
	 switch (j) 
	 {
		 case 1 :
		 

     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound0 -> w ; 
     dst3 .h  =  sound0 -> h ; 
     SDL_BlitSurface ( sound0 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     
		 break ; 
		 case 2 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound9 -> w ; 
     dst3 .h  =  sound9 -> h ; 
     SDL_BlitSurface ( sound9 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=1;
		 break ;  
		 case 3 :
     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound8 -> w ; 
     dst3 .h  =  sound8 -> h ; 
     SDL_BlitSurface ( sound8 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=2 ; 
		 break ;  
		 case 4 :
     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound7 -> w ; 
     dst3 .h  =  sound7 -> h ; 
     SDL_BlitSurface ( sound7 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=3;
		 break ;  
		 case 5 : 
     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound6 -> w ; 
     dst3 .h  =  sound6 -> h ; 
     SDL_BlitSurface ( sound6 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=4 ; 
		 break ; 
		 
		 
		 
		 
	 }





     break ; 
     
       case SDLK_UP : 
    if (menu==1)
    {  if (i==3) 
     { 
		      dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  277 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
     i-- ;  
 }
 else if (i==4) 
 {
	         dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  322 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i-- ; 
}
 else if (i==5) 
 {
	          dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  373 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i-- ; 
}
  else if (i==1) 
 {
	         dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  417 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
     i=5;    
} 
else if (i==2) 
 {
	         dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  460 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	 i-- ;              
}
}
 if ( c==1)
 {
	 switch (j) 
	 {
		 case 1 :
		 
     dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound1 -> w ; 
     dst3 .h  =  sound1 -> h ; 
     SDL_BlitSurface ( sound1 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=2 ; 
		 break ; 
		 case 2 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound2 -> w ; 
     dst3 .h  =  sound2 -> h ; 
     SDL_BlitSurface ( sound2 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=3 ;
		 break ;  
		 case 3 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound3 -> w ; 
     dst3 .h  =  sound3 -> h ; 
     SDL_BlitSurface ( sound3 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=4;
		 break ;  
		 case 4 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound4-> w ; 
     dst3 .h  =  sound4 -> h ; 
     SDL_BlitSurface ( sound4 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     j=5;
		 break ;  
		 case 5 : 
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound5 -> w ; 
     dst3 .h  =  sound5 -> h ; 
     SDL_BlitSurface ( sound5 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     
		 break ; 
		 default : j++ ; 
		 break ; 
		 
		 
		 
		 
	 }
 } 
break ; 


  case SDLK_SPACE : 
   
   if (i==2)
     { 

     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  168 ; 
     dst1 . y  =  277 ; 
     dst1 . w  =  Pressed1 -> w ; 
     dst1.h  =  Pressed1 -> h ; 
     SDL_BlitSurface ( Pressed1 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 

     SDL_Delay(1000) ; 
continuer=1 ;
animate(screen ,sprite ,sprite2,sprite3,  Level , dst3 ,  done) ; 
 


 }
 else if (i==3) 
 {
	    dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  170 ; 
     dst1 . y  =  322 ; 
     dst1 . w  =  Pressed2 -> w ; 
     dst1.h  =  Pressed2 -> h ; 
     SDL_BlitSurface ( Pressed2 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
}
 else if (i==4) 
 {

	    dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  178 ; 
     dst1 . y  =  372 ; 
     dst1 . w  =  Pressed3 -> w ; 
     dst1.h  =  Pressed3 -> h ; 
     SDL_BlitSurface ( Pressed3 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 

      switch(j) 
      
    {
		
		 case 1 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound1 -> w ; 
     dst3 .h  =  sound1 -> h ; 
     SDL_BlitSurface ( sound1 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );
		 break ; 
		 case 2 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound2 -> w ; 
     dst3 .h  =  sound2 -> h ; 
     SDL_BlitSurface ( sound2 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
   
		 break ;  
		 case 3 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound3 -> w ; 
     dst3 .h  =  sound3 -> h ; 
     SDL_BlitSurface ( sound3 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
		 break ;  
		 case 4 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound4 -> w ; 
     dst3 .h  =  sound4 -> h ; 
     SDL_BlitSurface ( sound4 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
		 break ;  
		 case 5 : 
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound5 -> w ; 
     dst3 .h  =  sound5 -> h ; 
     SDL_BlitSurface ( sound5 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     
 }
     c=1 ;  
     menu=0 ; 
     	break ;


     
}
 else if (i==5) 
 {
 dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  179 ; 
     dst1 . y  =  417 ; 
     dst1 . w  =  Pressed4 -> w ; 
     dst1.h  =  Pressed4 -> h ; 
     SDL_BlitSurface ( Pressed4 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
     SDL_Delay(300) ; 
     
     Mix_PlayMusic(song,1) ; 

       SDL_BlitSurface ( credit1 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
            SDL_BlitSurface ( credit2 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit3 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit4 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit5 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit6 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen );
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit7 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit8 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit9 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(1000) ;    
  
  
}
else if (i==1) 
 {
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  204 ; 
     dst1 . y  =  459 ; 
     dst1 . w  =  Pressed5 -> w ; 
     dst1.h  =  Pressed5 -> h ; 
     SDL_BlitSurface ( Pressed5 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
     SDL_Delay(1500) ; 
     done=1 ; 
}
else if (i==0) 
 {
 dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
     i=1; 
  
}
break ; 

}
}

     case SDL_MOUSEMOTION : 
        

  
      if ((event.motion.x > 168 && event.motion.x < 288 && event.motion.y > 275 && event.motion.y < 295)&&(menu==1))
      {
		      
	  dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  277 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
		  
	  
	}
	    if ((event.motion.x > 171 && event.motion.x < 282 && event.motion.y > 321 && event.motion.y < 341)&&(menu==1))
	    { 
   dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  322 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
			
			}
			
		    if ((event.motion.x > 179 && event.motion.x < 273 && event.motion.y > 371 && event.motion.y < 389)&&(menu==1))
{ 	     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  373 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
	}	
			    if ((event.motion.x > 180 && event.motion.x < 271 && event.motion.y > 417 && event.motion.y < 436 )&&(menu==1))
	
	{
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  417 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ; 
		}
		
		if ((event.motion.x > 204  && event.motion.x < 252 && event.motion.y > 458 && event.motion.y < 477 )&&(menu==1))
		{			    
	     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst1 . x  =  147 ; 
     dst1 . y  =  460 ; 
     dst1 . w  =  scroll -> w ; 
     dst1.h  =  scroll -> h ; 
     SDL_BlitSurface ( scroll ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,scrolling,0) ;
 }
 
   if ((event.motion.x > 557  && event.motion.x < 600 && event.motion.y > 425 && event.motion.y < 452)&&(Quit==1)) 
    {
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Quuit -> w ; 
     dst.h  =  Quuit -> h ; 
     SDL_BlitSurface ( Quuit ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst . x  =  0 ; 
     dst . y  =  -10 ; 
     dst . w  =  Cadre1 -> w ; 
     dst.h  =  Cadre1 -> h ; 
     SDL_BlitSurface ( Cadre1 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     }
    else if ((event.motion.x > 782  && event.motion.x < 867 && event.motion.y > 425 && event.motion.y < 446 )&&(Quit==1))
{
    dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Quuit -> w ; 
     dst.h  =  Quuit -> h ; 
     SDL_BlitSurface ( Quuit ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     dst . x  =  0 ; 
     dst . y  =  -10 ; 
     dst . w  =  Cadre2 -> w ; 
     dst.h  =  Cadre2 -> h ; 
     SDL_BlitSurface ( Cadre2 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
							 
							 }
						 
	 break ; 

	case SDL_MOUSEBUTTONUP :
		
		if(event.button.button == SDL_BUTTON_RIGHT) 
		{
			x=event.button.x ; 
			y=event.button.y ; 
		}
	    if (event.button.x > 168 && event.button.x < 288 && event.button.y > 275 && event.button.y < 295)
	    {
			   dst . x  =  0 ; 
        dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  168 ; 
     dst1 . y  =  277 ; 
     dst1 . w  =  Pressed1 -> w ; 
     dst1.h  =  Pressed1 -> h ; 
     SDL_BlitSurface ( Pressed1 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 

     SDL_Delay(1000) ; 
continuer=1 ;
animate(screen ,sprite ,sprite2,sprite3,  Level , dst3 ,  done) ; 
			
			}
	    if (event.button.x > 171 && event.button.x < 282 && event.button.y > 321 && event.button.y < 341)
	    {
				    dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  170 ; 
     dst1 . y  =  322 ; 
     dst1 . w  =  Pressed2 -> w ; 
     dst1.h  =  Pressed2 -> h ; 
     SDL_BlitSurface ( Pressed2 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
			}
	    if (event.button.x > 179 && event.button.x < 273 && event.button.y > 371 && event.button.y < 389)
	    {
				    dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  178 ; 
     dst1 . y  =  372 ; 
     dst1 . w  =  Pressed3 -> w ; 
     dst1.h  =  Pressed3 -> h ; 
     SDL_BlitSurface ( Pressed3 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 

      switch(j) 
      
    {
		
		 case 1 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound1 -> w ; 
     dst3 .h  =  sound1 -> h ; 
     SDL_BlitSurface ( sound1 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );
		 break ; 
		 case 2 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound2 -> w ; 
     dst3 .h  =  sound2 -> h ; 
     SDL_BlitSurface ( sound2 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
   
		 break ;  
		 case 3 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound3 -> w ; 
     dst3 .h  =  sound3 -> h ; 
     SDL_BlitSurface ( sound3 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
		 break ;  
		 case 4 :
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound4 -> w ; 
     dst3 .h  =  sound4 -> h ; 
     SDL_BlitSurface ( sound4 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
		 break ;  
		 case 5 : 
	 dst3 . x  =  0 ; 
     dst3 . y  =  0 ; 
     dst3 . w  =  sound5 -> w ; 
     dst3 .h  =  sound5 -> h ; 
     SDL_BlitSurface ( sound5 ,  NULL ,  screen ,  & dst3 ); 
     SDL_Flip ( screen );  
     
 }
     c=1 ;  
     menu=0 ; 
     	break ;
			}
	    if (event.button.x > 180 && event.button.x < 271 && event.button.y > 417 && event.button.y < 436)
	    {
			 dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  179 ; 
     dst1 . y  =  417 ; 
     dst1 . w  =  Pressed4 -> w ; 
     dst1.h  =  Pressed4 -> h ; 
     SDL_BlitSurface ( Pressed4 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
     SDL_Delay(300) ; 
     
     Mix_PlayMusic(song,1) ; 

       SDL_BlitSurface ( credit1 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
            SDL_BlitSurface ( credit2 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit3 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit4 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit5 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit6 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen );
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit7 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit8 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(2500) ;    
  
         SDL_BlitSurface ( credit9 ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     SDL_Delay(1000) ; 
			}
	    if (event.button.x > 204  && event.button.x < 252 && event.button.y > 458 && event.button.y < 477)
	    {
		     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 

     dst1 . x  =  204 ; 
     dst1 . y  =  459 ; 
     dst1 . w  =  Pressed5 -> w ; 
     dst1.h  =  Pressed5 -> h ; 
     SDL_BlitSurface ( Pressed5 ,  NULL ,  screen ,  & dst1 ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ; 
     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Quuit -> w ; 
     dst.h  =  Quuit -> h ; 
     SDL_BlitSurface ( Quuit ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
     Mix_PlayChannel(1,pressing,0) ;
     Quit=1 ; 
     menu=0 ; 	
			}
   while(Quit==1) 
   {
   if (event.button.x > 557  && event.button.x < 600 && event.button.y > 425 && event.button.y < 452)
    {
      done=1 ; 
     }
    else if (event.button.x > 782  && event.button.x < 867 && event.button.y > 425 && event.button.y < 446 )
{
		     dst . x  =  0 ; 
     dst . y  =  0 ; 
     dst . w  =  Background -> w ; 
     dst.h  =  Background -> h ; 
     SDL_BlitSurface ( Background ,  NULL ,  screen ,  & dst ); 
     SDL_Flip ( screen ); 
Quit=0 ; 
menu=1 ; 
}
			break ; 


}
}
}
}

return 0 ; 
}

 

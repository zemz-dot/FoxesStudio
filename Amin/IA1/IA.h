#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED


typedef struct
{
  int x ;
  int y ;
  float rayon ;

}Circle;

typedef struct
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  Circle c ;
  SDL_Rect pos_text ;

}Objet ;


void intialiser(Objet *perso ,Objet *zombie) ;
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
float calculer_distance (Objet *objet1,Objet *objet2) ;
int verif_collision ( Objet *objet1,Objet *objet2,float D1 ) ;
void deplacement_objet(Objet *objet,int *running) ;


#endif // IA_H_INCLUDED

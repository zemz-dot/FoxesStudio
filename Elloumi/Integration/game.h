#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


#define W_Screen 800
#define H_Screen 600


#define SPEED 5


#define SPRITE_H 96
#define SPRITE_W  111
#define MAX_FRAMES 8



           #define W_BackgImg 259
           #define H_BackgImg 194w

typedef struct 
{

SDL_Rect position_entite;
SDL_Rect position_map;
SDL_Rect frame;
SDL_Rect dst;


SDL_Surface * image_entite;
SDL_Surface * spriteleft;
SDL_Surface * spriteright;

int pos_alea_max_x;
int pos_alea_min_x;

int pos_alea_max_y;
int pos_alea_min_y;

int pos_max_x;
int pos_min_x;

int pos_max_y;
int pos_min_y;
int curframe;
int maxframe;


}ent;

typedef struct 
{

SDL_Surface *image ; 
SDL_Rect position ; 

} object ; 

void initialiserObj(  object *obj , char name[] , int x , int y ) ; 
void affichageObj (  object obj , SDL_Surface *screen) ; 


typedef struct 
{
        SDL_Surface * temps;
	SDL_Rect position_temps;

	int heure;
	
	int minute;
	
	int seconde;
	
	 
	TTF_Font *police;

	int tempsactuel;
	int tempsprecedent;
	

	
}temps;


typedef struct 
{
 SDL_Surface * img;
 SDL_Rect 	p;
}enigme;


void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
 int solution_e (char image []) ;
int resolution (int * running,int *run);
int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;



void setrects(SDL_Rect* clip , int LI , int HI , int frames ) ; 

void animate(SDL_Surface *screen , SDL_Surface *sprite ,SDL_Surface *sprite2,SDL_Surface *sprite3,SDL_Surface *Background , SDL_Rect positionFond ,  int running) ;  






SDL_Rect scroll1(SDL_Surface *ecran,SDL_Surface *imageDeFond ,int continuer ,SDL_Rect positionFond) ; 

SDL_Surface * afficher_chrono(SDL_Surface *ecran , SDL_Surface *Background , SDL_Rect p , int running );




int collisionbb ( SDL_Rect posj , SDL_Rect posobj ) ; 
int collisiontrigoinscrit ( SDL_Rect posj , SDL_Rect posobj ) ; 
int CollisionTrigoCir (  SDL_Rect posj , SDL_Rect posobj );

void afficher_entite_secondaire (ent *E, SDL_Surface *ecran) ;


void initialiser_entite(ent E[],int n);
void animation_entite_gauche(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond,int continuer);
void animation_entite_droite(ent* E ,SDL_Rect rects[],SDL_Surface*screen,SDL_Surface*Background,SDL_Rect positionFond);
void enemy_va_x(ent * E);
int position_aleatoire(int positionmax,int positionmin);


#endif // JEU_H_INCLUDED

#ifndef VIE_H_
#define VIE_H_
typedef struct vie
{
	
	SDL_Rect position;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
        SDL_Surface *fond6;
}vie;

void initialiservie(vie *vie);
void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i);
int collisionbb( SDL_Rect posj , SDL_Rect posobj );
#endif

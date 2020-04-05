#include "enigmes.h"

void init_enigme(enigme *e)
{
	e->Tab[0].solution=3;

	e->Tab[1].solution=1;

	e->Tab[2].solution=2;

	e->police = TTF_OpenFont("./Resources/Oswald-Heavy.ttf", 50);
	e->num=-1;
	e->correcte=-1;

	SDL_Color couleureNoire ={0,0,0};

	e->Tab[0].texteQ = TTF_RenderText_Blended (e->police,"Q1: **** ?", couleureNoire) ;
	e->Tab[0].texteR = TTF_RenderText_Blended (e->police, "1- Reponse:1   2-Reponse:2    3-Reponse:3", couleureNoire) ;


	e->Tab[1].texteQ = TTF_RenderText_Blended (e->police,"Q2: ****", couleureNoire) ;
	e->Tab[1].texteR = TTF_RenderText_Blended (e->police, "1- Reponse:    2-Reponse:    3-Reponse:", couleureNoire) ;


	e->Tab[2].texteQ = TTF_RenderText_Blended (e->police,"Q3: ****?", couleureNoire) ;
	e->Tab[2].texteR = TTF_RenderText_Blended (e->police, "1- Reponse:   2-Reponse:    3-Reponse:", couleureNoire) ;

	e->vrai = IMG_Load("./resources/true.png");
	e->faux = IMG_Load("./resources/false.png");

	e->posTF.x=800;
	e->posTF.y=300;

}

void generationAleatoire(enigme *e)
{
	e->num=rand()%3;
	printf("\nenumm=%d",e->num);
}

void afficherEnigme(enigme *e,SDL_Surface *screen)
{
	e->posQ.x=130;
	e->posQ.y=140;
	e->posR.x=330;
	e->posR.y=220;
	SDL_BlitSurface (e->Tab[e->num].texteQ, NULL, screen, &e->posQ) ;
	SDL_BlitSurface (e->Tab[e->num].texteR, NULL, screen, &e->posR) ;
}

void resoudreEnigme (enigme *e,SDL_Event event,SDL_Surface *screen)
{
	switch(event.key.keysym.sym)
	{
		case SDLK_a:
			if(e->Tab[e->num].solution==1)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}
		break;

		case SDLK_b:
			if(e->Tab[e->num].solution==2)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}
		break;

		case SDLK_c:
			if(e->Tab[e->num].solution==3)
			{
				e->correcte=1;
				SDL_BlitSurface(e->vrai,NULL,screen,&e->posTF);
			}
			else
			{
				e->correcte=0;
				SDL_BlitSurface(e->faux,NULL,screen,&e->posTF);
			}
		break;
	}

}

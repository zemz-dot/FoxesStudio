prog:main.o obj.o intobj.o vie.o
	gcc main.o obj.o intobj.o vie.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g

obj.o:obj.c
	gcc -c obj.c -lSDL -lSDL_image -g
intobj.o:intobj.c
	gcc -c intobj.c -lSDL -lSDL_image -g  
vie.o:vie.c 
	gcc -c vie.c -lSDL -lSDL_image -g 

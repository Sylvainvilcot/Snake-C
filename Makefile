but : snake.out

OFILES = affichage_score.o \
				generation_pommes_obstacles.o \
				gameinit.o \
				main.o \
				menu.o \
				physique.o \
				snake_deplacement.o \

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

affichage_score.o : affichage_score.h

gameinit.o : gameinit.h generation_pommes_obstacles.h

generation_pommes_obstacles.o : generation_pommes_obstacles.h

main.o : affichage_score.h gameinit.h generation_pommes_obstacles.h menu.h physique.h snake_deplacement.h

menu.o : menu.h affichage_score.h

physique.o : physique.h

snake_deplacement.o : snake_deplacement.h

snake.out : $(OFILES)
			 	$(CC) $(CFLAGS) -o snake.out $(OFILES) -lgraph

clean :
				-rm -f $(OFILES) snake

.PHONY : but clean

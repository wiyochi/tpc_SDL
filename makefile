SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

EXE_TEST=TEST
EXE_JEU=JEU
EXE_JEUG=JEUG

OPT=-Wall -Wextra -g
LIB=-lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf

JEUG: master.o master_graphique.o gui.o
	gcc -o $@ $^ $(LIB)

JEU: master.o master_texte.o
	gcc -o $@ $^ $(LIB)

TEST: master.o tests.o teZZt.o
	gcc -o $@ $^ $(LIB)
 
%.o: %.c
	gcc -o $@ -c $< $(OPT)

clean:
	rm *.o
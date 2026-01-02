lifesim: main.c grille.c automate.c analyse.c
	gcc -o lifesim main.c grille.c automate.c analyse.c -I.

clean:
	rm lifesim

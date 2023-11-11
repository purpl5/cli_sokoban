#Les variables
CC = gcc
CFLAGS = -W -Wall
EXEC = main
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(wildcard header/*.h)
ARCFILENAME = archive-$(shell date +%F-%H-%M-%S).tar

#Compile le programme en fonction de EXEC, OBJETS, CC, LDFLAGS
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#Génère les fichiers .o dans un répertoire "temporaire" obj qui est créer juste avant la création des fichiers .o
obj/%.o: src/%.c $(DEPS)
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

#Archive notre projet en rajoutant header, src, doc, makefile et doxyfile dans une archive contenant la date de l'archive (nom est égal à la variable ARCFILENAME) 
archive:
	tar -cf ./archive/$(ARCFILENAME) ./header ./src ./doc makefile doxyfile

#Créer le dossier doc "temporaire" qui est créer lors de l'utilisation de la target et est supprimer lorsque
#nous utilisons le clean.
#Nous pouvons retrouver l'index du doxygen HTML a ./doc/html/index.html
doc:
	doxygen doxyfile

#Supprimer les dossiers obj, doc et supprimer main.exe
clean:
	rm -f $(EXEC)
	rm -rf obj doc

#Permets de dire au makefile que les target donner ne sont pas des "file targets" conçu pour créer des fichiers 
#par le biais d'autres fichiers, mais juste de dire a makefile que ces target sont juste fait pour lancer des 
#commandes. 
.PHONY: archive clean doxygen

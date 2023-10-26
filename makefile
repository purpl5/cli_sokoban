# Les variables 
CC = gcc -g 
CFLAGS = -W -Wall 
EXEC = main 
OBJETS = obj/*.o
ARCFILE = archive-$(shell date +%F-%H-%M-%S).tar

#Compile le programme en fonction de EXEC, OBJETS, CC, CFLAGS
$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

#Génère les fichiers .o dans un répertoire "temporaire" obj qui est créer juste avant la création des fichiers .o
#et qui est supprimé au moment du clean.
obj/%.o : src/%.c 	
	mkdir obj 
	$(CC) $(CFLAGS) -c $< 
	mv *.o ./obj

#Permets de dire au makefile que les target donner ne sont pas des "file targets" conçu pour créer des fichiers 
#par le biais d'autres fichiers, mais juste de dire a makefile que ces target sont juste fait pour lancer des 
#commandes. 
.PHONY : archive clean doxygen test flush_log

#Lance le script shell permettant de créer l'archive, contenant la date de création pour les différencier
archive :  
	tar -cf ./archive/$(ARCFILE) ./header ./src ./doc makefile doxyfile

#Créer le dossier doc "temporaire" qui est créer lors de l'utilisation de la target et est supprimer lorsque
#nous utilisons le clean.
#Nous pouvons retrouver l'index du doxygen HTML a ./doc/html/index.html
doxygen :
	mkdir doc
	doxygen doxyfile

#Supprimer les dossiers obj, doc et supprimer main.exe
clean :
	rm ./main
	rm -rf ./obj ./doc
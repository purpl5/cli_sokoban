CC = gcc -g 
CFLAGS = -W -Wall 
EXEC = main 
OBJETS = obj/*.o

$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ -lm 

obj/%.o : src/%.c 	
	mkdir obj 
	$(CC) $(CFLAGS) -c $< 
	mv *.o ./obj

.PHONY : archive clean doxygen

archive : 
	./archive.sh

doxygen :
	mkdir doc
	doxygen doxyfile

clean :
	rm ./main
	rm -rf ./obj ./doc

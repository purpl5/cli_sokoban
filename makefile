CC = gcc -g 
CFLAGS = -W -Wall 
EXEC = main 
OBJETS = obj/main.o
$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ -lm 
obj/%.o : src/%.c 
	$(CC) $(CFLAGS) -c $< 
	mv *.o ./obj
clean :
	rm ./obj/*.o ./main
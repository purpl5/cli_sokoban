CC = gcc -g 
CFLAGS = -W -Wall 
EXEC = main 
OBJETS = obj/main.o
$(EXEC) : $(OBJETS)
	$(CC) $(CFLAGS) -o $@ $^ -lm 
	rm .\obj\*.o
obj/%.o : src/%.c 
	$(CC) $(CFLAGS) -c $< 
	mv *.o ./obj
OUT = mazer
OBJS = main.o sdl_help.o
CC = g++
DEBUG = #-g
CFLAGS = -Wall -c `sdl-config --cflags` $(DEBUG)
LFLAGS = -Wall `sdl-config --libs` -lSDL_image $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp sdl_help.h
	$(CC) $(CFLAGS) main.cpp

sdl_help.o : sdl_help.cpp sdl_help.h
	$(CC) $(CFLAGS) sdl_help.cpp

clean :
	\rm -f *.o *.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT) assets

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	./$(OUT)

scratch : clean run
	

OUT = mazer
OBJS = main.o game.o render.o eventhandler.o
CC = g++
DEBUG = #-g
CFLAGS = -Wall -c `sdl-config --cflags` $(DEBUG)
LFLAGS = -Wall `sdl-config --libs` -lSDL_image $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp game.h
	$(CC) $(CFLAGS) main.cpp

game.o : game.cpp game.h
	$(CC) $(CFLAGS) game.cpp

render.o : render.cpp render.h
	$(CC) $(CFLAGS) render.cpp

eventhandler.o : eventhandler.cpp eventhandler.h
	$(CC) $(CFLAGS) eventhandler.cpp

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
	


OUT = mazer
OBJS = main.o game.o timer.o graphics.o renderer.o inputhandler.o maze.o mazerenderer.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `sdl-config --cflags` $(DEBUG)
LFLAGS = -Wall `sdl-config --libs` -lSDL_image $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp game.h
	$(CC) $(CFLAGS) main.cpp

game.o : game.cpp game.h inputhandler.h timer.h maze.h mazerenderer.h
	$(CC) $(CFLAGS) game.cpp

timer.o : timer.cpp timer.h
	$(CC) $(CFLAGS) timer.cpp

graphics.o : graphics.cpp graphics.h
	$(CC) $(CFLAGS) graphics.cpp

renderer.o : renderer.cpp renderer.h
	$(CC) $(CFLAGS) renderer.cpp

inputhandler.o : inputhandler.cpp inputhandler.h
	$(CC) $(CFLAGS) inputhandler.cpp

maze.o : maze.cpp maze.h
	$(CC) $(CFLAGS) maze.cpp

mazerenderer.o : mazerenderer.cpp mazerenderer.h renderer.h graphics.h maze.h
	$(CC) $(CFLAGS) mazerenderer.cpp

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean :
	\rm -rf *.o *.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT) assets

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	./$(OUT)

scratch : clean run
	

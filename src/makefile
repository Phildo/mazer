
OUT = mazer
OBJS = main.o game.o graphics.o timer.o inpututils.o renderutils.o mainscene.o maze.o mazerenderer.o player.o playerrenderer.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `sdl-config --cflags` $(DEBUG)
LFLAGS = -Wall `sdl-config --libs` -lSDL_image $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp game.h
	$(CC) $(CFLAGS) main.cpp

game.o : game.cpp game.h graphics.h inpututils.h timer.h scene.h mainscene.h
	$(CC) $(CFLAGS) game.cpp

graphics.o : graphics.cpp graphics.h
	$(CC) $(CFLAGS) graphics.cpp

timer.o : timer.cpp timer.h
	$(CC) $(CFLAGS) timer.cpp

inpututils.o : inpututils.cpp inpututils.h
	$(CC) $(CFLAGS) inpututils.cpp

renderutils.o : renderutils.cpp renderutils.h
	$(CC) $(CFLAGS) renderutils.cpp

mainscene.o : mainscene.cpp mainscene.h scene.h maze.h mazerenderer.h player.h playerrenderer.h
	$(CC) $(CFLAGS) mainscene.cpp

maze.o : maze.cpp maze.h
	$(CC) $(CFLAGS) maze.cpp

mazerenderer.o : mazerenderer.cpp mazerenderer.h renderer.h graphics.h maze.h
	$(CC) $(CFLAGS) mazerenderer.cpp

player.o : player.cpp player.h
	$(CC) $(CFLAGS) player.cpp

playerrenderer.o : playerrenderer.cpp playerrenderer.h renderer.h graphics.h player.h
	$(CC) $(CFLAGS) playerrenderer.cpp

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
	

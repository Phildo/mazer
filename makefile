OUT = mazer
OBJS = main.o game.o render.o inputhandler.o
SRCDIR = src
PRE = cd $(SRCDIR) && 
CC = g++
DEBUG = #-g
CFLAGS = -Wall -c `sdl-config --cflags` $(DEBUG)
LFLAGS = -Wall `sdl-config --libs` -lSDL_image $(DEBUG)

$(OUT) : $(OBJS)
	$(PRE) $(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : $(SRCDIR)/main.cpp $(SRCDIR)/game.h
	$(PRE) $(CC) $(CFLAGS) main.cpp

game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h
	$(PRE) $(CC) $(CFLAGS) game.cpp

render.o : $(SRCDIR)/render.cpp $(SRCDIR)/render.h
	$(PRE) $(CC) $(CFLAGS) render.cpp

inputhandler.o : $(SRCDIR)/inputhandler.cpp $(SRCDIR)/inputhandler.h
	$(PRE) $(CC) $(CFLAGS) inputhandler.cpp

clean :
	\rm -rf $(SRCDIR)/*.o $(SRCDIR)/*.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(SRCDIR)/$(OUT) assets

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	$(SRCDIR)/$(OUT)

scratch : clean run
	

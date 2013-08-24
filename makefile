OUT = mazer
OBJS = main.o
CC = g++
DEBUG = #-g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall -lSDL $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm -f *.o *.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT) assets

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

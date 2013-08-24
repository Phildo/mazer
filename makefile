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

tar :
	tar -czvf main.cpp

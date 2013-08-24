OUT = mazer
OBJS = main.o
CC = gcc++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp main.h
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o $(OUT)

tar :
	tar -czvf main.cpp

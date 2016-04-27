OBJS = projectDriver.o HashTable.o Account.o
CC = g++
CFLAGS = -c

projectDriver : $(OBJS)
	$(CC) $(OBJS) -o projectDriver

HashTable.o : HashTable.h Account.h
	$(CC) $(CFLAGS) HashTable.cpp

projectDriver.o : HashTable.h Account.h projectDriver.cpp
	$(CC) $(CFLAGS) projectDriver.cpp

clean:
	\rm *.o projectDriver

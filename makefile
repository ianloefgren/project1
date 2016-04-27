OBJS = HashTable.o Account.o PassTable.o projectDriver.o
CC = g++
CFLAGS = -c

projectDriver : $(OBJS)
	$(CC) $(OBJS) -o projectDriver

Account.o : Account.h PassTable.h Account.cpp
	$(CC) $(CFLAGS) Account.cpp	

PassTable.o : PassTable.h PassTable.cpp
	$(CC) $(CFLAGS) PassTable.cpp	

HashTable.o : HashTable.h Account.h PassTable.h HashTable.cpp
	$(CC) $(CFLAGS) HashTable.cpp

projectDriver.o : HashTable.h Account.h PassTable.h projectDriver.cpp
	$(CC) $(CFLAGS) projectDriver.cpp

clean:
	\rm *.o projectDriver

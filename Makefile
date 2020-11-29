CC=gcc
CFLAGS=-Wall -g
SHARED_DIR=bin/shared

all: libmarksweepgarbagecollector.so
	sudo cp bin/shared/libmarksweepgarbagecollector.so /usr/lib
	sudo chmod 755 /usr/lib/libmarksweepgarbagecollector.so

libmarksweepgarbagecollector.so: collectable.o mark_sweep_garbage_collector.o
	$(CC) $(CFLAGS) -fPIC -shared collectable.o mark_sweep_garbage_collector.o -o $(SHARED_DIR)/libmarksweepgarbagecollector.so
	rm *.o

collectable.o: include/collectable.cpp
	$(CC) $(CFLAGS) -fPIC -c include/collectable.cpp

mark_sweep_garbage_collector.o: include/mark_sweep_garbage_collector.cpp
	$(CC) $(CFLAGS) -fPIC -c include/mark_sweep_garbage_collector.cpp

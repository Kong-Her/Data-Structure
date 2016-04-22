CC = g++
CFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = 

playlist: Playlist.o DoublyLinkedList.o
	$(CC) $(LDFLAGS) Playlist.o DoublyLinkedList.o -o playlist

Playlist.o: Playlist.cpp Playlist.h DoublyLinkedList.h
	$(CC) $(CFLAGS) Playlist.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	$(CC) $(CFLAGS) DoublyLinkedList.cpp

clean:
	rm *o playlist

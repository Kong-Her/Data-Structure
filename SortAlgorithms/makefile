CC = g++
CFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS = -lrt

csort : CensusSort.o CensusData.o CensusDataSorts.o
	$(CC) $(LDFLAGS) CensusSort.o CensusData.o CensusDataSorts.o -o csort

CensusSort.o : CensusSort.cpp CensusData.h
	$(CC) $(CFLAGS) CensusSort.cpp

CensusData.o : CensusData.cpp CensusData.h
	$(CC) $(CFLAGS) CensusData.cpp

CensusDataSorts.o : CensusDataSorts.cpp CensusData.h
	$(CC) $(CFLAGS) CensusDataSorts.cpp
	
clean :
	rm *.o csort 

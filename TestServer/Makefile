#VPATH =../GGLib/NetWork
NETLIB = ../GGLib/NetWork
obj = TestServer.o NetAddr.o GGTCPSocket.o
cc = g++ 
CFLAGS= -std=c++11 -Wall 
OBJDIR= ./obj

TestServer: TestServer.o
	cd ../GGLib/NetWork && $(MAKE)
	$(cc) $(CFLAGS) -o  TestServer $(NETLIB)/*.o TestServer.o


TestServer.o:TestServer.cpp
	$(cc) $(CFLAGS) -c $<

#NetAddr.o:NetAddr.cpp
#	cd ../GGLib/NetWork && $(MAKE)
#	$(cc) $(CFLAGS) -c $<

#GGTCPSocket.o:GGTCPSocket.cpp
#	cd ../GGLib/NetWork && $(MAKE)
#	$(cc) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm TestServer TestServer.o 
	rm $(NETLIB)/*.o
	

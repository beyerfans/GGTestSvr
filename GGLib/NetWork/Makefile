obj=GGTCPSocket.o NetAddr.o
cc=g++ -std=c++11

target: $(obj)

NetAddr.o:NetAddr.h NetAddr.cpp
	$(cc) -c  NetAddr.cpp

GGTCPSocket.o:GGTCPSocket.h GGTCPSocket.cpp
	$(cc) -c  GGTCPSocket.cpp

clean:
	rm $(obj)

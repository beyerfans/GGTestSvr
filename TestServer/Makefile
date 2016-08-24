VPATH =./: ../GGLib/NetWork
obj = TestServer.o NetAddr.o GGTCPSocket.o
cc = g++ -std=c++11


TestServer: NetAddr.o GGTCPSocket.o TestServer.o
	$(cc) -o  TestServer NetAddr.o GGTCPSocket.o TestServer.o

NetAddr.o:NetAddr.cpp
	$(cc) -c $<
	@echo 'NetAddr'     

TestServer.o:TestServer.cpp
	$(cc) -c $<
	@echo 'TestServer'

NetAddr.o:NetAddr.cpp
	$(cc) -c $<
	@echo 'NetAddr'

GGTCPSocket.o:GGTCPSocket.cpp
	$(cc) -c $<
	@echo 'NetAddr'
.PHONY : clean
clean:
	rm TestServer $(obj)
	

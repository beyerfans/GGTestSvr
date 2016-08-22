obj=TestServer.o
cc=g++ -std=c++11

TestServer: $(obj)
	g++ -o  TestServer $(obj)

$(obj):TestServer.cpp
	$(cc) -c TestServer.cpp

clean:
	rm TestServer $(obj)
	

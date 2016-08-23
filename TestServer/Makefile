obj=TestServer.o
cc=g++ -std=c++11

TestServer: $(obj)
	$(cc) -o  TestServer $(obj)

$(obj):TestServer.cpp
	$(cc) -c TestServer.cpp

clean:
	rm TestServer $(obj)
	

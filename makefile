helloword  : helloworld.o
	g++ -o helloworld.exe  helloworld.o
helloworld.o : helloworld.cpp
	g++ -c helloworld.cpp
  

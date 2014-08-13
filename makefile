helloword : helloworld.o
  g++ -o helloword  helloworld.o
  
helloworld.o : helloworld.cpp
  g++ -c helloword helloworld.cpp
  

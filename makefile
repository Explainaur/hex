test: ./code/hex/*.cpp ./code/main.cpp
	g++-8  -g code/main.cpp -I code -std=c++1z -lpthread -Wall -O2 -o test
	

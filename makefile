INCLUDE=-I./src/checkers/headers/ -I./src/communication/

all: player1 player2

player1:
	g++ -Wall src/checkers/*.cpp src/player1/*.cpp $(INCLUDE) -o player1\
	    -lSDL -lSDL_image -lSDL_ttf -lboost_system -std=c++11

player2:
	g++ -Wall src/checkers/*.cpp src/player2/*.cpp $(INCLUDE) -o player2\
	    -lSDL -lSDL_image -lSDL_ttf -lboost_system -std=c++11

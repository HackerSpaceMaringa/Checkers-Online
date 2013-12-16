CPP=g++
INCLUDE=-I./src/checkers/headers/ -I./src/communication/
WFLAG=-Wall 
SRC_CHECKERS=$(wildcard ./src/checkers/*.cpp)
OBJ_CHECKERS=$(SRC_CHECKERS:.cpp=.o)
SRC_COMM=$(wildcard ./src/communication/*.cpp)
OBJ_COMM=$(SRC_COMM:.cpp=.o)
LINKER=-lSDL -lSDL_image -lSDL_ttf -lboost_system
STD=-std=c++11

all: player1 player2

.cpp.o:
	$(CPP) $(WFLAG) -c $(INCLUDE) $< -o $@ $(STD)

player1: $(OBJ_CHECKERS) $(OBJ_COMM)
	$(CPP) $(WFLAG) $^ src/player1/*.cpp $(INCLUDE)\
	    -o player1 $(LINKER) $(STD)

player2: $(OBJ_CHECKERS) $(OBJ_COMM)
	$(CPP) $(WFLAG) $^ src/player2/*.cpp $(INCLUDE)\
	    -o player2 $(LINKER) $(STD)

clean:
	rm -rf player1 player2 $(OBJ_CHECKERS) $(OBJ_COMM)

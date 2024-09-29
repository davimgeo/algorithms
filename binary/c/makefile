CXX = gcc
CXXFLAGS = -Wall -I./src/include
OUT = bin/bin.out

SRC = run.c src/bin_1D.c src/bin_2D.c -I./src/include

run:
	@$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)
	@./$(OUT)


build:
	@/usr/bin/g++ -DEVAL -std=c++11 -O2 -pipe -static -s -o tsp grader.cpp tsp.cpp

run:
	@./tsp && clear && more output.txt
all: build run

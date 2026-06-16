main: main.cpp graph.cpp
	g++ *.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main
run: main
	./main
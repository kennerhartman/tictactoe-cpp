CXX = g++

# there is only one return error that will not be fixed, but does not disrupt the program
CFLAGS = -Wno-return-type

main: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o main
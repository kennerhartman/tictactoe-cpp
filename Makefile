CXX = g++

# there is only one return error that will not be fixed, but does not disrupt the program
CXXFLAGS = -Wno-return-type

main: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o main
CXX = clang++

CXXFLAGS=-std=c++23 -Wall -Wconversion

run: mat
	./mat

mat: mat.o
	$(CXX) $^ -o $@

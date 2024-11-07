CXX = clang++

LIB = math_functions
SHARED = lib$(LIB).so

main: main.o $(SHARED)
	$(CXX) -L. -l$(LIB) $< -o $@

run: main
	LD_LIBRARY_PATH=. ./main

$(SHARED): $(LIB).o
	$(CXX) -shared -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.so *.o main

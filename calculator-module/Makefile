CXX := clang++

CXXFLAGS := -std=c++20 -fprebuilt-module-path=.

MODS := calculator.cppm
SRCS := main.cpp
OBJS := $(MODS:.cppm=.o) $(SRCS:.cpp=.o)

exe: $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cppm
	$(CXX) $(CXXFLAGS) -fmodule-output -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o *.pcm exe

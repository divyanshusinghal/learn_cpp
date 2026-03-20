.PHONY: all clean rebuild print print-%

CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

SOURCES := $(wildcard *.cpp)
TARGETS := $(SOURCES:.cpp=.exe)

all: $(TARGETS)

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

rebuild: clean all

print:
	@echo "SOURCES: $(SOURCES)"
	@echo "TARGETS: $(TARGETS)"

print-%:
	@echo "$* = $($*)"

# useful command to know
# make -n -> tells you the equivalent of output what actuall runs when you call "make" 
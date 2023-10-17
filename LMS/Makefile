# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source directory and target binary directory
SRCDIR = src
BINDIR = bin

# Executable name
TARGET = lms

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

all: directory $(BINDIR)/$(TARGET)

directory:
	@mkdir -p $(BINDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o
	rm -f $(BINDIR)/$(TARGET)

.PHONY: all directory clean
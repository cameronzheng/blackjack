# Compiler to use
CXX = g++

# Compiler flags:
# -Wall: Enable all warning messages
# -Wextra: Enable extra warning flags
# -g: Include debugging information
CXXLFAGS = -std=c++23 -Wall -g

# Target executable name
TARGET = main

# Source files
SRCS = main.cpp deck.cpp

# Object files (replace .c with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS) 

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
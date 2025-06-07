# Compiler (macOS Xcode tool)
CXX = clang++

# Object files
OBJS = main.o Board.o

# Executable name
TARGET = chess_game

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

# Compilation rule
%.o: %.cpp
	$(CXX) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

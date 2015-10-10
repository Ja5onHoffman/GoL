CXX = g++
SOURCE_FILES = Cell.cpp World.cpp main.cpp

gameOfLife: $(SOURCE_FILES)
	$(CXX) $(SOURCE_FILES) -o gameOfLife

clean:
	rm gameOfLife

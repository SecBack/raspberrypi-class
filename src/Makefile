# # Makefile for building the examples distributed
# # with SenseHat.
# # Header files path (Update this with the library installation folder).
# HEADERS_PATH = /usr/include

# # Library path (Update this with the library installation folder).
# LIBRARY_PATH = /usr/lib

# # List of source files
# SOURCES += Display.cpp Menu.cpp main.cpp

# #List of object files
# OBJECTS += $(SOURCES:.cpp=.o)

# all: Display Menu main

# #Compile all of the source files
# %.o: %.cpp
# 	@echo ---Compiling file: $<
# 	g++ -I $(HEADERS_PATH) -std=c++0x -c $^ -o $@
# 	@---echo

# #Building display executable
# Display: Display.o
# 	@ ---echo Building target file: $@.
# 	g++ -L$(LIBRARY_PATH) -o $@ $^
# 	@ ---echo

# #Building menu executable
# Menu: Menu.o
# 	@ ---echo Building target file: $@.
# 	g++ -L$(LIBRARY_PATH) -o $@ $^ -lncurses -l SenseHat -l RTIMULib
# 	@ ---echo

# #Building main executable
# main: main.o
# 	@ ---echo Building target file: $@.
# 	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
# 	@ ---echo

# # Uninstall the exemples from the system
# uninstall:
# 	rm -f  Display main Menu

# .PHONY: clean
# clean:
# 	rm -f *.o

# g++ -c Display.cpp -L/usr/lib -L/usr/lib
all:
	g++ -c Sensors.cpp
	g++ -c Data.cpp
	g++ -c Display.cpp
	g++ -c Menu.cpp -lncurses
	g++ -c main.cpp
	g++ -o a.o main.cpp Display.o Menu.o Sensors.o Data.o -L/usr/lib -L/usr/lib -l SenseHat -l RTIMULib -lncurses -lpthread

.PHONY: clean
clean:
	rm -f *.o
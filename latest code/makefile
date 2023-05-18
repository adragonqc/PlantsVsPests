# CC=g++
# CFLAGS = -std=c++11 -Wall 
# PATH1 = -I /home/linuxbrew/.linuxbrew/Cellar/sfml/2.5.1_2 
# SFMLFLAGS = -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# SOURCES=main.cpp farmer.cpp tomato_plant.cpp pest.cpp map.cpp #squirrel.cpp frog.cpp map.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# EXECUTABLE=game

# all: $(SOURCES) $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(LDFLAGS) $(OBJECTS) -o $@



# # default target
# #this creates the object
# main.o: main.cpp
# 	$(CC) $(CFLAGS) -c -o $@ $< $(PATH1)

# #then calls the object to make the runner and complete the compilation
# side: main.o
# 	$(CC) $(CFLAGS) $< -o $@  $(PATH1) $(SFMLFLAGS)

# # program1
# name: $(TARGETS)
# 	$(CC) $(CFLAGS) $< -o $@ $(PATH1) $(SFMLFLAGS)

# # #this creates the object
# # farmer.o: farmer.cpp
# # 	$(CC) $(CFLAGS) -c -o $@ $< $(PATH1)

# # #then calls the object to make the runner and complete the compilation
# # side: farmer.o
# # 	$(CC) $(CFLAGS) $< -o $@  $(PATH1) $(SFMLFLAGS)

# #this creates the object
# map.o: map.cpp
# 	$(CC) $(CFLAGS) -c -o $@ $< $(PATH1)

# #then calls the object to make the runner and complete the compilation
# side2: map.o
# 	$(CC) $(CFLAGS) $< -o $@  $(PATH1) $(SFMLFLAGS)


# # #this creates the object
# # pest.o: pest.cpp
# # 	$(CC) $(CFLAGS) -c -o $@ $< $(PATH1)

# # #then calls the object to make the runner and complete the compilation
# # side: pest.o
# # 	$(CC) $(CFLAGS) $< -o $@  $(PATH1) $(SFMLFLAGS)

# # #this creates the object
# # tomato_plant.o: tomato_plant.cpp
# # 	$(CC) $(CFLAGS) -c -o $@ $< $(PATH1)


# # program1
# name: $(TARGETS)
# 	$(CC) $(CFLAGS) $< -o $@ $(PATH1) $(SFMLFLAGS)



# #this runs the program
# run: side
# 	./side

# # clean targetss
# clean:
# 	rm -f sfml-app # deprecated
# 	rm -f *.app
# 	rm -f *.o
# 	rm -f *.d
# 	rm -f -r objects/
# 	rm -f -r dependencies/

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CXX = g++
CXXFLAGS = -std=c++11 -Wall
PATH1 = -I /home/linuxbrew/.linuxbrew/Cellar/sfml/2.5.1_2 
SFML_LIBS = -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCS = main.cpp map.cpp farmer.cpp plant.cpp pest.cpp strawberry.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = mygame

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(PATH1) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f sfml-app # deprecated
	rm -f *.app
	rm -f *.o
	rm -f *.d
	rm -f -r objects/
	rm -f -r dependencies/
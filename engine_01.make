#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Engine.cpp Sprite.cpp error.cpp GLSLProgram.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lGL -lGLU -lGLEW -lglut

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = new_engine

#This is the target that compiles our executable
all :
	$(CC) -o $(OBJ_NAME) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS)
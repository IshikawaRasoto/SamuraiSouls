PROJECT_NAME := main

CC := g++
DIR := ./src 

SRCS := $(wildcard *.cpp $(foreach dir, $(DIR), $(wildcard $(dir)**/*.cpp) $(wildcard $(dir)*/*/*.cpp)) $(wildcard $(dir)*/*/*/*.cpp) $(wildcard $(dir)*/*/*/*/*.cpp))
INCLUDE := -I./include 
SFML_MODULES := window graphics system
SFML_FLAGS := $(foreach module, $(SFML_MODULES), -lsfml-$(module))

FLAGS = $(SFML_FLAGS) -lm

.PHONY: clean

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(SRCS)
	$(CC) -o $@ $^ $(FLAGS) $(INCLUDE)

clean:
	rm -rf ./$(PROJECT_NAME)
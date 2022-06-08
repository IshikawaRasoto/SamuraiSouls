PROJECT_NAME := main

CC := g++
SRC_DIR := src
INCLUDE_DIR := include

CSRCS := $(shell find ./ $(SRC_DIR) -name "*.cpp")
HSRCS := $(shell find $(INCLUDE_DIR) -name "*.hpp")
OBJS := $(CSRCS:.cpp=.o)

INCLUDES := $(foreach dir, $(INCLUDE_DIR), -I$(dir))
SFML_MODULES := window graphics system
SFML_FLAGS := $(foreach module, $(SFML_MODULES), -lsfml-$(module))

FLAGS = $(SFML_FLAGS) -lm $(INCLUDES) -c

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJS) 
	$(CC) -o $@ $^ $(SFML_FLAGS)

%.o: %.cpp
	$(CC) -o $@ $< $(FLAGS) 

main.o: main.cpp
	$(CC) -o $@ $< $(FLAGS)

clean:
	rm -rf $(shell find ./ $(SRC_DIR) -name "*.o") ./$(PROJECT_NAME)

.PHONY: clean all

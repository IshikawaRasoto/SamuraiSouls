CC = g++

TARGET = main

OUTDIR = ./bin
SUBDIR = Entities
LIBS = sfml-graphics sfml-window sfml-system

SRCS = $(wildcard *.cpp $(foreach fd,$(SUBDIR),$(fd)/*.cpp))
FLAGS = $(foreach lib, $(LIBS),-l$(lib))

.PHONY = clean

$(TARGET): $(SRCS)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	rm -rf ./$(TARGET)

#add biblioteca de math (-lm)
CC      := gcc
CFLAGS  := -Iinclude -Wall -Wextra -g -O0 -fno-omit-frame-pointer -std=gnu17 -D_USE_MATH_DEFINES
LDFLAGS := -lm

# Find all source files in subdirectories
SRCS    := $(shell find src -name "*.c")
# Convert src/*.c to bin/*.o
OBJS    := $(SRCS:src/%.c=bin/%.o)
TARGET  := bin/engine_sim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Rule for compiling nested source files into a flat bin/ structure
bin/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/*

.PHONY: all clean

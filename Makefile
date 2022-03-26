# Compiler to use
CC = clang

# Compiler flags
CFLAGS = -Wall -DNDEBUG

# The name to use for both the target source files, and the output files
all: binary_search stack queue circular_queue


clear:
	rm binary_search stack queue circular_queue

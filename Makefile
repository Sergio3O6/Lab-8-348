# Makefile for NFL Score and Temperature Conversion Programs

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Executable names
FOOTBALL = football_score
TEMP = temperature_conversion

# Default target
all: $(FOOTBALL) $(TEMP)

# Build football_score program
$(FOOTBALL): football_score.c
	$(CC) $(CFLAGS) football_score.c -o $(FOOTBALL)

# Build temperature_conversion program
$(TEMP): temperature_conversion.c
	$(CC) $(CFLAGS) temperature_conversion.c -o $(TEMP)

# Clean up compiled files
clean:
	rm -f $(FOOTBALL) $(TEMP)

# Phony targets so they don't conflict with files named 'all' or 'clean'
.PHONY: all clean

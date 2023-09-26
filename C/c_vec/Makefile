PROJECT_NAME = vec
CC = gcc
CFLAGS = -Iinclude -Wall -lm
SRC_DIR = src
BUILD_DIR = build

# list of all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# list of object files from source files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

build: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(PROJECT_NAME) $(OBJ_FILES)

# Rule to compile individual object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)/*.o $(PROJECT_NAME)

run:
	make build
	./build/$(PROJECT_NAME)


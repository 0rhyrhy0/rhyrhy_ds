# Directories
SRC_DIR := src
OBJ_DIR := obj
HEADER_DIR := headers
BIN_DIR := bin

# File lists
HEADERS := $(wildcard $(HEADER_DIR)/*.h)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler   
CC := g++
# add any compiler flags here
CFLAGS := -Wall -Wextra -Wmissing-declarations -Werror
CFLAGS := -Wall -Wextra -Werror  # for simple one-file project, where declaration is not seperated


# Targets
all: run

# We are checking both header files and source files,
# but it is better to modify both, or only source files.
# If you modify only the header file, it can mislead to malfunction.
# Typically the header file is considered to include only the declarations,
# and the source file include all the definition and implementations.
$(BIN_DIR)/main.exe: $(HEADERS) $(OBJS)
	@$(CC) -o $@ $^ $(CFLAGS)
	@echo $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@echo $@


.PHONY: run, clean, r

run : bin/main.exe
	@echo
	@./bin/main.exe
	@echo

clean:
	@rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
	clear

r : 
	@make clean --no-print-directory
	@make run --no-print-directory

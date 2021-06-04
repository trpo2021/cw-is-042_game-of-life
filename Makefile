APP_NAME = gameoflife
LIB_NAME = libgameoflife

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(BIN_DIR) $(OBJ_DIR) $(SRC_DIR) $(RES_DIR) $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)

.PHONY: test
test: bin/test

bin/test: obj/test/main.o obj/test/firsttest.o $(LIB_OBJECTS) test/ctest.h
	$(CC) -Wall -I src obj/test/main.o obj/test/firsttest.o $(LIB_OBJECTS) test/ctest.h -o bin/test

obj/test/main.o: test/main.c
	$(CC) -c -Wall -I src test/main.c -o obj/test/main.o

obj/test/firsttest.o: test/firsttest.c
	$(CC) -c -Wall -I src test/firsttest.c -o  obj/test/firsttest.o 

.PHONY: clean
clean:
	-rm -f $(APP_PATH) $(APP_OBJECTS) $(DEPS) $(LIB_PATH)
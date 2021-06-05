APP_NAME = gameoflife
LIB_NAME = libgameoflife
TST_NAME = testgameoflife

CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall
CPPFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TST_PATH = $(BIN_DIR)/$(TST_NAME)

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TST_SOURCES = $(shell find $(TST_DIR) -name '*.$(SRC_EXT)')
TST_OBJECTS = $(TST_SOURCES:$(TST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TST_OBJECTS:.o=.d)

.PHONY: all
all: $(BIN_DIR) $(OBJ_DIR) $(SRC_DIR) $(RES_DIR) $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)
	mkdir -p $(OBJ_DIR)/$(TST_DIR)

.PHONY: test
test: $(TST_PATH)

$(TST_PATH): $(TST_OBJECTS) $(LIB_OBJECTS) $(LIB_PATH)
	$(CC) $(TFLAGS) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/$(TST_DIR)/%.o: $(TST_SOURCES).c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm -f $(APP_PATH) $(LIB_PATH) $(TST_PATH) $(APP_OBJECTS) $(LIB_OBJECTS) $(OBJ_DIR)/$(TST_DIR)/* $(DEPS) 
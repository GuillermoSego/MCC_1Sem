# Directory structure
OBJECT_DIR = ./build/Debug
TARGET_DIR = ./build

# Target name
LINK_TARGET = $(TARGET_DIR)/P2_T6

# Macro with object files
_OBJS =  \
 Matrix.o \
 P2_T6.o \

OBJS = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJS))

# Target Build
all : $(LINK_TARGET)

# Linker command
$(LINK_TARGET) : $(OBJS)
	gcc -g -o $@ $^

# Create the directory structure if it doesn't exist
$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

# Compiler command
$(OBJECT_DIR)/%.o : %.c | $(OBJECT_DIR)
	gcc -g -o $@ -c $<

# Dependency Rules
$(OBJECT_DIR)/P2_T6.o : P2_T6.c Matrix.h
$(OBJECT_DIR)/Matrix.o : Matrix.c Matrix.h

# Cleaning files
REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean :
	rm -f $(REBUILDABLES)

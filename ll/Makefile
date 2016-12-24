#
# Filename:    Makefile
# Author:      Shahid Alam
# Dated:       December 02, 2016
# Decription:  Makefile for the Linked List example
#

ROOT  := source

# Directories
BIN_DIR        := bin
LIBS_DIR       := lib
INCLUDES_DIR   := $(ROOT)/include
LL_DIR         := $(ROOT)/ll
MAIN_DIR       := $(ROOT)

CPP      := gcc
CC       := gcc
LD       := gcc
AR       := ar
RM       := rm -f
CPPFLAGS := -Wno-deprecated -Wno-write-strings -Ofast -ansi -fpermissive -I$(INCLUDES_DIR)
CFLAGS   := -Wno-deprecated -Wno-write-strings -Ofast -ansi -I$(INCLUDES_DIR)
LDFLAGS  := -Ofast -ansi -s -static
LIBS     := -L$(LIBS_DIR)

echo_cmd = @printf   "   %-15s %s\n" "$(1)" "$(2)"

usage:
	@echo ""
	@echo "Makefile for the Linked List example"
	@echo ""
	@echo "Usage:"
	@echo "	make all        # Compile everything"
	@echo "	make clean      # Remove all object files"
	@echo "	make clean_all  # Remove all object files and binary"
	@echo ""

SRCS	=	$(LL_DIR)/ll.c \
			$(MAIN_DIR)/main.c

all: $(SRCS) ll.exe

OBJS     := $(SRCS:.c=.o)

ll.exe: $(OBJS)
	@printf   "   LD              $(BIN_DIR)/$@\n"
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(BIN_DIR)/$@

.c.o:
	$(call echo_cmd,CC    ,$@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf   "   RM \n $(OBJS)\n"
	$(RM) $(OBJS)

clean_all:
	@printf   "   RM \n $(OBJS) $(BIN_DIR)/ll.exe\n"
	$(RM) $(OBJS) $(BIN_DIR)/ll.exe

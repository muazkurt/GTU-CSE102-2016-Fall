#
# Filename:    Makefile
# Author:      Muaz Kurt
# Dated:       December 21, 2016
# Decription:  Makefile for Double and Circular Linkilst
#

Root        := source

# Directories
Binary      := bin
Library     := lib
Includes    := $(Root)/include
Circular    := $(Root)/CircularList
Double      := $(Root)/DoubleList
Main        := $(Root)

CC          := gcc
LD          := gcc
CFLAGS		:= -Ofast -ansi
LDFLAGS     := -Ofast -ansi
RM          := rm -f

usage:
	@echo ""
	@echo "Makefile for Double and Circular List"
	@echo ""
	@echo "Usage:"
	@echo " make double           # Compile Double List"
	@echo " make circular         # Compile Circular List"
	@echo " make clear            # Delete all object files"
	@echo " make clear_all        # Delete all object files and binary files"
	@echo ""

SRCS    =   $(Circular)/HW09_MUAZ_KURT_151044062_CircularList.c \
            $(Main)/main.c

circular: $(SRCS) circular.exe

OBJ     := $(SRCS:.c=.o)

circular.exe: $(OBJ)
    @printf "   LD                  $(Binary)/$@\n"
    $(LD) $(LDFLAGS) $(OBJ) $(Library) -o $(Binary)/$@

.c.o:
    @printf "   CC                  $@\n"
    $(CC) $(CFLAGS) -c $< -o $@

clear:
    @printf   "   RM\n   $(OBJ) \n"
    $(RM) $(OBJ)

clear_all:
    @printf   "   RM\n   $(OBJ) $(Binary)/circular.exe \n"
    $(RM) $(OBJ) $(Binary)/circular.exe
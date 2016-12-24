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

CC		 := gcc
CFLAGS   := -Wno-deprecated -Wno-write-strings -Ofast -ansi -I$(Includes)
LDFLAGS  := -Ofast -ansi -s -static
RM       := rm -f

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

SRCCircular	=	$(Circular)/HW09_MUAZ_KURT_151044062_CircularList.c \
				$(Main)/main.c

circular: $(SRCCircular) CircularList.exe

OBJCircular    :=  $(SRCCircular:.c=.o)

CircularList.exe: $(OBJCircular)
	@printf     "   LD                  $(Binary)/$@	\n"
	$(CC) $(LDFLAGS) -o $(Binary)/$@ $(OBJCircular)

.c.o:
	@printf     "   CC            $@		\n"
	$(CC) $(CFLAGS) -c $< -o $@

SRCDouble	=   $(Double)/HW09_MUAZ_KURT_151044062_DoubleList.c \
                    $(Main)/main.c

double: $(SRCDouble) DoubleList.exe

OBJDouble	:=  $(SRCDouble:.c.o)

DoubleList.exe: $(OBJDouble)
	@printf     "   LD                  $(Binary)/$@	\n"
	$(CC) $(LDFLAGS) -o $(Binary)/$@ $(OBJDouble)

clear:
	@printf     "   RM    $(OBJCircular), $(OBJDouble)\n"
	$(RM) $(OBJCircular) $(OBJDouble)

clear_all:
	@printf "   RM  \n  $(OBJCircular), $(OBJDouble)\n"
	@printf "$(Binary)/HW09_MUAZ_KURT_151044062_CircularList.exe\n"
	@printf "$(Binary)/HW09_MUAZ_KURT_151044062_DoubleList.exe\n"
	$(RM) $(OBJCircular) $(OBJDouble) $(Binary)/HW09_MUAZ_KURT_151044062_CircularList.exe $(Binary)/HW09_MUAZ_KURT_151044062_DoubleList.exe

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
LD   	    := gcc
CFLAGS		:= -Wno-deprecated -Wno-write-strings -Ofast -ansi -I$(Includes)
LDFLAGS		:= -Ofast -ansi -s -static
RM          := rm -f

echo_cmd = @printf   "   %-25s %s\n" "$(1)" "$(2)"


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

SRCCircular     =   $(Circular)/HW09_MUAZ_KURT_151044062_CircularList.c \
                    $(Main)/main.c

SRCDouble       =   $(Double)/HW09_MUAZ_KURT_151044062_DoubleList.c \
                    $(Main)/main.c

double: $(SRCDouble) HW09_MUAZ_KURT_151044062_DoubleList.exe

OBJDouble       :=  $(SRCDouble:.c.o)

HW09_MUAZ_KURT_151044062_DoubleList.exe: $(OBJDouble)
									@printf     "   LD                  $(Binary)/$@\n"
									$(LD) $(LDFLAGS) $(OBJDouble) $(OBJDouble) -o $(Binary)/$@

circular: $(SRCCircular) HW09_MUAZ_KURT_151044062_CircularList.exe

$OBJCircular    :=  $(SRCCircular:.c.o)

HW09_MUAZ_KURT_151044062_CircularList.exe: $(OBJCircular)
										@printf     "   LD                  $(Binary)/$@\n"
										$(LD) $(LDFLAGS) $(OBJCircular) -o $(Binary)/$@

.c.o:
		$(call echo_cmd, CC     ,$@)
		$(CC) $(CFLAGS) -c $< -o $@

clear:
		@printf     "   RM  \n  $(OBJCircular), $(OBJDouble)\n"
		$(RM)   $(OBJCircular)  $(OBJDouble)

clear_all:
			@printf "   RM  \n  $(OBJCircular), $(OBJDouble)\n"
			@printf "$(Binary)/HW09_MUAZ_KURT_151044062_CircularList.exe\n"
			@printf "$(Binary)/HW09_MUAZ_KURT_151044062_DoubleList.exe\n"
			$(RM) $(OBJCircular) $(OBJDouble) $(Binary)/HW09_MUAZ_KURT_151044062_CircularList.exe $(Binary)/HW09_MUAZ_KURT_151044062_DoubleList.exe

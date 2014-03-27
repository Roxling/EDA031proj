# Define the compiler. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of libstdc++.
CXXFLAGS =  -g -O2 -Wall -W -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
LDFLAGS =   -g 
#CPPFLAGS =  -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS += -stdlib=libc++

PROGS = newsserver
all:$(PROGS)
	
newsserver: newsserver.o ../connection.o server.o Commands/CommandFactory.o Commands/Command.o Commands/create_art_command.o Commands/create_ng_command.o Commands/delete_art_command.o Commands/delete_ng_command.o Commands/get_art_command.o Commands/list_art_command.o Commands/list_ng_command.o Commands/no_command.o DB/MemDB.o DB/DiskDB.o DB/Article.o DB/NewsGroup.o ../protocol.o

CommandFactory: Commands/CommandFactory.o ../protocol.o


# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm -f *.d $(PROGS)
	cd DB;make clean;
	cd Commands; make clean;

# Generate dependencies in *.d files
%.d: %.cc
	@set -e; rm -f $@; \
         $(CPP) -MM $(CXXFLAGS) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$


# Include the *.d files
SRC = $(wildcard *.cc)
include $(SRC:.cc=.d)


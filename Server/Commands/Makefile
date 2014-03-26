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

all:   $(PROGS)

# Create the library; ranlib is for Darwin and maybe other systems.
# Doesn't seem to do any damage on other systems.

all: $(PROGS)

# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm -f *.d $(PROGS)



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


all:
	cd Client; make
	cd Server; make
	
# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o* $(PROGS)
	rm -f *.d* $(PROGS)
	rm -f *~* $(PROGS)

	cd Client; make clean
	cd Server; make clean

cleangit:
	git rm *.o*;
	git rm *.d*;
	git rm *~*;

# Generate dependencies in *.d files
%.d: %.cc
	@set -e; rm -f $@; \
         $(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$

# Include the *.d files
SRC = $(wildcard *.cc)
include $(SRC:.cc=.d)

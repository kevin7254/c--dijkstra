# Made by Viktor Eriksson vi2476er-s and Kevin Nilsson ke6880ni-s

# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = test_graph_small test_nodeset test_dijkstra test_graph_nofile test_graph_file main

all: $(PROGS)

test: test_graph_small test_nodeset test_dijkstra test_graph_nofile test_graph_file main
	./test_graph_small
	./test_nodeset
	./test_dijkstra
	./test_graph_nofile
	./test_graph_file
	./main

# Targets rely on implicit rules for compiling and linking
#main: main.o edge.o node.o
test_graph_small: test_graph_small.o edge.o node.o
test_nodeset: test_nodeset.o nodeset.o node.o edge.o
test_dijkstra: test_dijkstra.o nodeset.o node.o edge.o dijkstra.o
test_graph_nofile: test_graph_nofile.o node.o edge.o graph.o
main: edge.o graph.o node.o dijkstra.o nodeset.o 
test_graph_file: test_graph_file.o node.o edge.o graph.o dijkstra.o nodeset.o

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)

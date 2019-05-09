SRCDIRS = Base Tase
INCDIR = include
OBJDIR = obj
CXX = g++
CXXFLAGS = -I$(INCDIR) -std=gnu++11 -g -Wall

#SOURCES := $(wildcard $(SRCDIRS:%=src/%/*.cpp)) $(wildcard src/*.cpp)
#OBJECTS :=  $(addprefix $(OBJDIR)/,$(SOURCES:$(SRCDIRS)/%.cpp=%.o))

all: 
	$(CXX) -c src/main.cpp -o obj/main.o $(CXXFLAGS) 
	$(CXX) -c src/Base/Base.cpp -o obj/Base/Base.o $(CXXFLAGS)
	$(CXX) -c src/Utility/FileSystem.cpp -o obj/Utility/FileSystem.o $(CXXFLAGS)
	$(CXX) -c src/Utility/DateTime.cpp -o obj/Utility/DateTime.o $(CXXFLAGS)
	$(CXX) -o bin/ProjectCreator obj/Base/Base.o obj/Utility/FileSystem.o obj/Utility/DateTime.o obj/main.o


makedirs:
	mkdir obj
	mkdir bin
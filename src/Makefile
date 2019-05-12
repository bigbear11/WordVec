CXX := g++ -std=c++11
CXXFLAGS := -g -O2

THIRDPART := ../thirdpart

#include path
INC_PATH := -I$(THIRDPART)/boost-1.53.0/include
INC_PATH += -I$(THIRDPART)
INC_PATH += -I./

#lib path
LIB_BOOST_PATH := $(THIRDPART)/boost-1.53.0/lib
LIBS := -L$(LIB_BOOST_PATH)

LIBS := -L$(LIB_BOOST_PATH)
LIBS += $(LIB_BOOST_PATH)/libboost_system.a
LIBS += $(LIB_BOOST_PATH)/libboost_program_options.a
LIBS += -lpthread
LIBS += -lrt

BINS := word2vec
SRC := $(wildcard *.cc) 
OBJ := $(patsubst %.cc, %.o, $(SRC))

all:$(BINS)

$(BINS): main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INC_PATH) $(LIBS)

%.o : %.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@ $(INC_PATH)

clean:
	rm *.o $(BINS)

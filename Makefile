
CPP = g++
PROJECT_MANAGER = project
PRJOCET_BIN = listpost

# FLAGS
BUILD_FLAG = -lm
CPPFLAG = -Wall -I ./src
TEST_FLAG = -lgtest

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(shell find src -name "*.cpp")
BIN_OBJ = $(patsubst %.cpp,build/%.o,$(BIN_SRC))

LIB_SRC = $(shell find src/lib -name "*.cpp" )
LIB_OBJ = $(patsubst %.cpp,build/%.o,$(LIB_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(shell find test -name "*.cpp")
TESTING_OBJ = $(patsubst %.cpp,build/%.o,$(TESTING_FILE))

# SOURCE CODE TO OBJECT FILE
./build/src/%.o: ./src/%.cpp ./src/%.hpp
	@mkdir -p $(dir $@)
	@$(CPP) -g $(CPPFLAG) -c $< -o $@

./build/src/%.o: ./src/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) -g $(CPPFLAG) -c $< -o $@

./build/test/%.o: ./test/%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) -g $(CPPFLAG) -c $< -o $@

clear:
	@rm -rf build/* bin/*

clean: clear

all: clear build

./build/lib/libs.a: $(LIB_OBJ)
	@mkdir -p build/lib
	@ar rcs $@ $^

./bin/test: ./build/lib/libs.a $(TESTING_OBJ)
	@mkdir -p bin
	@$(CPP) -g $(TEST_FLAG) -c $< -o $@

./bin/main: ./build/lib/libs.a ./src/main.cpp
	@mkdir -p bin
	@$(CPP) $(CFLAG) -c $< -o $@

test: ./bin/test
	@./bin/test

run: ./bin/main
	@./bin/run

.PHONY: all clean clear test run
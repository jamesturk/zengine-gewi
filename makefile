#Makefile for ZEngine

include ./config
#defines the user shouldn't change#
INCLUDES = -I./include $(SDL_INC_PATH) $(GL_INC_PATH) $(ZE_INC_PATH)
LIBRARIES = -L./lib $(SDL_LIB_PATH) $(GL_LIB_PATH)
CFLAGS = $(EXTRA_OPTIONS) $(WARN_LEVEL) $(INCLUDES) $(LIBRARIES)
LIB_OUT = ./lib/libgewiS.a
ALL_TESTS = gewiTest00

SOURCES = $(wildcard src/*.cpp)

#SOURCES with path stripped and .cpp changed to .o
OBJECTS = $(notdir $(SOURCES:.cpp=.o))

#build targets#

$(LIB_OUT): $(SOURCES)
	@echo Building $(BUILD_NAME)...
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(AR) $(LIB_OUT) $(OBJECTS)
	@echo Built $(BUILD_NAME).

./test/bin/gewiTest00$(EXE) : $(LIB_OUT) ./test/gewiTest00.cpp
	@echo Building gewiTest00...
	$(CC) $(CFLAGS) ./test/gewiTest00.cpp -o ./test/bin/gewiTest00$(EXE) $(LIBS)
	@echo gewiTest00 compiled.

.PHONY: $(ALL_TESTS) tests all install clean veryclean

gewiTest00: ./test/bin/gewiTest00$(EXE)

tests: $(ALL_TESTS)
all: $(LIB_OUT) $(ALL_TESTS)

install: $(LIB_OUT)
	mkdir -p $(INSTALL_INC)
	mkdir -p $(INSTALL_LIB)
	mkdir -p $(INSTALL_DOC)
	cp -r ./include/* $(INSTALL_INC)
	cp $(LIB_OUT) $(INSTALL_LIB)
	cp -r ./doc/html/* $(INSTALL_DOC)

clean:
	rm -f *.o
	@echo All object files removed.

veryclean:
	rm -f *.o
	rm -f ./test/bin/*.exe
	rm -f $(LIB_OUT)
	@echo All output files removed.

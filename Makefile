# Copyright(c) [2017] <Frzifus> All Rights Reserved.
# Distributed under MIT license.
# See file LICENSE for detail at LICENSE file.

CXX=g++
CXXFLAGS=-std=c++14 -I ./src/ -isystem ./lib/SFML/include/ -isystem ./lib/protobuf/src/ -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -c

SOURCEDIR=./src/
SFMLPATH=./lib/SFML/lib/
PROTOPATH=./lib/protobuf/src/.libs/

PATH := /usr/bin:$(PATH)

STATLIBS=$(SFMLPATH)libsfml-all-s.a $(PROTOPATH)libprotobuf.a

# ldd libsfml-{window,graphics,network,system}.so | egrep -v "linux|sfml" | sed -r "s/^[^l]lib([^.]+).+/-l\1/g" | sort | uniq | tr "\n" " "
LDFLAGS=-lbz2 -lc -lcap -ldl -lfreetype -lgcc_s -lGL -lGLdispatch -lGLX -lgraphite2 -lharfbuzz -lICE -ljpeg -lm -lpcre -lpng16 -lpthread -lresolv -lrt -lSM -lstdc++ -ludev -luuid -lX11 -lXau -lxcb -lXdmcp -lXext -lXrandr -lXrender -lz 

SOURCES:= $(shell find $(SOURCEDIR) -name '*.cc')
OBJDIR=./build/obj
OBJ=$(SOURCES:.cc=.o)
OBJECTS=$(addprefix $(OBJDIR)/,$(SOURCES:.cc=.o))
EXECUTABLE=build/bin/main

all: buildDep objFolder copyResources $(SOURCES) $(EXECUTABLE)
	@echo Finish!!

$(EXECUTABLE): objFolder copyResources $(OBJ)
	@echo Build executable $@
	@$(CXX) $(LDFLAGS) $(OBJECTS) $(STATLIBS) -o $@

.cc.o:
	@echo Build object $@
	@$(CXX) $(CXXFLAGS) $< -o $(OBJDIR)/$@

objFolder:
	@echo Create folder
	for folder in $(shell ls -d src/*) ; do \
		mkdir -p $(OBJDIR)/$$folder ; \
	done

copyResources:
	@echo Copy resources
	mkdir -p build/bin/resources/
	cp -r resources build/bin/

buildDep:
	@echo Build dependencies
	./builddep.sh

image:
	docker build -t rpic .

ci_build: image
	docker run --rm -it -v ${PWD}:/rpic  sfml:latest

clean:
	rm -f $(shell find build/ -name '*.o')

distclean:
	rm -fr build
        #git ls-files --others | xargs rm -rf

test_server:
	$(CXX) -std=c++14 -I ./include/ -o build/bin/server_test test/server_test.cc src/network/CtlMessage.pb.cc -lm -lsfml-network -lprotobuf

run_test_server:
	@echo Run testserver
	./build/bin/server_test 4444

run:
	@echo Run executable
	./$(EXECUTABLE)

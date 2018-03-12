CC=g++
RM=rm

$(shell mkdir -p _build)

CFLAGS= -std=c++11 -Werror -Wall -Wfatal-errors -Wno-shift-count-overflow -Weffc++ -Wno-non-virtual-dtor -Wno-strict-aliasing -Wno-unused-private-field -O3 -pthread -lutil

all: _build/AT25SF081.so

_build/AT25SF081.o: AT25SF081.cpp
	$(CC) -fPIC -c -o $@ $^ $(CFLAGS) -I./include -I./modeling-framework/include

_build/AT25SF081.so: _build/AT25SF081.o modeling-framework/obj/ModelingFramework.o
	$(CC) -shared -o $@ $^

.PHONY: clean
clean:
	$(RM) -rf _build
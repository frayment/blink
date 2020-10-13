#
# Makefile
#
# Author       : Finn Rayment <finn@rayment.fr>
# Date created : 13/10/2020
#

VERSION=1.0
LIB:=libblink.a
PREFIX:=/usr/local

CC:=cc
CCFLAGS:=-O2 --std=c89 \
         -Wall -Wextra -Wpedantic -Werror --pedantic-errors \
         -DVERSION=\"${VERSION}\"

SOURCES:=$(wildcard src/*.c)
OBJECTS:=$(patsubst src/%,obj/%,$(patsubst %.c,%.o,$(SOURCES)))
HEADERS:=$(wildcard include/*.h)
INCLUDE:=-Iinclude/

all: dirs $(OBJECTS)
	ar -crv lib/$(LIB) $(OBJECTS)
	ranlib lib/$(LIB)

obj/%.o : src/%.c
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

dirs:
	mkdir -p lib obj

clean:
	rm -rf lib obj

test: all
	cd test && sh test.sh

dist:
	rm -rf blink-$(VERSION)
	mkdir -p blink-$(VERSION)
	cp -R COPYING README INSTALL Makefile src include blink-$(VERSION)
	tar -cJf blink-$(VERSION).tar.xz blink-$(VERSION)
	rm -rf blink-$(VERSION)

install: all
	mkdir -p $(PREFIX)/include/blink
	cp -f $(HEADERS) $(PREFIX)/include/blink
	for hdr in $(PREFIX)/include/blink/*.h; do chmod 644 $$hdr; done
	mkdir -p $(PREFIX)/lib
	cp -f lib/$(LIB) $(PREFIX)/lib
	chmod 755 $(PREFIX)/lib/$(LIB)

uninstall:
	rm -f $(PREFIX)/lib/$(LIB)
	rm -rf $(PREFIX)/include/blink

.PHONY: all dirs clean test dist install uninstall


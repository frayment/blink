#
# Makefile
#
# Author       : Finn Rayment <finn@rayment.fr>
# Date created : 13/10/2020
#

VERSION=1.0
LIB:=libblink.a
PREFIX:=/usr/local

# This variable lists all platforms to be included in the build.
# If you do not want to include a platform, remove it from the list and it will
# not be compiled into the resulting library and its header will not be
# installed if `make install` is run.
PLATFORMS:=mos6502 x86_64

CC:=cc
CCFLAGS:=-O2 --std=c89 \
         -Wall -Wextra -Wpedantic -Werror --pedantic-errors \
         -DVERSION=\"${VERSION}\"

SOURCES:=$(foreach platform,$(PLATFORMS),$(wildcard src/$(platform)*.c))
#SOURCES:=$(wildcard src/*.c)
OBJECTS:=$(patsubst src/%,obj/%,$(patsubst %.c,%.o,$(SOURCES)))
HEADERS:=$(patsubst %,include/%.h,$(PLATFORMS))
#HEADERS:=$(wildcard include/*.h)
INCLUDE:=-Iinclude/

all: dirs $(OBJECTS)
	rm -f lib/$(LIB)
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
	chmod 755 $(PREFIX)/include/blink
	mkdir -p $(PREFIX)/lib
	cp -f lib/$(LIB) $(PREFIX)/lib
	chmod 755 $(PREFIX)/lib/$(LIB)

uninstall:
	rm -f $(PREFIX)/lib/$(LIB)
	rm -rf $(PREFIX)/include/blink

.PHONY: all dirs clean test dist install uninstall


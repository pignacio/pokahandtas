#
# makefile
# ignacio, 2015-09-17 22:01
#

CC=clang
CFLAGS=-Wall

all: run

run: pokahandtas
	./pokahandtas

pokahandtas: card.o draw.o


# vim:ft=make
#

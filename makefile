#
# makefile
# ignacio, 2015-09-17 22:01
#


all: run

run: scons
	./build/debug/pokahandtas

scons:
	scons

clean:
	scons -c

.PHONY: all run scons clean

# vim:ft=make
#

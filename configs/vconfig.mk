CC := gcc
CCFLAGS=-m64 \
		-nostdlib \
		-fno-builtin \
		-fno-exceptions \
		-fno-leading-underscore \
		-Wno-write-strings \
		-fno-pie

ASM:= nasm
AFLAGS =-f bin

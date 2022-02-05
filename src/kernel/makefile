export

ifeq ($(KERNDIR),)
KERNDIR != pwd
endif

ifeq ($(KERNBUILDDIR),)
KERNBUILDDIR := $(BUILDDIR)/kernel
endif

ifeq ($(KERNOBJDIR),)
KERNOBJDIR := $(KERNBUILDDIR)/obj
endif

KERNOBJ=loader.o \
<<<<<<< HEAD
		drivers/graphics/font_char.o \
		drivers/graphics/vbe.o \
		drivers/graphics/svga.o \
=======
>>>>>>> 9c7c44bb5b78681a243eb6cea3cbf753c72bc496
		main.o

KOBJF = $(KERNOBJ:%=$(KERNOBJDIR)/%)

CCFLAGS += \
<<<<<<< HEAD
		-I$(SOLUTIONDIR)/include \
		-I$(SOLUTIONDIR)/include/kernel
CPPFLAGS= $(CCFLAGS) \
		-fno-rtti
=======
		-I$(SOLUTIONDIR)/include
>>>>>>> 9c7c44bb5b78681a243eb6cea3cbf753c72bc496
AFLAGS =-f elf32

.PHONY: all makekerndir clean
all: \
	makekerndir \
	kernel.bin

makekerndir:
<<<<<<< HEAD
	@$(MKDIR) $(KERNOBJDIR)/common
	@$(MKDIR) $(KERNOBJDIR)/drivers/graphics
=======
	@$(MKDIR) $(KERNOBJDIR)
>>>>>>> 9c7c44bb5b78681a243eb6cea3cbf753c72bc496

%.o: %.asm
	@$(ECHO) "  ASM   " $(KERNOBJDIR)/$@
	@$(ASM) $< $(AFLAGS) -o $(KERNOBJDIR)/$@
%.o: %.c
	@$(ECHO) "  CC    " $(KERNOBJDIR)/$@
	@$(CC) $(CCFLAGS) -c -o $(KERNOBJDIR)/$@ $<
%.o: %.cpp
	@$(ECHO) "  CPP   " $(KERNOBJDIR)/$@
<<<<<<< HEAD
	@$(CC) $(CPPFLAGS) -c -o $(KERNOBJDIR)/$@ $<
=======
	@$(CC) $(CCFLAGS) -c -o $(KERNOBJDIR)/$@ $<
>>>>>>> 9c7c44bb5b78681a243eb6cea3cbf753c72bc496

kernel.bin: linker.ld $(KERNOBJ)
	@$(ECHO) "  LD    " $(KERNBUILDDIR)/$@
	@ld -m elf_i386 -T$< --oformat binary -o $(KERNBUILDDIR)/$@ $(KOBJF)
	@size=$$(stat -L -c %s $(KERNBUILDDIR)/$@);\
	newsize=$$(expr $$size - $$(expr $$size % 512) + 512);\
	echo "$@" "$$size ($$(printf '0x%02X' $$(expr $$size / 512)) sectors) ->" "$$newsize ($$(printf '0x%02X' $$(expr $$newsize / 512)) sectors)";\
	dd if=/dev/zero of=$(KERNBUILDDIR)/$@ bs=1 seek=$$size count=$$(expr $$newsize - $$size)

clean:
	@rm -r $(KERNBUILDDIR) || true

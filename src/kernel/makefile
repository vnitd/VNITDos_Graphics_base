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

KERNOBJ=main.o

KOBJF = $(KERNOBJ:%=$(KERNOBJDIR)/%)

CCFLAGS += \
		-I$(SOLUTIONDIR)/include

.PHONY: all makekerndir clean
all: \
	makekerndir \
	kernel.bin

makekerndir:
	@$(MKDIR) $(KERNOBJDIR)

%.o: %.asm
	@$(ECHO) "  ASM   " $(KERNOBJDIR)/$@
	@$(ASM) $< $(AFLAGS) -o $(KERNOBJDIR)/$@
%.o: %.c
	@$(ECHO) "  CC    " $(KERNOBJDIR)/$@
	@$(CC) $(CCFLAGS) -c -o $(KERNOBJDIR)/$@ $<

kernel.bin: linker.ld $(KERNOBJ)
	@$(ECHO) "  LD    " $(KERNBUILDDIR)/$@
	@ld -m elf_i386 -T$< --oformat binary -o $(KERNBUILDDIR)/$@ $(KOBJF)
	@size=$$(stat -L -c %s $(KERNBUILDDIR)/$@);\
	newsize=$$(expr $$size - $$(expr $$size % 512) + 512);\
	echo "$@" "$$size ($$(printf '0x%02X' $$(expr $$size / 512)) sectors) ->" "$$newsize ($$(printf '0x%02X' $$(expr $$newsize / 512)) sectors)";\
	dd if=/dev/zero of=$(KERNBUILDDIR)/$@ bs=1 seek=$$size count=$$(expr $$newsize - $$size)

clean:
	@rm -r $(KERNBUILDDIR)

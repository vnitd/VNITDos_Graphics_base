export

ifeq ($(SOLUTIONDIR),)
SOLUTIONDIR != pwd
endif

ifeq ($(SOURCEDIR),)
SOURCEDIR = $(SOLUTIONDIR)/src
endif

ifeq ($(BUILDDIR),)
BUILDDIR = $(SOLUTIONDIR)/build
endif

ifeq ($(CONFIG),)
CONFIG := vconfig
endif

include $(SOLUTIONDIR)/configs/$(CONFIG).mk

ifeq ($(VERSION),)
VERSION=0.0.1
endif

ifeq ($(CP),)
CP=cp
endif

ifeq ($(MKDIR),)
MKDIR=mkdir -p
endif

ifeq ($(ECHO),)
ECHO=echo
endif

ifeq ($(LN),)
LN=ln
endif

ifeq ($(BOOTDIR),)
BOOTDIR=$(SOURCEDIR)/boot
endif

ifeq ($(KERNDIR),)
KERNDIR=$(SOURCEDIR)/kernel
endif

MAKEFLAGS += --no-print-directory

include $(SOLUTIONDIR)/configs/binfile.mk

OS_VERSION=0.1
OS_NAME=Base
OS_FILE_NAME=VNITDos-$(OS_NAME)_v$(OS_VERSION)
OS_IMG_FILE=$(SOLUTIONDIR)/$(OS_FILE_NAME).img

.PHONY: all clean
all: \
	clean \
	run
clean: \
	clean-all

.PHONY: build-all clean-all
build-all: \
	build-boot \
	build-kernel
clean-all: \
	clean-boot \
	clean-kernel
	@rm -r $(BUILDDIR) || true

#
# boot target
#
.PHONY: build-boot clean-boot
build-boot:
	@$(ECHO) "  MK    " $(BOOTDIR)
	@$(MAKE) -C $(BOOTDIR)
clean-boot:
	@$(MAKE) -C $(BOOTDIR) clean

#
# kernel target
#
.PHONY: build-kernel clean-kernel
build-kernel:
	@$(ECHO) "  MK    " $(KERNDIR)
	@$(MAKE) -C $(KERNDIR)
clean-kernel:
	@$(MAKE) -C $(KERNDIR) clean

#
# IMG Target
#
$(OS_IMG_FILE): build-all
	@$(ECHO) "  IMG   " $(OS_IMG_FILE)
	@cat $(BINFILE) > $(BUILDDIR)/tmp.bin
	@dd if=/dev/zero of=$@ bs=512 count=2880
	@dd if=$(BUILDDIR)/tmp.bin of=$@ conv=notrunc

run: $(OS_IMG_FILE)
	@qemu-system-i386 -drive format=raw,file=$<,if=ide,index=0,media=disk

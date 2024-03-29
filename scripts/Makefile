# SPDX-License-Identifier: GPL-2.0
###
# scripts contains sources for various helper programs used throughout
# the kernel for the build process.
# ---------------------------------------------------------------------------
# kallsyms:      Find all symbols in vmlinux
# pnmttologo:    Convert pnm files to logo files
# conmakehash:   Create chartable
# conmakehash:	 Create arrays for initializing the kernel console tables
# kmodsdt:       Post-process module .o files for SDT probes

HOST_EXTRACFLAGS += -I$(srctree)/tools/include

hostprogs-$(CONFIG_BUILD_BIN2C)  += bin2c
hostprogs-$(CONFIG_KALLSYMS)     += kallsyms
hostprogs-$(CONFIG_LOGO)         += pnmtologo
hostprogs-$(CONFIG_VT)           += conmakehash
hostprogs-$(BUILD_C_RECORDMCOUNT) += recordmcount
hostprogs-$(CONFIG_BUILDTIME_EXTABLE_SORT) += sortextable
hostprogs-$(CONFIG_ASN1)	 += asn1_compiler
hostprogs-$(CONFIG_MODULE_SIG)	 += sign-file
hostprogs-$(CONFIG_SYSTEM_TRUSTED_KEYRING) += extract-cert
hostprogs-$(CONFIG_SYSTEM_EXTRA_CERTIFICATE) += insert-sys-cert
hostprogs-$(CONFIG_DTRACE)	 += kmodsdt

HOSTCFLAGS_sortextable.o = -I$(srctree)/tools/include
HOSTCFLAGS_asn1_compiler.o = -I$(srctree)/include
HOSTLDLIBS_sign-file = -lcrypto
HOSTLDLIBS_extract-cert = -lcrypto

always		:= $(hostprogs-y) $(hostprogs-m)

kallsyms-objs   := kallsyms.o

ifeq ($(CONFIG_KALLMODSYMS),y)
kallsyms-objs   += eu_simple.o

HOSTCFLAGS_eu_simple.o := -I$(srctree)/scripts
HOSTCFLAGS_kallsyms.o := $(shell pkg-config --cflags glib-2.0) -I$(srctree)/scripts
HOSTLDLIBS_kallsyms := $(shell pkg-config --libs glib-2.0) -ldw
endif

ifeq ($(CONFIG_DTRACE),y)
HOSTCFLAGS_kmodsdt.o := -I$(srctree)/include/generated
HOSTLDLIBS_kmodsdt := -lelf
endif

# The following hostprogs-y programs are only build on demand
hostprogs-y += unifdef

# These targets are used internally to avoid "is up to date" messages
PHONY += build_unifdef
build_unifdef: $(obj)/unifdef
	@:

subdir-$(CONFIG_MODVERSIONS) += genksyms
subdir-y                     += mod
subdir-$(CONFIG_CTF)         += dwarf2ctf
subdir-$(CONFIG_SECURITY_SELINUX) += selinux
subdir-$(CONFIG_DTC)         += dtc
subdir-$(CONFIG_GDB_SCRIPTS) += gdb

# Let clean descend into subdirs
subdir-	+= basic kconfig package gcc-plugins

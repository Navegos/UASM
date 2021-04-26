
# This makefile creates the UASM Elf binary for Linux/FreeBSD.

ifndef DEBUG
DEBUG=0
endif

ifndef INSTR
INSTR=0
endif

ifeq ($(DEBUG),0)
TARGET1=uasm
else
TARGET1=uasmd
endif

inc_dirs  = -IH

#cflags stuff

warning_c_flags = -Wno-sign-conversion -Wno-implicit-int-conversion -Wno-comment -Wno-switch -Wno-implicit-function-declaration -Wno-enum-conversion -Wformat -Werror=format-security -Wdate-time

ifeq ($(INSTR),0)
instr_c_flags = -march=x86-64-2 -msse2
endif

ifeq ($(INSTR),1)
instr_c_flags = -march=x86-64-v3 -mavx
endif

ifeq ($(INSTR),2)
instr_c_flags = -march=x86-64-v3 -mavx2
endif

ifeq ($(INSTR),3)
instr_c_flags = -march=x86-64-v4 -mavx512f
endif

ifeq ($(DEBUG),0)
extra_c_flags = $(warning_c_flags) -O3 -finline-functions -std=gnu17 -march=x86-64 -mabi=sysv -target x86_64-pc-linux-gnu -DNDEBUG -funsigned-char -fwritable-strings -fPIC -fPIE -fstack-protector-strong -mstack-alignment=16 -D_FORTIFY_SOURCE=2
OUTD=GccUnixR
else
extra_c_flags = $(warning_c_flags) -g -O0 -std=gnu17 -march=x86-64 -mabi=sysv -target x86_64-pc-linux-gnu -D_DEBUG -DDEBUG_OUT -funsigned-char -fwritable-strings -fPIC -fPIE -fstack-protector-strong -mstack-alignment=16 -D_FORTIFY_SOURCE=2
OUTD=GccUnixD
endif

c_flags = -DMACROLIB=1 -D__unix__ -D__linux__ $(extra_c_flags)

CC = clang

.SUFFIXES:
.SUFFIXES: .c .o

include gccmod.inc

#.c.o:
#	$(CC) -c $(inc_dirs) $(c_flags) -o $(OUTD)/$*.o $<
$(OUTD)/%.o: %.c
	$(CC) -D __unix__ -c $(inc_dirs) $(c_flags) $(CFLAGS) $(CPPFLAGS) -o $(OUTD)/$*.o $<

all:  $(OUTD) $(OUTD)/$(TARGET1)

$(OUTD):
	mkdir $(OUTD)

$(OUTD)/$(TARGET1) : $(OUTD)/main.o $(proj_obj)
ifeq ($(DEBUG),0)
	$(CC) -D __unix__ $(CFLAGS) $(OUTD)/main.o $(proj_obj) -Wl,-Bsymbolic-functions -fPIC -fPIE -pie -Wl,-z,relro -Wl,-z,now -s -o $@ -Wl,-Map,$(OUTD)/$(TARGET1).map $(LDFLAGS)
else
	$(CC) -D __unix__ $(CFLAGS) $(OUTD)/main.o $(proj_obj) -Wl,-Bsymbolic-functions -fPIC -fPIE -pie -Wl,-z,relro -Wl,-z,now -o $@ -Wl,-Map,$(OUTD)/$(TARGET1).map $(LDFLAGS)
endif

$(OUTD)/msgtext.o: msgtext.c H/msgdef.h
	$(CC) -D __unix__ -c $(inc_dirs) $(c_flags) $(CFLAGS) $(CPPFLAGS) -o $*.o msgtext.c

$(OUTD)/reswords.o: reswords.c H/instruct.h H/special.h H/directve.h H/opndcls.h H/instravx.h
	$(CC) -D __unix__ -c $(inc_dirs) $(c_flags) $(CFLAGS) $(CPPFLAGS) -o $*.o reswords.c

######

clean:
	rm $(OUTD)/$(TARGET1)
	rm $(OUTD)/*.o
	rm $(OUTD)/*.map

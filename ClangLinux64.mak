
# This makefile creates the UASM Elf binary for Linux/FreeBSD.

TARGET1=uasm

ifndef DEBUG
DEBUG=0
endif

inc_dirs  = -IH

#cflags stuff

ifeq ($(DEBUG),0)
extra_c_flags = -O3 -std=c11 -march=x86-64 -target x86_64-pc-linux-gnu -DNDEBUG -funsigned-char -fwritable-strings
OUTD=GccUnixR
else
extra_c_flags = -g -O0 -std=c11 -march=x86-64 -target x86_64-pc-linux-gnu -D_DEBUG -DDEBUG_OUT -funsigned-char -fwritable-strings
OUTD=GccUnixD
endif

c_flags = -DMACROLIB=1 -D__UNIX__ -D__LINUX__ $(extra_c_flags)

CC = clang

.SUFFIXES:
.SUFFIXES: .c .o

include gccmod.inc

#.c.o:
#	$(CC) -c $(inc_dirs) $(c_flags) -o $(OUTD)/$*.o $<
$(OUTD)/%.o: %.c
	$(CC) -D __UNIX__ -c $(inc_dirs) $(c_flags) -o $(OUTD)/$*.o $<

all:  $(OUTD) $(OUTD)/$(TARGET1)

$(OUTD):
	mkdir $(OUTD)

$(OUTD)/$(TARGET1) : $(OUTD)/main.o $(proj_obj)
ifeq ($(DEBUG),0)
	$(CC) -D __UNIX__ $(OUTD)/main.o $(proj_obj) -s -o $@ -Wl,-Map,$(OUTD)/$(TARGET1).map
else
	$(CC) -D __UNIX__ $(OUTD)/main.o $(proj_obj) -o $@ -Wl,-Map,$(OUTD)/$(TARGET1).map
endif

$(OUTD)/msgtext.o: msgtext.c H/msgdef.h
	$(CC) -D __UNIX__ -c $(inc_dirs) $(c_flags) -o $*.o msgtext.c

$(OUTD)/reswords.o: reswords.c H/instruct.h H/special.h H/directve.h H/opndcls.h H/instravx.h
	$(CC) -D __UNIX__ -c $(inc_dirs) $(c_flags) -o $*.o reswords.c

######

clean:
	rm $(OUTD)/$(TARGET1)
	rm $(OUTD)/*.o
	rm $(OUTD)/*.map


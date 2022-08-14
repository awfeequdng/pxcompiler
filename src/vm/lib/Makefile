
include Make.inc

SRCS = hashing.c timefuncs.c dblprint.c ptrhash.c operators.c \
	utf8.c htable.c bitvector.c \
	int2str.c arraylist.c

OBJS = $(SRCS:%.c=%.o)
DOBJS = $(SRCS:%.c=%.do)

ifneq ($(MAKECMDGOALS),debug)
XOBJS = $(OBJS)
else
XOBJS = $(DOBJS)
endif

FLAGS = -Wall -Wno-strict-aliasing $(CFLAGS) $(HFILEDIRS:%=-I%) -fvisibility=hidden

DEBUGFLAGS += $(FLAGS)
SHIPFLAGS += $(FLAGS)

default: release

HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(SHIPFLAGS) -c $< -o $@
%.do: %.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(DEBUGFLAGS) -c $< -o $@

release debug: libsupport.a

libsupport.a: $(XOBJS)
	rm -rf $@
	$(AR) -rcs $@ $^

clean:
	rm -f *.o
	rm -f *.do
	rm -f *.a
	rm -f *~ *#
	rm -f core*
	rm -f libsupport.a

include Make.inc

SRCS = gc.c init.c main.c alloc.c task.c sys.c pltypes.c module.c
OBJS = $(SRCS:%.c=%.o)

default: vm_main

HEADERS = $(wildcard *.h)
CPPFLAGS += -Wall

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -Ilib -c $^ -o $@

vm_main: $(OBJS)
	rm -rf $@
	$(CC) $^ -o $@  -Llib -lsupport

clean:
	rm -f *.o
	rm -f vm_main
	rm -f *~ *#
	rm -f core*

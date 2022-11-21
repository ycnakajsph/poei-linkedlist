CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
DEBUG_FLAGS += -g
CFILES = linked_list.c double_linked_list.c

all:
	$(CC) $(LDFLAGS) -o linked_list $(CFLAGS) $(CFILES) main.c

test_ll_debug:
	$(CC) $(LDFLAGS)  -o debug_linked_list_tests $(CFLAGS) $(DEBUG_FLAGS) tests/test_main.c $(CFILES) -lcunit

test_d_ll_debug:
	$(CC) $(LDFLAGS)  -o debug_d_ll_tests $(CFLAGS) $(DEBUG_FLAGS) tests/test_d_ll_main.c $(CFILES) -lcunit

clean:
	rm -f *.o linked_list_tests linked_list

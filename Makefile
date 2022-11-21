CC ?= gcc
CFLAGS += -Wall --pedantic -Werror
DEBUG_FLAGS += -g

all:
	$(CC) $(LDFLAGS) -o linked_list $(CFLAGS) linked_list.c main.c

test:
	$(CC) $(LDFLAGS)  -o linked_list_tests $(CFLAGS) tests/test_main.c linked_list.c -lcunit

test_debug:
	$(CC) $(LDFLAGS)  -o debug_linked_list_tests $(CFLAGS) $(DEBUG_FLAGS) tests/test_main.c linked_list.c -lcunit

clean:
	rm -f *.o linked_list_tests linked_list

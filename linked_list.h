#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

typedef struct linked_list{
	int data;
	struct linked_list* next;
} linked_list;

linked_list* get_new_elem(int data);

#endif
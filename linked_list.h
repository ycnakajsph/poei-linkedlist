#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

typedef struct linked_list{
	int data;
	struct linked_list* next;
} linked_list;

linked_list* ll_get_new_elem(int data);
void ll_push_elem(linked_list* list, linked_list* elem);
void ll_pop(linked_list* list);
void ll_free(linked_list* list);

#endif
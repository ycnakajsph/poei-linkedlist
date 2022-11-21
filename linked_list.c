#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

linked_list* get_new_elem(int data){
	linked_list* new_elem = (linked_list*) malloc(sizeof(linked_list));

	new_elem->data = data;
	new_elem->next = NULL;

	return new_elem;
}

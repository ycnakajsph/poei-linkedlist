#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

linked_list* ll_get_new_elem(int data){
	linked_list* new_elem = (linked_list*) malloc(sizeof(linked_list));

	new_elem->data = data;
	new_elem->next = NULL;

	return new_elem;
}

void ll_push_elem(linked_list* list, linked_list* elem){
	linked_list* pt = list;

	while(pt->next != NULL){
		pt = pt->next;
	}

	pt->next = elem;

}

void ll_pop(linked_list* list){
	linked_list* pt = list;
	linked_list* prev = NULL;
	int i = 0;

	if(pt->next == NULL){
		printf("ain't not poping!\n");
		return;
	}

	while(pt->next != NULL){
		i++;
		prev = pt;
		pt = pt->next;
	}

	prev->next = NULL;
	free(pt);
}
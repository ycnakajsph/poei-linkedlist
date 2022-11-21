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
		printf("ain't no poping!\n");
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

void ll_free(linked_list* list){
	linked_list* pt = list;
	linked_list* pt_prev;

	while (pt != NULL){
		pt_prev = pt;
		pt = pt->next;
		free(pt_prev);
	}
}

int ll_length(linked_list* list){
	linked_list* pt = list;
	int len = 0;

	while (pt != NULL){
		pt = pt->next;
		len++;
	}

	return len;
}
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

double_linked_list* d_ll_get_new_elem(int data){
	double_linked_list* new_elem = (double_linked_list*) malloc(sizeof(double_linked_list));

	new_elem->data = data;
	new_elem->next = NULL;
	new_elem->prev = NULL;

	return new_elem;
}


void d_ll_push_elem(double_linked_list* list, double_linked_list* elem){
	double_linked_list* pt = list;

	while(pt->next != NULL){
		pt = pt->next;
	}

	pt->next = elem;
	elem->prev = pt;

}

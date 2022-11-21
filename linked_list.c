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

void ll_print(linked_list* list){
	linked_list* pt;
	pt = list;

	while (pt != NULL){
		printf("[%d]->",pt->data);
		pt = pt->next;
	}
	printf("\n");
}

void ll_add_index(linked_list** list,int index,linked_list* elem){
	linked_list* pt = *list;
	linked_list* tmp;
	int id = 0;
	int len;

	if(index == 0){ // in case we want to replace the first elem
		elem->next = *list;
		*list = elem;
		return;
	}

	len = ll_length(*list);

	while (pt != NULL && id != index - 1 && id < len-1){
		pt = pt->next;
		id++;
	}

	tmp = pt->next;
	pt->next = elem;
	elem->next = tmp;
}

linked_list* ll_elem_at_index(linked_list* list, int index){
	linked_list* pt = list;
	int id = 0;
	int len;

	len = ll_length(list);

	while (pt != NULL && id != index && id < len-1){
		pt = pt->next;
		id++;
	}

	return pt;
}

void ll_swap_index_general(linked_list* list, int index0, int index1){

	linked_list* elem0;
	linked_list* elem0_prev;
	linked_list* elem1;
	linked_list* elem1_prev;
	linked_list* elem1_next;


	elem0_prev = ll_elem_at_index(list,index0-1);
	elem0 = elem0_prev->next;

	elem1_prev = ll_elem_at_index(list,index1-1);
	elem1 = elem1_prev->next;

	elem1_next = elem1->next;

	elem0_prev->next = elem1;
	elem1->next = elem0->next;

	elem1_prev->next = elem0;
	elem0->next = elem1_next;

}

void ll_swap_index_glued(linked_list* list, int index0, int index1){

	linked_list* elem0;
	linked_list* elem0_prev;
	linked_list* elem1;
	linked_list* elem1_next;

	elem0_prev = ll_elem_at_index(list,index0-1);
	elem0 = elem0_prev->next;

	elem1 = ll_elem_at_index(list,index1);
	elem1_next = elem1->next;

	elem0_prev->next = elem1;
	elem1->next = elem0;
	elem0->next = elem1_next;

	/*
	elem0_prec elem0 elem1 elem1_next
	elem0_prec elem1 elem0 elem1_next
	*/

}

void ll_swap_head_headp1(linked_list** list){
	linked_list* elem0;
	linked_list* elem1;
	linked_list* elem1_next;

	elem0 = *list;
	elem1 = ll_elem_at_index(*list,1);
	elem1_next = elem1->next;

	elem1->next = elem0;
	elem0->next = elem1_next;

	*list = elem1;

	/*
	elem0 elem1 elem1_next
	elem1 elem0 elem1_next
	*/
}

void ll_swap_index_head(linked_list** list, int index0, int index1){

	linked_list* elem0;
	linked_list* elem0_next;
	linked_list* elem1;
	linked_list* elem1_next;
	linked_list* elem1_prev;

	if(index0+1 == index1){
		ll_swap_head_headp1(list);
		return;
	}

	elem0 = *list;
	elem0_next = elem0->next;

	elem1_prev = ll_elem_at_index(*list,index1-1);
	elem1 = elem1_prev->next;
	elem1_next = elem1->next;

	elem1->next = elem0_next;
	*list = elem1;

	elem1_prev->next = elem0;
	elem0->next = elem1_next;

	/*
	elem0 elem0_next elem1_prev elem1 elem1_next
	elem1 elem0_next elem1_prev elem0 elem1_next
	*/

}

void ll_swap_index(linked_list** list, int index0, int index1){
	/*linked_list* pt = *list;*/

	if(index0 > index1){ // we want index0 < index1
		int tmp;
		tmp = index1;
		index1 = index0;
		index0 = tmp;
	}

	if(index0 == 0){
		ll_swap_index_head(list,index0,index1);
	}
	else if(index1 == index0+1){
		ll_swap_index_glued(*list,index0,index1);
	}
	else{ // general case
		ll_swap_index_general(*list, index0, index1);
	}

}
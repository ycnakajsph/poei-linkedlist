#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../linked_list.h"

void test_d_ll_get_new_elem(){
	
	double_linked_list* elem = d_ll_get_new_elem(12);

	CU_ASSERT( elem->data == 12);
	CU_ASSERT( elem->next == NULL);
	CU_ASSERT( elem->prev == NULL);

	free(elem);
}

void test_d_ll_push_elem(){
	
	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);
	double_linked_list* pt = HEAD;

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);

	CU_ASSERT( pt->data == 11);
	CU_ASSERT( pt->next == elem0);
	CU_ASSERT( pt->prev == NULL);
	pt = pt->next;
	CU_ASSERT( pt->data == 12);
	CU_ASSERT( pt->next == elem1);
	CU_ASSERT( pt->prev == HEAD);
	pt = pt->next;
	CU_ASSERT( pt->data == 13);
	CU_ASSERT( pt->next == NULL);
	CU_ASSERT( pt->prev == elem0);

	free(elem0);
	free(elem1);
	free(HEAD);
}


void test_d_ll_pop(){

	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);

	d_ll_pop(HEAD);

	CU_ASSERT(elem0->next == NULL);
	CU_ASSERT(elem0->prev == HEAD);
	CU_ASSERT(HEAD->next == elem0);
	CU_ASSERT(HEAD->prev == NULL);

	free(elem0);
	free(HEAD);
}

void test_d_ll_free(){

	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);

	d_ll_free(HEAD); // Usefull only with valgrind

}

void test_d_ll_add_index_0(){

	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* init_HEAD = HEAD;
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);
	double_linked_list* elem2 = d_ll_get_new_elem(14);
	double_linked_list* elem_add = d_ll_get_new_elem(100);

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);
	d_ll_push_elem(HEAD,elem2);

	/*d_ll_print(HEAD);*/
	d_ll_add_index(&HEAD,0,elem_add);
	/*d_ll_print(HEAD);*/

	CU_ASSERT(HEAD == elem_add);
	CU_ASSERT(HEAD->prev == NULL);
	CU_ASSERT(HEAD->next == init_HEAD);

	d_ll_free(HEAD);

}

void test_d_ll_add_index(){

	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);
	double_linked_list* elem2 = d_ll_get_new_elem(14);
	double_linked_list* elem_add = d_ll_get_new_elem(100);

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);
	d_ll_push_elem(HEAD,elem2);

	/*d_ll_print(HEAD);*/
	d_ll_add_index(&HEAD,2,elem_add);
	/*d_ll_print(HEAD);*/

	CU_ASSERT(elem0->next == elem_add);
	CU_ASSERT(elem_add->prev == elem0);
	CU_ASSERT(elem_add->next == elem1);
	CU_ASSERT(elem1->prev == elem_add);

	d_ll_free(HEAD); // Usefull only with valgrind

}

void test_d_ll_add_index_last(){

	double_linked_list* HEAD = d_ll_get_new_elem(11);
	double_linked_list* elem0 = d_ll_get_new_elem(12);
	double_linked_list* elem1 = d_ll_get_new_elem(13);
	double_linked_list* elem2 = d_ll_get_new_elem(14);
	double_linked_list* elem_add = d_ll_get_new_elem(100);

	d_ll_push_elem(HEAD,elem0);
	d_ll_push_elem(HEAD,elem1);
	d_ll_push_elem(HEAD,elem2);

	/*d_ll_print(HEAD);*/
	d_ll_add_index(&HEAD,4,elem_add); // >= len
	/*d_ll_print(HEAD);*/

	CU_ASSERT(elem2->next == elem_add);
	CU_ASSERT(elem_add->next == NULL);
	CU_ASSERT(elem_add->prev == elem2);

	d_ll_free(HEAD); // Usefull only with valgrind

}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main()
{
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if (
		NULL == CU_add_test(pSuite, "test_d_ll_get_new_elem()", test_d_ll_get_new_elem) ||
		NULL == CU_add_test(pSuite, "test_d_ll_push_elem()", test_d_ll_push_elem)||
		NULL == CU_add_test(pSuite, "test_d_ll_pop()", test_d_ll_pop)||
		NULL == CU_add_test(pSuite, "test_d_ll_free()", test_d_ll_free)||
		NULL == CU_add_test(pSuite, "test_d_ll_add_index_0()", test_d_ll_add_index_0)||
		NULL == CU_add_test(pSuite, "test_d_ll_add_index()", test_d_ll_add_index)||
		NULL == CU_add_test(pSuite, "test_d_ll_add_index_last()", test_d_ll_add_index_last)
	)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

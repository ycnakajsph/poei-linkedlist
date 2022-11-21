#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../linked_list.h"

void test_ll_get_new_elem(){
	
	linked_list* elem = ll_get_new_elem(12);

	CU_ASSERT( elem->data == 12);
	CU_ASSERT( elem->next == NULL);

	free(elem);
}

void test_ll_push_elem(){
	
	linked_list* HEAD = ll_get_new_elem(11);
	linked_list* elem0 = ll_get_new_elem(12);
	linked_list* elem1 = ll_get_new_elem(13);
	linked_list* pt = HEAD;

	ll_push_elem(HEAD,elem0);
	ll_push_elem(HEAD,elem1);

	CU_ASSERT( pt->data == 11);
	CU_ASSERT( pt->next == elem0);
	pt = pt->next;
	CU_ASSERT( pt->data == 12);
	CU_ASSERT( pt->next == elem1);
	pt = pt->next;
	CU_ASSERT( pt->data == 13);
	CU_ASSERT( pt->next == NULL);

	free(elem0);
	free(elem1);
	free(HEAD);
}

void test_ll_pop(){
	
	linked_list* HEAD = ll_get_new_elem(11);
	linked_list* elem0 = ll_get_new_elem(12);
	linked_list* elem1 = ll_get_new_elem(13);

	ll_push_elem(HEAD,elem0);
	ll_push_elem(HEAD,elem1);

	ll_pop(HEAD);

	CU_ASSERT(elem0->next == NULL);
	CU_ASSERT(HEAD->next == elem0);

	free(elem0);
	free(HEAD);
}

void test_ll_pop_empty(){
	
	linked_list* HEAD = ll_get_new_elem(11);

	ll_pop(HEAD);

	CU_ASSERT(HEAD->next == NULL);

	free(HEAD);
}

void test_ll_free(){

	linked_list* HEAD = ll_get_new_elem(11);
	linked_list* elem0 = ll_get_new_elem(12);
	linked_list* elem1 = ll_get_new_elem(13);

	ll_push_elem(HEAD,elem0);
	ll_push_elem(HEAD,elem1);

	ll_free(HEAD); // Usefull only with valgrind

}

void test_ll_length(){

	linked_list* HEAD = ll_get_new_elem(11);
	linked_list* elem0 = ll_get_new_elem(12);
	linked_list* elem1 = ll_get_new_elem(13);

	ll_push_elem(HEAD,elem0);
	ll_push_elem(HEAD,elem1);

	CU_ASSERT(ll_length(HEAD) == 3);
	CU_ASSERT(ll_length(elem0) == 2);
	CU_ASSERT(ll_length(elem1) == 1);

	ll_free(HEAD);

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
		NULL == CU_add_test(pSuite, "test_ll_get_new_elem()", test_ll_get_new_elem) ||
		NULL == CU_add_test(pSuite, "test_ll_push_elem()", test_ll_push_elem)||
		NULL == CU_add_test(pSuite, "test_ll_pop()", test_ll_pop)||
		NULL == CU_add_test(pSuite, "test_ll_pop_empty()", test_ll_pop_empty)||
		NULL == CU_add_test(pSuite, "test_ll_free()", test_ll_free)||
		NULL == CU_add_test(pSuite, "test_ll_length()", test_ll_length)
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

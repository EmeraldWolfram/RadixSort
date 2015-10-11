#include "unity.h"
#include "Sort.h"
#include "LinkedList.h"
#include "GetNumberOfDigits.h"
#include <stdlib.h>
#include <math.h>

void setUp(void){}

void tearDown(void){}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * -----------------------
 *  *********                        \
 *  * head  * \       *******        ******
 *  *********   ----> * 0x1 * -----> *0x0 *
 *                    *******        ******
 *  
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * -----------------------
 *  *********                        \
 *  * head  * \       *******        *******
 *  *********   ----> * 0x0 * -----> * 0x1 *
 *                    *******        *******
 *
 *  THIS TEST USE TO CHECK IF sortList CAN SWAP TWO SINGLE DIGIT NUMBER 
 */
void test_sortList_given_1_0_should_return_0_1(void){
	LinkedList* testList  = createLinkedList();

  addListLast(testList, createListElement(0x1)); 
  addListLast(testList, createListElement(0x0));
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, ASCENDING_BIN_NUMBER);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x0, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x1, sortedList->tail->value);
}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * --------------------------------------------------------------------
 *  *********                                                                      \
 *  * head  * \       *******        ******        *******        *******        *******
 *  *********   ----> * 0x3 * -----> *0x9 * -----> * 0x6 * -----> * 0x2 * -----> * 0x4 *
 *                    *******        ******        *******        *******        *******
 *
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * --------------------------------------------------------------------
 *  *********                                                                      \
 *  * head  * \       *******        ******        *******        *******        *******
 *  *********   ----> * 0x2 * -----> *0x3 * -----> * 0x4 * -----> * 0x6 * -----> * 0x9 *
 *                    *******        ******        *******        *******        *******
 *
 *  THIS TEST USE TO CHECK IF sortList CAN HANDLE 5 SINGLE DIGIT 
 */
void test_sortList_given_3_9_6_2_4_should_return_2_3_4_6_9(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x3)); 
  addListLast(testList, createListElement(0x9)); 
  addListLast(testList, createListElement(0x6)); 
  addListLast(testList, createListElement(0x2)); 
  addListLast(testList, createListElement(0x4)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, ASCENDING_BIN_NUMBER);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x2, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x3, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x4, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(0x6, sortedList->head->next->next->next->value);
  TEST_ASSERT_EQUAL(0x9, sortedList->tail->value);
}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ******        *******
 *  *********   ----> * 0x7E* -----> *0x02* -----> * 0x0E*
 *                    *******        ******        *******
 *  
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ******        *******
 *  *********   ----> * 0x02* -----> *0x0E* -----> * 0x7E*
 *                    *******        ******        *******
 * 
 *  THIS TEST USE TO CHECK IF sortList CAN HANDLE INPUT LIST WITH DIFFERENT IN DIGIT
 */
void test_sortList_given_0x7E_0x2_0xE_should_return_0x2_0xE_0x7E(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x7E)); 
  addListLast(testList, createListElement(0x02)); 
  addListLast(testList, createListElement(0x0E)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, ASCENDING_BIN_NUMBER);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x02, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x0E, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x7E, sortedList->tail->value);
}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * -------------------------------------------------------
 *  *********                                                        \
 *  * head  * \       *******        *******        *******        *******
 *  *********   ----> * 0x56* -----> *0x316* -----> *0x3A6* -----> * 0x06*
 *                    *******        *******        *******        *******
 *
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * -------------------------------------------------------
 *  *********                                                        \
 *  * head  * \       *******        *******        *******        *******
 *  *********   ----> * 0x06* -----> *0x316* -----> *0x56 * -----> *0x3A6*
 *                    *******        *******        *******        *******
 *
 *  THIS TEST USE TO CHECK IF sortList CAN HANDLE 4 NUMBER INSIDE SAME BIN
 */
void test_sortList_given_0x56_0x316_0x3A6_0x06_should_return_0x6_0x56_0x316_0x3A6(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x56)); 
  addListLast(testList, createListElement(0x316)); 
  addListLast(testList, createListElement(0x3A6)); 
  addListLast(testList, createListElement(0x06)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, ASCENDING_BIN_NUMBER);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x06, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x56, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x316, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(0x3A6, sortedList->tail->value);
}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ********        *******
 *  *********   ----> * 0x00* -----> *0x1000* -----> *0x100*
 *                    *******        ********        *******
 *
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       ********        ********        *******
 *  *********   ----> *0x1000* -----> *0x100 * -----> *0x00 *
 *                    ********        ********        *******
 *
 *  THIS TEST USE TO CHECK IF sortList CAN SORT IN DESCENDING ORDER
 */
void test_sortList_0x0_0x1000_0x100_should_return_0x1000_0x100_0x00(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x00)); 
  addListLast(testList, createListElement(0x1000)); 
  addListLast(testList, createListElement(0x100)); 

  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, DESCENDING_BIN_NUMBER);
  
  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x1000, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x100, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x00, sortedList->tail->value);
}

/**
 *  sortList function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ********        *******
 *  *********   ----> * -6  * -----> *  -2  * -----> * -3  *
 *                    *******        ********        *******
 *
 *  after calling sortList function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       ********        ********        *******
 *  *********   ----> * -6   * -----> *  -3  * -----> *  -2 *
 *                    ********        ********        *******
 *
 *  THIS TEST USE TO CHECK IF sortList CAN SORT ZERO LIST
 */
void test_sortList_given_neg6_neg2_neg3_should_return_neg6_neg3_neg2(void){
  LinkedList* testList  = createLinkedList();
   
  addListLast(testList, createListElement(-6)); 
  addListLast(testList, createListElement(-2)); 
  addListLast(testList, createListElement(-3));
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sortList(testList, DESCENDING_BIN_NUMBER);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(-6, sortedList->head->value);
  TEST_ASSERT_EQUAL(-3, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(-2, sortedList->tail->value);
}

/**
 *  sort function should sort the input link list as shown below:
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ------------------------------------------------------
 *  *********                                                       \
 *  * head  * \       *******        ********        *******       ********
 *  *********   ----> * 0   * -----> * -16  * -----> *  3  *-----> *  -2  *
 *                    *******        ********        *******       ********
 *
 *  after calling sort function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * -------------------------------------------------------
 *  *********                                                         \
 *  * head  * \       ********        ********        *******        *******
 *  *********   ----> * -16  * -----> *  -2  * -----> *  0  * -----> *  3  *
 *                    ********        ********        *******        *******
 *
 *  THIS TEST USE TO CHECK IF sort function CAN CALL sortList TO HANDLE LIST WITH
 *  NEGATIVE AND POSITIVE NUMBER
 */
void test_sort_given_0_neg16_3_neg2_should_return_neg16_neg2_0_3(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0)); 
  addListLast(testList, createListElement(-16)); 
  addListLast(testList, createListElement(3)); 
  addListLast(testList, createListElement(-2)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(-16, sortedList->head->value);
  TEST_ASSERT_EQUAL(-2, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(3, sortedList->tail->value);
}

/**
 *  TEST SORT WITH ONLY POSITIVE ITEM, SEE CAN IT SORT WITHOUT NEGATIVE ITEM
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ******        *******
 *  *********   ----> * 0x7E* -----> *0x02* -----> * 0x0E*
 *                    *******        ******        *******
 *  
 *  after calling sort function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ******        *******
 *  *********   ----> * 0x02* -----> *0x0E* -----> * 0x7E*
 *                    *******        ******        *******
 * 
 */
void test_sort_given_0x7E_0x2_0xE_should_return_0x2_0xE_0x7E(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x7E)); 
  addListLast(testList, createListElement(0x02)); 
  addListLast(testList, createListElement(0x0E)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x02, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x0E, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x7E, sortedList->tail->value);
}

/**
 *  TO TEST sort FUNCTION ABLE TO SORT LIST WITH NEGATIVE NUMBER ONLY
 *
 *  INPUT : 
 *   
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       *******        ********        *******
 *  *********   ----> * -6  * -----> *  -2  * -----> * -3  *
 *                    *******        ********        *******
 *
 *  after calling sort function, a sorted link list will be return as shown below:
 *
 *  SORTED:
 *
 *  *********
 *  * tail  * ----------------------------------------
 *  *********                                         \
 *  * head  * \       ********        ********        *******
 *  *********   ----> * -6   * -----> *  -3  * -----> *  -2 *
 *                    ********        ********        *******
 *
 *  THIS TEST USE TO CHECK IF sort CAN SORT NEGATIVE VALUE WITHOUT HAVING POSITIVE ITEM
 */
void test_sort_given_neg6_neg2_neg3_should_return_neg6_neg3_neg2(void){
  LinkedList* testList  = createLinkedList();
   
  addListLast(testList, createListElement(-6)); 
  addListLast(testList, createListElement(-2)); 
  addListLast(testList, createListElement(-3));
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(-6, sortedList->head->value);
  TEST_ASSERT_EQUAL(-3, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(-2, sortedList->tail->value);
}
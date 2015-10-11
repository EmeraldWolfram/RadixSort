#include "unity.h"
#include "Sort.h"
#include "LinkedList.h"
#include "GetNumberOfDigits.h"
#include <stdlib.h>
#include <math.h>

void setUp(void){}

void tearDown(void){}

//TO DO Add DOCUMENTATION
void test_sort_given_1_0_should_return_0_1(void){
	LinkedList* testList  = createLinkedList();

  addListLast(testList, createListElement(0x1)); 
  addListLast(testList, createListElement(0x0));
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x0, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x1, sortedList->tail->value);
}

void test_sort_given_3_9_6_2_4_should_return_2_3_4_6_9(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0x3)); 
  addListLast(testList, createListElement(0x9)); 
  addListLast(testList, createListElement(0x6)); 
  addListLast(testList, createListElement(0x2)); 
  addListLast(testList, createListElement(0x4)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0x2, sortedList->head->value);
  TEST_ASSERT_EQUAL(0x3, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0x4, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(0x6, sortedList->head->next->next->next->value);
  TEST_ASSERT_EQUAL(0x9, sortedList->tail->value);
}

void test_sort_given_126_2_14_should_return_2_14_126(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(126)); 
  addListLast(testList, createListElement(2)); 
  addListLast(testList, createListElement(14)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(2, sortedList->head->value);
  TEST_ASSERT_EQUAL(14, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(126, sortedList->tail->value);
}

void test_sort_given_22_222_2_62_should_return_2_22_62_222(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(22)); 
  addListLast(testList, createListElement(222)); 
  addListLast(testList, createListElement(2)); 
  addListLast(testList, createListElement(62)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(2, sortedList->head->value);
  TEST_ASSERT_EQUAL(22, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(62, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(222, sortedList->tail->value);
}

void test_sort_0_1000_100_should_return_0_100_1000(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0)); 
  addListLast(testList, createListElement(1000)); 
  addListLast(testList, createListElement(100)); 

  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);
  
  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(0, sortedList->head->value);
  TEST_ASSERT_EQUAL(100, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(1000, sortedList->tail->value);
}

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

void test_sort_given_0_neg6_3_neg2_should_return_neg6_neg2_0_3(void){
  LinkedList* testList  = createLinkedList();
  
  addListLast(testList, createListElement(0)); 
  addListLast(testList, createListElement(-6)); 
  addListLast(testList, createListElement(3)); 
  addListLast(testList, createListElement(-2)); 
  
  LinkedList* sortedList = createLinkedList();
  sortedList = sort(testList);

  TEST_ASSERT_NOT_NULL(sortedList->head);
  TEST_ASSERT_EQUAL(-6, sortedList->head->value);
  TEST_ASSERT_EQUAL(-2, sortedList->head->next->value);
  TEST_ASSERT_EQUAL(0, sortedList->head->next->next->value);
  TEST_ASSERT_EQUAL(3, sortedList->tail->value);
}


// void test_sort_2_2_6_should_Throw_ERR_SAME_VALUE_OBTAINED(void){
  // TEST_IGNORE_MESSAGE("ToDo: Catch ERROR test!");
// }

// void test_sort_given_nothing_should_Throw_ERR_EMPTY_LIST(void){
  // TEST_IGNORE_MESSAGE("ToDo: Catch ERROR test!");
// }
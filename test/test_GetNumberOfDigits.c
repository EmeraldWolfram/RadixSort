#include "unity.h"
#include "GetNumberOfDigits.h"
#include "LinkedList.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

void test_getNumberOfHexDigit_given_1_should_return_1(void){
	int digit = getNumberOfHexDigit(0x000000001);
  TEST_ASSERT_EQUAL(1, digit);
}

void test_getNumberOfHexDigit_given_minus1_should_return_1(void){
	int digit = getNumberOfHexDigit(0xFFFFFFFF);
  TEST_ASSERT_EQUAL(1, digit);
}

void test_getNumberOfHexDigit_given_2147483647_should_return_8(void){
	int digit = getNumberOfHexDigit(0x7FFFFFFF);
  TEST_ASSERT_EQUAL(8, digit);
}

void test_getNumberOfHexDigit_given_neg2147483648_should_return_8(void){
	int digit = getNumberOfHexDigit(0x80000000);
  TEST_ASSERT_EQUAL(8, digit);
}

void test_getNumberOfHexDigit_given_0_should_return_1(void){
	int digit = getNumberOfHexDigit(0x00000000);
  TEST_ASSERT_EQUAL(1, digit);
}

//***************************************************************************
void test_getLargestNumber_given_3_1_5_should_return_5(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(3));
  addListLast(testList, createListElement(1));
  addListLast(testList, createListElement(5));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(5, largestNumber);
}

void test_getLargestNumber_given_36_12_25_should_return_36(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(36));
  addListLast(testList, createListElement(12));
  addListLast(testList, createListElement(25));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(36, largestNumber);
}

void test_getLargestNumber_given_neg8_neg12_5_should_return_5(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(-12));
  addListLast(testList, createListElement(5));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(5, largestNumber);
}
//*****************************************************************************
void test_getSmallestNumber_given_3_1_5_should_return_1(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(3));
  addListLast(testList, createListElement(1));
  addListLast(testList, createListElement(5));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(1, smallestNumber);
}

void test_getSmallestNumber_given_12_36_25_should_return_12(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(12));
  addListLast(testList, createListElement(36));
  addListLast(testList, createListElement(25));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(12, smallestNumber);
}

void test_getSmallestNumber_given_neg8_neg12_5_should_return_neg12(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(-12));
  addListLast(testList, createListElement(5));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(-12, smallestNumber);
}
//*****************************************************************************
void test_getPosList_given_neg7_neg8_9_4_neg2_should_return_9_4(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-7));
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(9));
  addListLast(testList, createListElement(4));
  addListLast(testList, createListElement(-2));
  
  LinkedList* posList = getPosList(testList);
  
  TEST_ASSERT_NOT_NULL(posList);
  TEST_ASSERT_NOT_NULL(posList->head);
  TEST_ASSERT_EQUAL(9, posList->head->value);
  TEST_ASSERT_EQUAL(4, posList->tail->value);
}

void test_getNegList_given_neg7_neg8_9_4_neg2_should_return_neg7_neg8_neg2(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-7));
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(9));
  addListLast(testList, createListElement(4));
  addListLast(testList, createListElement(-2));
  
  LinkedList* posList = getNegList(testList);
  
  TEST_ASSERT_NOT_NULL(posList);
  TEST_ASSERT_NOT_NULL(posList->head);
  TEST_ASSERT_EQUAL(-7, posList->head->value);
  TEST_ASSERT_EQUAL(-8, posList->head->next->value);
  TEST_ASSERT_EQUAL(-2, posList->tail->value);
}
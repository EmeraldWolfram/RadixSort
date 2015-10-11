#include "unity.h"
#include "GetNumberOfDigits.h"
#include "LinkedList.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

/**
 *  getNumberOfHexDigit take in an integer value and determine the number of digit
 *  the input integer have. All the zero shall be ignored
 *
 *  The following test take a value 0x01 should return 1 digit as 0x01 = 0x1
 *  therefore, it should return 1 digit only.
 */
void test_getNumberOfHexDigit_given_1_should_return_1(void){
	int digit = getNumberOfHexDigit(0x000000001);
  TEST_ASSERT_EQUAL(1, digit);
}

/**
 *  getNumberOfHexDigit take in an integer value and determine the number of digit
 *  the input integer have. All the zero shall be ignored
 *
 *  The following test take a value 0xFFFFFFFF should return 1 digit as value 
 *  between 0x80000000 and 0xFFFFFFFF is negative value and 0xFFFFFFFF is decimal -1
 *  In term of magnitude, it should return 1 digit
 */
void test_getNumberOfHexDigit_given_minus1_should_return_1(void){
	int digit = getNumberOfHexDigit(0xFFFFFFFF);
  TEST_ASSERT_EQUAL(1, digit);
}

/**
 *  The following test check if 0x7FFFFFFF or decimal 2147483647 should return 8
 */
void test_getNumberOfHexDigit_given_2147483647_should_return_8(void){
	int digit = getNumberOfHexDigit(0x7FFFFFFF);
  TEST_ASSERT_EQUAL(8, digit);
}

/**
 *  The following test check if 0x80000000 or decimal -2147483648 should return 8
 */
void test_getNumberOfHexDigit_given_neg2147483648_should_return_8(void){
	int digit = getNumberOfHexDigit(0x80000000);
  TEST_ASSERT_EQUAL(8, digit);
}

/**
 *  The following test check if 0x00000000 or decimal 0 received should return 1
 *  as 0 is still a digit. although it is 0 but last 0 should not be ignored.
 */
void test_getNumberOfHexDigit_given_0_should_return_1(void){
	int digit = getNumberOfHexDigit(0x00000000);
  TEST_ASSERT_EQUAL(1, digit);
}

/**
 *  From 3, 1, 5, the largest number found in the third position which is 5
 **/
void test_getLargestNumber_given_3_1_5_should_return_5(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(3));
  addListLast(testList, createListElement(1));
  addListLast(testList, createListElement(5));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(5, largestNumber);
}

/**
 *  From 36, 12, 25, the largest number found in the first position which is 36
 **/
void test_getLargestNumber_given_36_12_25_should_return_36(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(36));
  addListLast(testList, createListElement(12));
  addListLast(testList, createListElement(25));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(36, largestNumber);
}

/**
 *  This is to make sure the function can determine positive larger than negative
 *  -8, -12, 5 should return 5.
 **/
void test_getLargestNumber_given_neg8_neg12_5_should_return_5(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(-12));
  addListLast(testList, createListElement(5));
  
  int largestNumber = getLargestNumber(testList);
  
  TEST_ASSERT_EQUAL(5, largestNumber);
}

/**
 *  From 3, 1, 5, the smallest number found in the second position which is 1
 **/
void test_getSmallestNumber_given_3_1_5_should_return_1(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(3));
  addListLast(testList, createListElement(1));
  addListLast(testList, createListElement(5));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(1, smallestNumber);
}

/**
 *  From 12, 36, 25, the smallest number found in the second position which is 12
 **/
void test_getSmallestNumber_given_12_36_25_should_return_12(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(12));
  addListLast(testList, createListElement(36));
  addListLast(testList, createListElement(25));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(12, smallestNumber);
}

/**
 *  From -8, -12, 5, the smallest number found in the second position which is -12
 **/
void test_getSmallestNumber_given_neg8_neg12_5_should_return_neg12(void){
  LinkedList* testList = createLinkedList();
  addListLast(testList, createListElement(-8));
  addListLast(testList, createListElement(-12));
  addListLast(testList, createListElement(5));
  
  int smallestNumber = getSmallestNumber(testList);
  
  TEST_ASSERT_EQUAL(-12, smallestNumber);
}
/**
 *  Test getPosList function can extract positive values in the list.
 */
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

/**
 *  Test getNegList function can extract negative values in the list.
 */
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
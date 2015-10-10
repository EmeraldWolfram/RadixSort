#include "unity.h"
#include "BinList.h"

void setUp(void){
}

void tearDown(void){
}

  /**
 *  createBinList like this
 *
 *  ********
 *  * head *-------->NULL
 *  ********
 *  * tail *-------->NULL
 *  ********
 */
void test_Linking_of_Create_BinList(void){
	BinList* myTestList = createBinList();
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NULL(myTestList->head);
	TEST_ASSERT_NULL(myTestList->tail);
  TEST_ASSERT_EQUAL(0,myTestList->length);
}

/**
 *  createBinElement like this
 *
 *  **************
 *  * size = 0   *
 *  **************
 *  * next       *-------->NULL
 *  **************
 */
void test_createBinElement(void){
  BinElement* testElement = createBinElement();

  TEST_ASSERT_NOT_NULL(testElement);
  TEST_ASSERT_EQUAL(0, testElement->size);
  TEST_ASSERT_NULL(testElement->next);
}


/**
 *  Before:                 After addListLast:
 *  ********                ********------>**************
 *  * head *----->NULL      * head *       * size = 0   *
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* next       *--->NULL
 *  ********                ********       **************
 *
 */
void test_addListLast_add_Single_Node_at_Last(void){
	BinList* myTestList = createBinList();
  BinElement* testElement = createBinElement();
  
	addListLast(myTestList,testElement);
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement);
	TEST_ASSERT_EQUAL_PTR(testElement, myTestList->head);
	TEST_ASSERT_NULL(myTestList->tail->next);
}

/**
 *  if Link List is NULL while calling addListLast
 *
 *  tell error
 *  ERROR: Linked List cannot be NULL
 *  Then, jump out directly!
 */
void test_addListLast_NULL_BinList_should_return_error(void){
  BinList* testBinList = NULL;
  BinElement* testElement = createBinElement();
  addListLast(testBinList, testElement);
 
  TEST_ASSERT_NULL(testBinList);
}

/**
 *  Before:                 After 1st addListLast:
 *                                --------------
 *                              /               \
 *  ********                ********       ************
 *  * head *----->NULL      * head *       * size = 0 *
 *  ********                ********       ************
 *  * tail *----->NULL      * tail * ----->* next     *--->NULL
 *  ********                ********       ************
 *
 *    After 2nd addListLast
 *            --------------------------
 *          /                           \
 *     ********       *************     ************
 *     * tail *       * size = 0  *     * size = 0 *                   
 *     ********       *************     ************
 *     * head * ----->* next      * --->* next     *----->NULL
 *     ********       *************     ************
 */
void test_addListLast_add_Two_Node_at_Last(void){
	BinList* myTestList = createBinList();
  BinElement* testElement_1 = createBinElement();
  BinElement* testElement_2 = createBinElement();
  
	addListLast(myTestList,testElement_1);
	addListLast(myTestList,testElement_2);
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
	TEST_ASSERT_EQUAL_PTR(testElement_1,myTestList->head);
	TEST_ASSERT_EQUAL_PTR(testElement_2,myTestList->tail);
  TEST_ASSERT_EQUAL_PTR(myTestList->head->next,myTestList->tail);
	TEST_ASSERT_NULL(myTestList->tail->next);
  TEST_ASSERT_EQUAL(2,myTestList->length);
}

/**
 *  Before:                 After addListLast:
 *                                --------------
 *                              /               \
 *  ********                ********       ************
 *  * head *----->NULL      * head *       * size = 0 *
 *  ********                ********       ************
 *  * tail *----->NULL      * tail * ----->* next     *--->NULL
 *  ********                ********       ************
 *
 */
void test_addListLast_add_NULL_Element_at_Last_should_do_nothing(void){
  BinList* testList = createBinList();
  BinElement* testElement_1 = createBinElement();
  BinElement* testElement_2 = NULL;
  addListLast(testList,testElement_1);
  addListLast(testList,testElement_2);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NULL(testElement_2);
  TEST_ASSERT_EQUAL_PTR(testElement_1, testList->head);
  TEST_ASSERT_NULL(testList->head->next);
  TEST_ASSERT_EQUAL_PTR(testList->head, testList->tail);
  TEST_ASSERT_EQUAL(1,testList->length);
}

/**
 *  Before:                 After 1st addListLast:
 *                                --------------
 *                              /               \
 *  ********                ********       ************
 *  * head *----->NULL      * head *       * size = 0 *
 *  ********                ********       ************
 *  * tail *----->NULL      * tail * ----->* next     *--->NULL
 *  ********                ********       ************
 *
 *    After 2nd addListLast
 *            -----------------------------------------------
 *          /                                                 \
 *     ********       *************       *************     ************
 *     * tail *       * size = 0  *       * size = 0  *     * size = 0 *                   
 *     ********       *************       *************     ************
 *     * head * ----->* next      * ----->* next      * --->* next     *----->NULL
 *     ********       *************       *************     ************
 */
void test_addListLast_add_Three_Node_at_Last(void){
	BinList* myTestList = createBinList();
  BinElement* testElement_1 = createBinElement();
  BinElement* testElement_2 = createBinElement();
  BinElement* testElement_3 = createBinElement();
		
	addListLast(myTestList,testElement_1);
	addListLast(myTestList,testElement_2);
	addListLast(myTestList,testElement_3);
		
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement_1); 
  TEST_ASSERT_NOT_NULL(testElement_2); 
  TEST_ASSERT_NOT_NULL(testElement_3); 
  TEST_ASSERT_EQUAL_PTR(testElement_1, myTestList->head);
	TEST_ASSERT_EQUAL_PTR(testElement_2, myTestList->head->next);
  TEST_ASSERT_EQUAL_PTR(testElement_3, myTestList->tail);
	TEST_ASSERT_NULL(myTestList->tail->next);
  TEST_ASSERT_EQUAL(3,myTestList->length);
}

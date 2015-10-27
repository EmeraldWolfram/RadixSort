#include "unity.h"
#include "ErrorObject.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_ThrowError_throw_ERR_NULL_ELEMENT_should_get_an_error_object_containing_them(void){
  ErrorObject* err;
  Try{
    ThrowError(ERR_NULL_ELEMENT, "NULL Element detected");
    TEST_FAIL_MESSAGE("Expecting ERR_NULL_ELEMENT but none thrown.");
  }Catch(err){
    TEST_ASSERT_EQUAL(ERR_NULL_ELEMENT, err->errorCode);
    TEST_ASSERT_EQUAL_STRING("NULL Element detected",  err->errorMsg);
    freeError(err);
  }
}

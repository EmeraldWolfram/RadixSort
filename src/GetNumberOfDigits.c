#include "GetNumberOfDigits.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int getNumberOfHexDigit(int NumberToFind){
  int digit = 0;
  
  if(NumberToFind == 0)
    digit++;
  else{
    while(NumberToFind != 0){
      NumberToFind = NumberToFind/16;
      digit++;
    }    
  }
  return digit;
}

int getLargestNumber(LinkedList* List){
  assert(List != NULL);
  int currentLargest;
  
  if(List->head == NULL)
    currentLargest = 0;
  else{
    ListElement* currentNode = List->head;
    currentLargest = currentNode->value;
    while(currentNode != NULL){
      if(currentNode->value > currentLargest)
        currentLargest = currentNode->value;
      currentNode = currentNode->next;
    } 
  }
  return currentLargest;
}

int getSmallestNumber(LinkedList* List){
  assert(List != NULL);
  int currentSmallest;
  
  if(List->head == NULL)
    currentSmallest = 0;
  else{
    ListElement* currentNode = List->head;
    currentSmallest = currentNode->value;
    while(currentNode != NULL){
      if(currentNode->value < currentSmallest)
        currentSmallest = currentNode->value;
      currentNode = currentNode->next;
    } 
  }
  return currentSmallest;
}
#include "GetNumberOfDigits.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int getNumberOfHexDigit(int numberToFind){
  int digit = 0;
  
  if(numberToFind == 0)
    digit++;
  else{
    while(numberToFind != 0){
      numberToFind = numberToFind/16;
      digit++;
    }    
  }
  return digit;
}

int getLargestNumber(LinkedList* inputList){
  assert(inputList != NULL);
  int currentLargest;
  
  if(inputList->head == NULL)
    currentLargest = 0;
  else{
    ListElement* currentNode = inputList->head;
    currentLargest = currentNode->value;
    while(currentNode != NULL){
      if(currentNode->value > currentLargest)
        currentLargest = currentNode->value;
      currentNode = currentNode->next;
    } 
  }
  return currentLargest;
}

int getSmallestNumber(LinkedList* inputList){
  assert(inputList != NULL);
  int currentSmallest;
  
  if(inputList->head == NULL)
    currentSmallest = 0;
  else{
    ListElement* currentNode = inputList->head;
    currentSmallest = currentNode->value;
    while(currentNode != NULL){
      if(currentNode->value < currentSmallest)
        currentSmallest = currentNode->value;
      currentNode = currentNode->next;
    } 
  }
  return currentSmallest;
}

LinkedList* getNegList(LinkedList* inputList){
  assert(inputList != NULL);
  LinkedList* splitList = createLinkedList();
  ListElement* tempNode = inputList->head;

  while(tempNode != NULL){
    if(tempNode->value < 0)
      addListLast(splitList, createListElement(tempNode->value));
    tempNode = tempNode->next;
  }
  
  return splitList;
}

LinkedList* getPosList(LinkedList* inputList){
  assert(inputList != NULL);
  LinkedList* splitList = createLinkedList();
  ListElement* tempNode = inputList->head;
  
  while(tempNode != NULL){
    if(tempNode->value >= 0)
      addListLast(splitList, createListElement(tempNode->value));
    tempNode = tempNode->next;
  }
  
  return splitList;  
}
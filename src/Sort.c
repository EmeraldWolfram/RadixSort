#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


LinkedList* sort(LinkedList* inputList){
  LinkedList* sortedList   = createLinkedList();
  LinkedList* sortPosList  = createLinkedList();
  LinkedList* sortNegList  = createLinkedList();
  LinkedList* posList = getPosList(inputList);
  LinkedList* negList = getNegList(inputList);

  ListElement* tempPosNode = posList->head;
  ListElement* tempNegNode = negList->head;
  sortPosList = sortList(posList, ASCENDING_BIN_NUMBER);
  sortNegList = sortList(negList, DESCENDING_BIN_NUMBER);
  
  addListLast(sortedList, sortNegList->head);
  addListLast(sortedList, sortPosList->head);
  // connectList(sortNegList, sortPosList);
  
  // return sortNegList;
  return sortedList;
}

LinkedList* sortList(LinkedList* inputList, Arrangement arrangement){
  int mdl16, div16, i, j, digit;
  LinkedList* sortedList = createLinkedList();
  ListElement* tempNode = inputList->head;
  
  if(arrangement == ASCENDING_BIN_NUMBER)
    digit = getNumberOfHexDigit(getLargestNumber(inputList));
  else
    digit = getNumberOfHexDigit(getSmallestNumber(inputList));
  
  NumberBin bin[16] = {
  [0x0] = {NULL}, [0x1] = {NULL}, [0x2] = {NULL}, [0x3] = {NULL},
  [0x4] = {NULL}, [0x5] = {NULL}, [0x6] = {NULL}, [0x7] = {NULL},
  [0x8] = {NULL}, [0x9] = {NULL}, [0xA] = {NULL}, [0xB] = {NULL},
  [0xC] = {NULL}, [0xD] = {NULL}, [0xE] = {NULL}, [0xF] = {NULL}
  };
  
  for(j=0; j<digit; j++){
  RESET(sortedList)

    while(tempNode != NULL){
      div16 = tempNode->value / (int)(pow(16.0, (double)j));
      if(div16 >= 0)
        mdl16 = div16 % 16;
      else
        mdl16 = (-1 * div16) % 16;
      
      // printf("modulus : %X\t", mdl16);
      if(bin[mdl16].binList == NULL)
        bin[mdl16].binList = createLinkedList();
    
      printf("div: %d\tbin: %d\tvalue: %d\n", div16, mdl16, tempNode->value);
      addListLast(bin[mdl16].binList, createListElement(tempNode->value));
      tempNode = tempNode->next;
    }
    tempNode = NULL;
    
    if(arrangement == ASCENDING_BIN_NUMBER){
      for(i=0;i < 16;i++){
        if(bin[i].binList != NULL)
          addListLast(sortedList, bin[i].binList->head);
        bin[i].binList = NULL;
      }
    }
    else{
      for(i=15;i > 0;i--){
        if(bin[i].binList != NULL)
          addListLast(sortedList, bin[i].binList->head);
        bin[i].binList = NULL;
      }
    }
    tempNode = sortedList->head;
  }
  return sortedList;
}
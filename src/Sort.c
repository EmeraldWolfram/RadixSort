#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


LinkedList* sort(LinkedList* inputList){
  LinkedList* sortPosList  = createLinkedList();
  LinkedList* sortNegList  = createLinkedList();
  LinkedList* posList = getPosList(inputList);
  LinkedList* negList = getNegList(inputList);

  ListElement* tempPosNode = posList->head;
  ListElement* tempNegNode = negList->head;
  sortPosList = sortList(posList, ASCENDING_BIN_NUMBER);
  sortNegList = sortList(negList, DESCENDING_BIN_NUMBER);
  
  connectList(sortNegList, sortPosList);

  return sortNegList;
}

LinkedList* sortList(LinkedList* inputList, Arrangement arrangement){
  int mdl16, div16, i, j;
  LinkedList* sortedList = createLinkedList();
  ListElement* tempNode = inputList->head;
  
  int digit_H = getNumberOfHexDigit(getLargestNumber(inputList));
  int digit_L = getNumberOfHexDigit(getSmallestNumber(inputList));
  int digit   = (digit_H > digit_L) ? digit_H : digit_L;
  
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
      if(div16 > 0)
        mdl16 = div16 % 16;
      else
        mdl16 = (-1 * div16) % 16;
      
      if(bin[mdl16].binList == NULL)
        bin[mdl16].binList = createLinkedList();
      printf("div16: %d\tbin: %d\t value: %d\t\n", div16, mdl16, tempNode->value);
      addListLast(bin[mdl16].binList, createListElement(tempNode->value));
      tempNode = tempNode->next;
    }
    tempNode = NULL;
    
    if(arrangement == ASCENDING_BIN_NUMBER){
      for(i=0;i < 16;i++){
        ASSEMBLE
      }
    }
    else{
      for(i=15;i >= 0;i--){
        ASSEMBLE
      }
    }
    tempNode = sortedList->head;
  }
  return sortedList;
}
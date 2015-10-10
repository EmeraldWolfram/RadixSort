#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


LinkedList* sort(LinkedList* inputList){
  LinkedList* sortedList = createLinkedList();
  ListElement* tempNode  = inputList->head;
  int mdl16, div16, i, j;
  int mode  = getLargestNumber(inputList);
  int digit = getNumberOfHexDigit(mode);
  
  NumberBin bin[16] = {
    [0x0] = {NULL}, [0x1] = {NULL},
    [0x2] = {NULL}, [0x3] = {NULL},
    [0x4] = {NULL}, [0x5] = {NULL},
    [0x6] = {NULL}, [0x7] = {NULL},
    [0x8] = {NULL}, [0x9] = {NULL},
    [0xA] = {NULL}, [0xB] = {NULL},
    [0xC] = {NULL}, [0xD] = {NULL},
    [0xE] = {NULL}, [0xF] = {NULL}
  };
  
  for(j=0; j<digit; j++){
    sortedList->head = NULL;
    sortedList->tail = NULL;
    sortedList->length = 0;
    while(tempNode != NULL){
      div16 = tempNode->value / (int)(pow(16.0, (double)j));
      mdl16 = div16 % 16;
      if(bin[mdl16].binList == NULL)
        bin[mdl16].binList = createLinkedList();
    
      addListLast(bin[mdl16].binList, createListElement(tempNode->value));
      tempNode = tempNode->next;
    }
    tempNode = NULL;

    for(i=0;i < 16;i++){
      if(bin[i].binList != NULL){
        addListLast(sortedList, bin[i].binList->head);
      }
      bin[i].binList = NULL;
    }
    tempNode = sortedList->head;
  }
  return sortedList;
}

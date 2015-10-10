#include "BinList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

BinList* createBinList(){
	BinList* newList = malloc(sizeof(BinList));
	assert(newList != NULL);
  
	newList-> head	= NULL;
	newList-> tail	= NULL;
  newList->length = 0;
	
	return newList;
}

BinElement* createBinElement(){
	BinElement* newNode = malloc(sizeof(BinElement));
	assert(newNode != NULL);
  
	newNode->next  = NULL;
  newNode->size  = 0;
  
	return newNode;
}


void addListLast(BinList* currentList, BinElement* currentNode){

  if(currentList == NULL){
    printf("ERROR: Element cannot be NULL!");
  }
  else if(currentNode == NULL){
    printf("ERROR: Link List cannot be NULL!");
  }
  else{
    BinElement* tempNode = currentList->head;
		//check if the linked list empty. If empty, create a Node that the head point to
		if(currentList->head == NULL){
			currentList->head = currentNode;
		}
		else{
			while(tempNode->next != NULL){    		//if the list is not empty, find the last node and add a node as new last node
				tempNode = tempNode->next;
			}
			tempNode->next = currentNode;
		}
		//No matter what, the tail always point to last node
      currentList->tail = currentNode;
      currentList->length ++;
    }
}

void addListFirst(BinList* stack, BinElement *elem){ 
  if(elem == NULL){
    printf("ERROR: Element cannot be NULL!");
  }
  else if(stack == NULL){
    printf("ERROR: Link List cannot be NULL!");
  }
  else{
    BinElement* prevHead = malloc(sizeof(BinElement));
    prevHead = stack->head;
    stack->head = elem; //No matter what, the head always point to the new added Element
    
    if(stack->length == 0){
      stack->head->next = NULL;
      stack->tail = elem;
    }
    else
      stack->head->next = prevHead;
    
    (stack->length)++;
    stack->tail->next = NULL; //Tail->next permanently pointing to NULL
  }
}


BinElement* listRemoveFirst(BinList* link){
  BinElement* removedElement;

  if(link == NULL){    
    removedElement = NULL;
    printf("ERROR: Link List cannot be NULL!");
  }
  else if(link->head == NULL){
    removedElement = NULL;
    printf("Nothing to remove, empty stack here! Return empty element");
  }
  else{
    removedElement = malloc(sizeof(BinElement));
    removedElement = link->head;
    if(link->head->next != NULL)
      link->head = link->head->next;
    else{
      link->head = NULL;
      link->tail = NULL;
    } 
    removedElement->next = NULL;
    link->length --;
  }
  return removedElement;
}

BinElement* listRemoveLast(BinList* link){
  BinElement* removedElement;
  BinElement* tempNode = malloc(sizeof(BinElement));
 
  if(link == NULL){    
    removedElement = NULL;
    printf("ERROR: Link List cannot be NULL!");
  }
  else if(link->head == NULL){
    removedElement = NULL;
    printf("Nothing to remove, empty stack here! Return empty element");
  }
  else{
    tempNode = link->head;
    removedElement = malloc(sizeof(BinElement));
    removedElement = link->tail;
    if(tempNode->next != NULL){
      while(tempNode->next != link->tail){
        tempNode = tempNode->next;
      }
      link->tail = tempNode;
      tempNode->next = NULL;
    }
    else{
      link->head = NULL;
      link->tail = NULL;
    }
    link->length --;
  }
  return removedElement;
}

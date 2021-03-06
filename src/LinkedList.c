#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

/**
 * createLinkedList
 *	Calling the function will generate an empty Linked List and return it	
 *
 *	As the linked list created was empty, both head and tail point to NULL
 *
 * Words:
 *	1. newList		a new linked list object that is empty
 *
 *
 * createListElement
 *
 *	Calling the function will generate a ListElement's object and return it.
 *	ListElement type object contain:
 *		1. an integer
 *		2. a pointer to the next ListElement object
 *
 *	ListElement type object is basically a node that can extend to store more value
 *
 * Words:
 *	1. inValue		integer argument brought in to store in the listElement object
 *	2. newNode		new created node that store the "inValue"
 */


LinkedList* createLinkedList(){
	LinkedList* newList = malloc(sizeof(LinkedList));
	assert(newList != NULL);
  
	newList-> head	= NULL;
	newList-> tail	= NULL;
  newList->length = 0;
	
	return newList;
}

ListElement* createListElement(int inValue){
	ListElement* newNode = malloc(sizeof(ListElement));
	assert(newNode != NULL);
  
	newNode->value = inValue;
	newNode->next = NULL;
  
	return newNode;
}

void addListLast(LinkedList* currentList, ListElement* currentNode){

  if(currentList == NULL){
    ThrowError(ERR_NULL_LINK_LIST, "NULL Link List detected");
  }
  else if(currentNode == NULL){
    ThrowError(ERR_NULL_ELEMENT, "NULL Element detected");
  }
  else{
    ListElement* tempNode = currentList->head;
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

void addListFirst(LinkedList* stack, ListElement *elem){ 
  if(elem == NULL){
    ThrowError(ERR_NULL_ELEMENT, "NULL Element detected");
  }
  else if(stack == NULL){
    ThrowError(ERR_NULL_LINK_LIST, "NULL Link List detected");
  }
  else{
    ListElement* prevHead = malloc(sizeof(ListElement));
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

ListElement* listRemoveFirst(LinkedList* link){
  ListElement* removedElement;

  if(link == NULL){    
    removedElement = NULL;
    ThrowError(ERR_NULL_LINK_LIST, "NULL Link List detected");
  }
  else if(link->head == NULL){
    removedElement = NULL;
    ThrowError(ERR_EMPTY_LIST, "Empty Link List detected");
  }
  else{
    removedElement = malloc(sizeof(ListElement));
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

ListElement* listRemoveLast(LinkedList* link){
  ListElement* removedElement;
  ListElement* tempNode = malloc(sizeof(ListElement));
 
  if(link == NULL){    
    removedElement = NULL;
    ThrowError(ERR_NULL_LINK_LIST, "NULL Link List detected");
  }
  else if(link->head == NULL){
    removedElement = NULL;
    ThrowError(ERR_EMPTY_LIST, "Empty Link List detected");
  }
  else{
    tempNode = link->head;
    removedElement = malloc(sizeof(ListElement));
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

void connectList(LinkedList* firstList, LinkedList* secondList){

  if(firstList == NULL || secondList == NULL)
    ThrowError(ERR_NULL_LINK_LIST, "NULL Link List detected");
  else{
    if(firstList->head == NULL){
      firstList->head = secondList->head;
      firstList->tail = secondList->tail;
      firstList->length = secondList->length;
    }
    else{
      if(secondList->head != NULL){
        firstList->tail->next = secondList->head;
        firstList->tail = secondList->tail;
        firstList->length = firstList->length + secondList->length;
      }
    }
  }
  free(secondList);
}



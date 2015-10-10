#ifndef Sort_H
#define Sort_H
#include "LinkedList.h"
#include "GetNumberOfDigits.h"

#define RESET(list)     list->head = NULL;\
                        list->tail = NULL;\
                        list->length = 0;
                        
#define ASSEMBLE()      if(bin[i].binList != NULL){\
                          addListLast(sortedList, bin[i].binList->head);\
                        }\
                        bin[i].binList = NULL;
                        
typedef enum{
  ASCENDING_BIN_NUMBER,
  DESCENDING_BIN_NUMBER
}Arrangement;
                        
typedef struct{
  LinkedList* binList;
}NumberBin;

LinkedList* sort(LinkedList* sortedList);
LinkedList* sortList(LinkedList* inputList, Arrangement arrangement);
// void dissembleListIntoBins(LinkedList* inputList, NumberBin* bin, int digitToArrange);


#endif // Sort_H

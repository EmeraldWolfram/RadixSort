#ifndef Sort_H
#define Sort_H
#include "LinkedList.h"
#include "GetNumberOfDigits.h"

typedef struct{
  LinkedList* binList;
}NumberBin;

LinkedList* sort(LinkedList* inputList);

#endif // Sort_H

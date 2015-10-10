#ifndef BinList_H
#define BinList_H

typedef struct BinElement BinElement;
struct BinElement{
  BinElement* next;
  int size;
  int value[10];
};

typedef struct{
  BinElement* head;
  BinElement* tail;
  int length;
} BinList;

BinList* createBinList();
BinElement* createBinElement();

void addListLast(BinList* currentList, BinElement* currentNode);
void addListFirst(BinList* stack, BinElement *elem);

BinElement* listRemoveFirst(BinList* link);
BinElement* listRemoveLast(BinList* link);

#endif // BinList_H

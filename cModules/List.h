#ifndef __list_h
#define __list_h

typedef struct list  *List;

List listMake();

unsigned int listLength(List list);
int listIsEmpty(List list);
void listPrepend(List list, int value);
void listInsert(List list, int value, int index);
void listAppend(List list, int value);
int *listGetFirst(List list);
int *listGetlast(List list);
int *listGetKeyByIndex(List list, int index);

#endif

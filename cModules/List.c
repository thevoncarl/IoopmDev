#include <stdlib.h>
#include "List.h"

struct link
{
  int value;
  struct link *next;
  
};

struct list
{
  struct link *first;
  struct link *last;
};



List listMake () {

  List result = malloc(sizeof(struct list));

  if (result != NULL) {
    result->first = NULL;
    result->last = NULL;
    return result;
  }
  //sätta felflaggor
  return NULL;
}


struct link *mkLink(int value, struct link *next) {
  struct link *result  = malloc(sizeof(struct link));
  if (result != NULL){
    result->value = value;
    result->next = next;
    return result;
  }
  return NULL;
}

unsigned int listLength(List list){
  unsigned int size = 0; 
 struct link *cursor = list->first;
 while (cursor != NULL){
    ++size;
    cursor = cursor->next;
 }
  return size;
}

int listIsEmpty (List list){
  return list->first == NULL;
}

void linkAdd(struct link *link, int value){

  link->next = mkLink(value, link->next);
  
}

void listPrepend(List list, int value){
list->first =  mkLink(value,list->first);
 if(list->last == NULL){
   list->last = list->first;
 }
}

void listInsert (List list, int value, int index){
  if (index == 0)  {
    listPrepend(list,value);
    return;
  }
  
  struct link *cursor = list->first;
  while (cursor){
    if(index-- == 1) linkAdd(cursor,value);
    cursor = cursor->next;
  }
}

void listAppend(List list, int value){
  if(list->last == NULL){

list->last = list->first =  mkLink(value, NULL);

  } else {
    list->last = list->last->next =  mkLink(value, NULL);    
  }
}

int *listGetFirst(List list) {
  if (listIsEmpty(list))  {
    return NULL;
  }else{
    return &(list->first->value);
    }
}

int *listGetlast(List list) {
  if (listIsEmpty(list))  {
    return NULL;
  }else{
    return &(list->last->value);
  }
}

int *listGetKeyByIndex(List list, int index){
  struct link *cursor = list->first;
  while (cursor && index > 0){
    if(index-- == 0) {return &(cursor->value); }
    cursor = cursor->next;
  }
  return NULL;
}



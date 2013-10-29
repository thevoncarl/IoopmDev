#include <stdio.h>
#include "List.h"

int main(int argc, char *argv[]){
  
  List Alist = listMake();
  if (listIsEmpty(Alist) == 1){
    printf ("Empty List!\n");
  }
  int i = 0;
  while (i < 100){
    listInsert(Alist, i, i*3);
    int *key1 = listGetKeyByIndex(Alist, i); 
    printf("Index: %d  Key: %d\n",i*3, *key1);
    listPrepend(Alist, i); 
    listAppend(Alist, i);
    i++;    
  }

  
  return 0;
}


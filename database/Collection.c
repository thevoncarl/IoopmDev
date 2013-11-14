#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Collection.h"


struct node {
  char* key;
  char* value;
  struct node *parent;
  struct node *left;
  struct node *right;
};


/*typedef*/ struct binaryTree{
  struct node *treeRoot;
}; //*Collection;


struct node *mkNode(char *key, char *value){
  struct node *returnNode = malloc(sizeof(struct node));
  char *aKey = malloc(strlen(key));
  char *aValue = malloc(strlen(value));
  strcpy(aKey, key);
  strcpy(aValue,value);
  if (returnNode != NULL ){
    returnNode->key = aKey;
    returnNode->value = aValue;
    returnNode->parent = NULL;
    returnNode->left = NULL;
    returnNode->right = NULL;
    return returnNode;
  }else 
    return NULL;
}

Collection mkCollection(){
  Collection result = malloc(sizeof(struct binaryTree));
if (result != NULL)
  {
    result->treeRoot = NULL;
    return result;
  }else return NULL;
}



struct node *treeSearch(struct node *root, char *key){
  struct node *cursor = root;
  int found = -1 ; 
  while (cursor != NULL && found != 0){
    found = strcmp(cursor->key, key);
    if(found < 0){
      cursor = cursor->left;
    }else if (found > 0){
      cursor = cursor->right;
    }
  }
  if (cursor != NULL && strcmp(cursor->key, key) == 0){
    return cursor;
  }else {
    return NULL;
    }
  
}


int insertNode(Collection collection, struct node *nodeToInsert){
  if (collection->treeRoot != NULL){   
    struct node *previusNode = NULL;
    struct node *aCursor = collection->treeRoot;
    int aResult;
    while(aCursor != NULL){
      previusNode = aCursor;
      aResult = strcmp(aCursor->key,nodeToInsert->key);
      if (aResult < 0){
	aCursor = aCursor->left;
      }else if (aResult > 0){
	aCursor = aCursor->right;
      }
      else { printf("Key Already Exist!1"); return 0;
      }
    } 
  if (nodeToInsert->parent != NULL && previusNode !=NULL){
    free(nodeToInsert->parent);
  }
  if(previusNode != NULL){
    nodeToInsert->parent = previusNode; 
    int aaResult = strcmp(nodeToInsert->key, previusNode->key);  
    if(aaResult > 0){
      previusNode->left = nodeToInsert;
      return 1;
    }else if(aaResult < 0) {
      previusNode->right = nodeToInsert;
    return 1;
    }else{
      printf("Key Already Exist!2");
      return 0;
    }
  }else{
    collection->treeRoot = nodeToInsert;
    return 1;
  }
  }else{
    collection->treeRoot = nodeToInsert;
    return 1;
  }
 
}


void destroyKeyValuePair(struct node *aNode){
  free(aNode->key);
  free(aNode->value);
}
void destroySubTree(struct node *subTree){
  if (subTree != NULL){
    destroySubTree(subTree->right);
    destroySubTree(subTree->left); 
    destroyKeyValuePair(subTree);
    free(subTree);
  } 
}


struct node* treeMinimum(struct node *aNode){
  struct node *curs = aNode;
  while(curs != NULL){
    curs = curs->left;
  }
  return curs;
}



void transplant (Collection collection, struct node *node1, struct node *node2){
  if (node1->parent == NULL){
    collection->treeRoot = node2;
  }else if (node1 == node1->parent->left){
    node1->parent->left = node2;
  }else {
    node1->parent->right = node2;
  }
  if (node2 != NULL){
    node2->parent = node1->parent;
  }
}

void treeDelete (Collection collection, struct node *nodeToDelete){
  if(nodeToDelete == NULL){
    transplant(collection,nodeToDelete,nodeToDelete->right);
      }else if(nodeToDelete->right == NULL){
    transplant(collection,nodeToDelete,nodeToDelete->left);
  }else {
    struct node *minNode = treeMinimum(nodeToDelete->right);
    if(minNode->parent != nodeToDelete){
      transplant(collection,minNode,minNode->right);
      minNode->right = nodeToDelete->right;
      minNode->right->parent = minNode;
    }
    transplant(collection,nodeToDelete,minNode);
    minNode->left = nodeToDelete->left;
    minNode->left->parent = minNode;
  }

  destroyKeyValuePair(nodeToDelete);
  free(nodeToDelete);
}

void rmCollection(Collection collection){

  destroySubTree(collection->treeRoot);
  free(collection);


}

 
int collectionRemoveKeyValuePair(Collection collection, char* key){
  struct node *aNode = treeSearch(collection->treeRoot, key);
  if(aNode != NULL){
    treeDelete(collection, aNode);
    return 1;
  }else {
    return 0;
  }
}

int collectionInsertKeyValuePair(Collection collection, char *key, char *value){

  struct node *newNode = mkNode(key,value);
  int success = insertNode(collection,newNode);
  return success;
}

int collectionDoseKeyExist(Collection collection, char* key){
  struct node * aNode = treeSearch(collection->treeRoot, key);
  if (aNode != NULL){
    return 1;
  }else {
    return 0;
    }
}
char* collectionGetValueByKey(Collection collection, char *key){
  struct node *aNode = treeSearch(collection->treeRoot, key);
  if (aNode != NULL){
    return aNode->value;
  }else {
    return NULL;
  }
}

void inOrderWalk(struct node* aNode){
  if(aNode != NULL){
    inOrderWalk(aNode->left);
    printf("(%s,%s)\n",aNode->key,aNode->value);
    inOrderWalk(aNode->right);
  }
}


void collectionPrint(Collection collection){
  inOrderWalk(collection->treeRoot);
}
/*
int main(int argc, char *argv[])
{
  Collection MyCollection = mkCollection();
  if (MyCollection != NULL){
    printf("FUCK YEAH! \n");
    
  }
  struct node *myNode = mkNode("String", "Value");
  if (myNode != NULL){
    printf("FUCK YEAH! \n ,%s:%s\n",myNode->key,myNode->value);
  }
  
  struct node *aNode = mkNode("kille","tjej");
  int su = insertNode(MyCollection,myNode);
  int su2 = insertNode(MyCollection,aNode);
  printf ("%d:%d\n",su,su2);
  
  struct node *kall = treeSearch(MyCollection->treeRoot,"kille");
  printf("%s\n",kall->value);
  
  rmCollection(MyCollection);
  
  puts ("Interface TESTS\n");
  
  Collection newCollection = mkCollection();
  int indicator1 = collectionInsertKeyValuePair(newCollection, "hund", "katt");
  if(indicator1 == 1){
    puts("Test 1: collectionInsertKeyValue Successful!\n");
  }else{
    puts ("Test 1: Failed!\n");
    
  }
  printf("Test 2 collectionDoseKeyExist: %d \n Indicator: %d \n collectionDoseKeyExist(false value): %d \n", collectionDoseKeyExist(newCollection, "hund"), indicator1,  collectionDoseKeyExist(newCollection, "olle") );
  printf("Test 3 collectionGetValueByKey:%s\n", collectionGetValueByKey(newCollection, "hund"));  
  printf("collectionGetValueByKey(false value): %s \n", collectionGetValueByKey(newCollection, "rally"));
 printf("Test 4 collectionRemoveKeyValuePair (removed string : Dose Exist?!) : %d : %d \n" ,collectionRemoveKeyValuePair(newCollection, "hund"),collectionDoseKeyExist(newCollection,"hund"));
  
  

return 0;
}*/


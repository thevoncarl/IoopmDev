#include "Collection.h"

struct binaryTree{
  char* key;
  char* value;
  struct binaryTree *left;
  struct binaryTree *right;
} *Collection;

Collection mkCollection(){
  binaryTree result = mkBinaryTree(NULL,NULL);
  return result;
}
printf("Collection could not me made");
return NULL;
}

binaryTree mkBinaryTree(char* key, char* value){
  struct binaryTree newTree = malloc(sizeof(struct binaryTree))
    if(newTree != NULL){
      newTree->key = key;
      newTree->value = value;
      newTree->left = NULL;
      newTree->right = NULL;
      return newTree;
    }else
      return NULL;
}

void collectionInsertKeyValuePair(Collection collection, char* key, char* value){
  if(key =! NULL && value != NULL && collection != NULL){
    if (collection->key == NULL && collection->value == NULL){
      collection->key = key;
      collection->value = value;
      return;
    }else{
      struct binaryTree *cursor = collection;
      int inserted = 0;
      while (!inserted && cursor != NULL){
	int result = strcmp(cursor->key, key);
	if (result > 0) // cursor->key < key
	  {
	    if (cursor->right == NULL)
	      { 
		struct binaryTree newTree = mkBinaryTree(key,value);
		cursor->right = newTree;
		inserted = 1;
	      }else{
	      cursor = cursor->right; 
	      continue;
	    }
	  }else if (result < 0) //cursor->key > key
	  if (cursor->left == NULL)
	    {
	      struct binaryTree newTree = mkBinaryTree(key,value);
	      cursor->left = newTree;
	      inserted = 1;
	     
	    }else {
	    cursor = cursor->left;
	    continue;
	  }else {
	  //key exists
	  free(cursor->value);
	  cursor->value = value;
	  inserted =!;
	  return;
	}
      }
    }
  }
   
    }    
    
}else
    { 
      printf ("Key or Value cannot be empty!");
    }

}

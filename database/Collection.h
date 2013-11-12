#ifndef __Collection_h
#define __Collection_h
typedef struct binaryTree *Collection;

Collection mkCollection();
void rmCollection();
int collectionInsertKeyValuePair(Collection collection, char* key, char* value);
char* collectionRemoveKeyValuePair(Collection collection, char* key);
char* collectionGetValueByKey(Collection collection, char *key);
int collectionDoseKeyExist(Collection collection, char *key);
void collectionQuery(Collection collection, char* key); 
//int collectionFind(Collection collection,char* key);


#endif

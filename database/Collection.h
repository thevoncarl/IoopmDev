#ifndef __Collection_h
#define __Collection_h

Collection mkCollection();
void collectionInsertKeyValuePair(Collection collection, char* key, char* value);
void collectionInsertKetValuePairStrict(Collection collection, char* key, char* value);
void collectionQuery(Collection collection, char* key); // puts("Found entry:");  printf("key: %s\nvalue: %s\n", cursor->key, cursor->value);   printf("Could not find an entry matching key \"%s\"!\n", buffer);
int collectionFind(Collection collection,char* key);


#endif

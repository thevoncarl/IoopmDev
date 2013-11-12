#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Collection.h"



void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}

 void printWelcome(){
  puts("Welcome to");
  puts(" ____    ____       ");
  puts("/\\  _`\\ /\\  _`\\     ");
  puts("\\ \\ \\/\\ \\ \\ \\L\\ \\   ");
  puts(" \\ \\ \\ \\ \\ \\  _ <\\ ");
  puts("  \\ \\ \\_\\ \\ \\ \\L\\ \\ ");
  puts("   \\ \\____/\\ \\____/ ");
  puts("    \\/___/  \\/___/  ");
  puts("");
  }
void readInputFromFile(Collection collection,char* filename, char buffer[]){
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  while(!(feof(database))){
    readline(buffer, 128, database);
    char* key;
     strcpy(key, buffer);
     readline(buffer, 128, database);
     char* value;
     strcpy(value, buffer);
     collectionInsertKeyValuePair(collection,key, value);
   }
}





int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: db [FILE]");
    return -1;
  }
  Collection dbCollection = mkCollection();
  char buffer[128];

  printWelcome();
  // Read the input file
  readInputFromFile(dbCollection, argv[1], buffer);

  // Main loop
  int choice = -1;
  while(choice != 0){
    puts("Please choose an operation");
    puts("1. Query a key");
    puts("2. Update an entry");
    puts("3. New entry");
    puts("4. Remove entry");
    puts("5. Print database");
    puts("0. Exit database");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    
    switch(choice){
    case 1:
      // Query
      printf("Enter key: ");
      readline(buffer, 128, stdin);
      puts("Searching database...\n");
      char *aStr = collectionGetValueByKey(dbCollection,buffer);
      if (aStr != NULL){
	puts("Found entry:"); 
	printf("key: %s\nvalue: %s\n",buffer, aStr);
      }else {
	 printf("Could not find an entry matching key \"%s\"!\n", buffer);
      }
      break;

    case 2:
      // Update
      printf("Enter key: ");
      readline(buffer, 128, stdin);
      puts("Searching database...\n");
      char *uValue = collectionGetValueByKey(buffer);
      if (uValue != NULL){      
	puts("Matching entry found:");
	printf("key: %s\nvalue: %s\n\n", buffer, uValue);
	char *uKey;
	strcpy(uKey, buffer); 
	puts("Enter new value: ");
	readline(buffer, 128, stdin);	 
	int success = collectionInsertKeyValuePair(dbCollection,uKey,buffer);
	if (success == 0){
	  printf ("New value: %s Inserted successfully with key: %s",buffer,uKey);
	}else{
	  puts("FAILED!");
	}
      }else{
	printf("Could not find an entry matching key \"%s\"!\n", buffer);
      }
      break;
  case 3:
    // Insert
    printf("Enter key: ");
    readline(buffer, 128, stdin);
    char* iKey;
    strcpy(iKey, buffer);
    puts("Searching database for duplicate keys...");
    int keyExist = collectionDoseKeyExist(iKey);
    if (keyExist == 0)
      {
	printf("key \"%s\" already exists!\n",iKey); 
      }else{
      puts("Key is unique!\n");
      printf("Enter value: ");
      readline(buffer, 128, stdin);
      char *iValue;
      strcpy(iValue, buffer);
      int success = collectionInsertKeyValuePair(dbCollection,iKey,iValue);
      if (success == 0){
	printf ("New value: %s Inserted successfully with key: %s",iValue,iKey);
      }else{
	puts("FAILED!");
      }
    }
    break;
    
  case 4:
    // Delete
    printf("Enter key: ");
    readline(buffer, 128, stdin);
    char* dKey;
    strcpy (dKey, buffer);
    puts("Searching database...\n");
    char *dValue = collectionRemoveKeyValuePair(dbCollection,dKey);
    if (dValue =! NULL){
      printf("Deleted the following entry:\nkey: %s\nvalue: %s\n", dKey, dValue);
    }
    else{
      printf("Could not find an entry matching key \"%s\"!\n", dKey);
    }
    
    break;
  case 5:
    // Print database
    /* cursor = list;
      while(cursor != NULL){
        puts(cursor->key);
        puts(cursor->value);
        cursor = cursor->next;
      }
      break;*/
    case 0:
      // Exit
      puts("Good bye!");
      break;
    default:
      // Please try again
      puts("Could not parse choice! Please try again");
    }
    puts("");
  }
  return 0;
}

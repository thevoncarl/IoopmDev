db: db.o Collection.o
	gcc -Wall -ggdb -o db db.o Collection.o

db.o: db.c db.h Collection.h
	gcc -c -Wall -ggdb db.c


Collection.o: Collection.c Collection.h
	gcc -c -Wall -ggdb -o Collection.c


db: db.o Collection.o
	gcc -Wall -ggdb -o db db.o Collection.o

db.o: db.c  Collection.h
	gcc -c -Wall -ggdb db.c


Collection.o: Collection.c Collection.h
	gcc -c -Wall -ggdb Collection.c


lorem.so: lorem.o
	gcc -o lorem.so lorem.o -dynamiclib

lorem.o: lorem.c redismodule.h
	gcc -fPIC -std=gnu99 -c -o lorem.o lorem.c

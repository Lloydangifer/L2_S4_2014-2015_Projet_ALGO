CC=gcc
CFLAGS=-Wall -std=c99 -g
TARGET=database

all: ${TARGET}
database: directory_generate.o directory_name_research.o main.o
	${CC} ${CFLAGS} -o ${TARGET} directory_generate.o directory_name_research.o main.o
directory_generate.o: directory_generate.c directory_generate.h
	${CC} -c ${CFLAGS} -o directory_generate.o directory_generate.c
directory_name_research.o : directory_name_research.c directory_name_research.h
	${CC} -c ${CFLAGS} -o directory_name_research.o directory_name_research.c
main.o : main.c
	${CC} -c ${CFLAGS} -o main.o main.c

clean:
	rm -f *.o

mrproper: clean
	rm -f ${TARGET}

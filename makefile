mypreprocessor: main.o comment_removal.o file_inclusion.o macro_sub.o
	cc main.o comment_removal.o file_inclusion.o macro_sub.o -o mypreprocessor

main.o: main.c
	cc -c main.c

comment_removal.o: comment_removal.c
	cc -c comment_removal.c

file_inclusion.o: file_inclusion.c
	cc -c file_inclusion.c

macro_sub.o: macro_sub.c
	cc -c macro_sub.c

clean:
	rm -f *.o mypreprocessor

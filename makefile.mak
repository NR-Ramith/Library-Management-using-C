a: user.o book.o library.o
	gcc user.o book.o library.o
user.o: user.c user_s.h
	gcc -c user.c user_s.h
book.o: book.c bk.h
	gcc -c book.c bk.h
library.o: library.c user_s.h bk.h
	gcc -c library.c user_s.h bk.h
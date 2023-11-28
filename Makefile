.PHONY: file.a main check clean 

CC = g++ -Wall -Wextra -Werror -std=c++17
OS=$(shell uname -s)
LIBS=-lgtest
LINUX=-lgtest -ggdb -pthread

all: file.a

file.a:
	$(CC) -c *.cc
	ar rcs file.a *.o
	ranlib file.a
	rm -rf *.o

main: file.a main.cc
ifeq ($(OS), Linux)
	$(CC) file.a -o test.out $(LINUX) 
else
	$(CC) file.a -o test.out $(LIBS) 
endif
	./test.out

check:
	clang-format -n *.cc
	clang-format -n *.h

clean:
	rm -f *.o *.a *.out *.txt

CC=gcc
CFLAGS=-Wall -Wextra -g -std=c99
LDFLAGS=-lm
all: test_tp3
test_tp3: pile.c file.c evaluateur.c parenthese.c test_tp3.c
$(CC) $(CFLAGS) pile.c file.c evaluateur.c parenthese.c test_tp3.c -o test_tp3 $(LDFLAGS)
clean:
rm -f test_tp3
valgrind: test_tp3
valgrind --leak-check=full --show-leak-kinds=all ./test_tp3

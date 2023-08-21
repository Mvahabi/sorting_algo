EXEC = sorting
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LDFLAGS = -lm

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$.o: %.c
	$(CC) $(CFLAGS) -o $<
	
tidy:
	rm -rf $(OBJECTS)

clean: tidy
	rm -rf $(EXEC)

format:
	clang-format -i -style=file *.[ch]
	

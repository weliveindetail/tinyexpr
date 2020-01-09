CCFLAGS = -ansi -Wall -Wshadow -O2
LFLAGS = -lm

.PHONY = all clean

all: example

example: example.c tinyexpr.c compile.c free.c eval.c
	$(CC) $(CCFLAGS) -o $@ $^ $(LFLAGS)
	./$@

.c.o:
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f *.o *.exe example

CCFLAGS = -ansi -Wall -Wshadow -O2
LFLAGS = -lm

.PHONY = all clean

all: test test_pr

test: test.c tinyexpr.c compile.c free.c eval.c
	$(CC) $(CCFLAGS) -o $@ $^ $(LFLAGS)
	./$@

test_pr: test.c tinyexpr.c compile.c free.c eval.c
	$(CC) $(CCFLAGS) -DTE_POW_FROM_RIGHT -DTE_NAT_LOG -o $@ $^ $(LFLAGS)
	./$@

.c.o:
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f *.o *.exe test_pr test

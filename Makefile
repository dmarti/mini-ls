all : mini-ls.so mini-ls

mini-ls.so : mini-ls.c
	$(CC) -o $@ -std=gnu99 -fPIC -shared $^

mini-ls : mini-ls.c
	$(CC) -o $@ -std=gnu99 $^

clean :
	rm -rf mini-ls.so mini-ls

.PHONY : all clean

tree:tree.c main.c seqqueue.c
	gcc $^ -o $@
.PHONY:
clean:
	rm tree
test:
	valgrind --tool=memcheck --leak-check=full ./tree

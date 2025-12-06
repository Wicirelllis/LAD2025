GENERATES = maze_*

all: maze_0 maze_1 maze_2 maze_3

run: maze_0 maze_1 maze_2 maze_3
	./maze_0
	./maze_1 5
	./maze_2 ' X' 5
	./maze_3 18 ' X' 5
	./maze_3 42 ' X' 5

patch: maze.c patch_1.patch patch_2.patch patch_3.patch
	cp maze.c maze_0.c
	patch -o maze_1.c maze_0.c patch_1.patch
	patch -o maze_2.c maze_1.c patch_2.patch
	patch -o maze_3.c maze_2.c patch_3.patch

compile: patch
	cc maze_0.c -o maze_0
	cc maze_1.c -o maze_1
	cc maze_2.c -o maze_2
	cc maze_3.c -o maze_3

clean:
	rm $(GENERATES)

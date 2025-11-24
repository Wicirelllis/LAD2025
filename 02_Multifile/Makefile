GENERATES = prog prog-a prog-so README liboutput_static.a liboutput.so
TRASH = *.o *~ o.*
TESTS = out-*
CFLAGS = -Wall

%.o: %.c
	cc $< $(CFLAGS) -fPIC -c -o $@

liboutput_static.a: const.o fun.o
	ar -rcs $@ $^

liboutput.so: const.o fun.o
	cc -shared $^ -o $@

prog: const.o fun.o prog.o
	cc $^ -o $@

prog-a: prog.o liboutput_static.a
	cc $< -L. -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc $< -L. -loutput_static -o $@

test: prog prog-a prog-so
	$(call test-run,0)
	$(call test-run,1,q)
	$(call test-run,3,q w e)

	$(call test-cmp,0)
	$(call test-cmp,1)
	$(call test-cmp,3)

define test-run
	./prog $2 > out-$1 2>&1
	./prog-a $2 > out-$1-a 2>&1
	./prog-so $2 > out-$1-so 2>&1
endef

define test-cmp
	cmp out-$1 out-$1-a
	cmp out-$1 out-$1-so
	cmp out-$1-a out-$1-so
endef

clean:
	rm -f $(TRASH) $(TESTS)

distclean: clean
	rm -rf $(GENERATES)

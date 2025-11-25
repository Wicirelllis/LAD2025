range: range.c
	cc range.c -O0 -g -o range

test: debug_1.gdb debug_2.gdb
	gdb --silent -x debug_1.gdb | grep @@@ > out_1
	cmp out_1_gt out_1
	gdb --silent -x debug_2.gdb | grep @@@ > out_2
	cmp out_2_gt out_2

clean:
	rm -f range out_1 out_2

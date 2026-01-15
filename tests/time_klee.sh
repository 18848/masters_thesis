# run time and save output in klee-time.txt
# also save ALL klee std out/err to klee-output.txt
/usr/bin/time -v -o klee-time.txt \
	klee --libc=uclibc main.bc &> klee-output.txt
# unable to replay the tests, no debug info nor optimisation
# clang -emit-llvm -c main.c
# recommended
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone main.c

# basic command
# klee main.bc
# for lib information
klee --libc=uclibc main.bc
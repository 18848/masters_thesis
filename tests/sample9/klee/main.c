#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <klee/klee.h>

int test4(char *buf)
{
	char *var = malloc(10);
	int i = 5;
	if (strcmp(buf, "BUG!") == 0)
	{
		free(var);
	}
	free(var);

	return 1;
}

int main(int argc, char const *argv[])
{
	char arr[10];
	klee_make_symbolic(arr, 10, "arr");
	klee_assume(arr[9] == '\0');

	test4(arr);
	return 0;
}

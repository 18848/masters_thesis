#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <owi.h>

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
	for (int i = 0; i < 10; i++) {
		arr[i] = owi_char();
	}
	owi_assume(arr[9] == '\0');

	test4(arr);
	return 0;
}

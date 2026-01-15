#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <owi.h>

char *global_string[] = {
	"string1",
	"string2",
	"string3",
	NULL,
};

int test3(char *buf)
{
	int i = 1;
	if (strcmp(buf, "BUG!") == 0)
	{
		i = 3;
		// owi_assert(0);
	}

	char c = *(global_string[i]);
	if (c == 's')
		return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	char arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = owi_char();
	}
	owi_assume(arr[9] == '\0');

	test3(arr);
	return 0;
}

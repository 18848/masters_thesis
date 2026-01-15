#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <owi.h>

int global_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int test1(char *buf)
{
	int i = 5;
	if (strcmp(buf, "BUG!") == 0)
	{
		i += 20;
		// owi_assert(0);
	}
	return global_arr[i];
}

int main(int argc, char const *argv[])
{
	char arr [10];
	for (int i = 0; i < 10; i++) {
		arr[i] = owi_char();
	}
	owi_assume(arr[9] == '\0');
	
	test1(arr);

	return 0;
}

/* 
Assert failure: false
Model:
  (model
    (symbol_0 (i32 66)) // B
    (symbol_1 (i32 85)) // U
    (symbol_2 (i32 71)) // G
    (symbol_3 (i32 33)) // !
    (symbol_4 (i32 0))
    (symbol_5 (i32 0))
    (symbol_6 (i32 0))
    (symbol_7 (i32 0))
    (symbol_8 (i32 0))
    (symbol_9 (i32 0)))
Reached problem!
 */

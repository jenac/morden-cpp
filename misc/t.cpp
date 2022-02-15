#include <stdio.h>
#define Elem(A) (sizeof(A) / sizeof((A)[0]))

int main()
{
	const char *y[] = {"%d ", "%i ", "%o ", "%x "};
	for (int ix = 0; ix < Elem(y); ++ix)
	{
		printf(y[ix], 0xD);
	}
	return 0;
}

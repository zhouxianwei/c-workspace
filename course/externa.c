#include <stdio.h>

extern int a;
extern int max(int x, int y);
int b = 12;

int main(int argc, char const *argv[])
{
	printf("%d\n", max(a, b));
	return 0;
}
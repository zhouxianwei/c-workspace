#include <stdio.h>

int a = 10;
extern int b;
int b;
int max(int x, int y){
	b = 20;
	return x > y ? x : y;
}
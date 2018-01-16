#include <stdio.h>


int main(int argc, char const *argv[])
{
	char buff[255];
	char ch;
	FILE *fp = NULL;

	fp = fopen("a.txt", "r");

	ch = fgetc(fp);
	while(ch != EOF){
		printf("%c\n", ch);
		ch = fgetc(fp);
	}
	fclose(fp);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int foo(char data[]) {
	return sizeof(data);
}

int main() {
	char a[9];
	printf("%i\n", sizeof(a));
	printf("%i\n", foo(a));

	return 0;
}
*/


int main() {
	char a[] = "12345";
	printf("%s\n", a);

	return 0;
}
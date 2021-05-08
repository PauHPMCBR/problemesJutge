#include <stdio.h>

int main() {
	char c = getchar();
	for (int i = c; i <= 'z'; ++i) {
		putchar(i);
	}
	putchar('\n');
}
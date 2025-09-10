#include <stdio.h>
#include <string.h>

void reverse_string(char *s) {
	size_t sLen = strlen(s);
		
	for (int i = 0; i < sLen / 2; i++) {
		char temp = s[i];
		s[i] = s[sLen - i - 1];
		s[sLen - i - 1] = temp;
	}

}


int main (int argc, char **argv) {
	char text[] = "I love coding";
	reverse_string(text);
	printf("reverse_string = %s\n", text);

	return 0;
}

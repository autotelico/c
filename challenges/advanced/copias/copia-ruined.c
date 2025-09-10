#include <stdio.h>
#include <string.h>

char *strtoken(char *s, const char *delimiter) {
	static char *static_s;
	static int offset;

	if (s != NULL) {
		static_s = s;
		offset = 0;
	}

	char *start = static_s + offset;

	while (static_s[offset] != '\0') {
		int is_delim = 0;
		for (int j = 0; delimiter[j] != '\0'; j++) {
			if (delimiter[j] == static_s[offset]) {
				offset++;
				is_delim = 1;
				break;
			}
		}
		if (!is_delim) break;
	}

	while (static_s[offset] != '\0') {
		char curr_char = static_s[offset];
		for (int j = 0; delimiter[j] != '\0'; j++) {
			char delim_char = delimiter[j];
			if (curr_char == delim_char) {
				static_s[offset] = '\0';
				offset++;
				return start;
			}
		}
		offset++;
	}

	return start;
}

int main(void) {
	char text[] = "something amazing";
	const char* delim = " ";

	char *token = strtoken(text, delim);

	while (token != NULL) {
		printf("%s\n", token);
		token = strtoken(NULL, delim);
	}


	return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strtoken(char *s, const char *delimiter) {
	static char *static_s;
	static int offset;
	static int last_token;

	if (s != NULL) {
		static_s = s;
		offset = 0;
		last_token = 0;
	}

	while (static_s[offset] != '\0') {
		int is_delim = 0;
		
		for (int i = 0; delimiter[i] != '\0'; i++) {
			if (delimiter[i] == static_s[offset]) {
				offset++;
				is_delim = 1;
				break;
			}
		}

		if (!is_delim) break;
	}

	char *start = static_s + offset;

	if (last_token) return NULL;

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

	if (static_s[offset] == '\0') {
		last_token = 1;
	}

	return start;
}

int main(void) {
	char text[] = "    something amazing to see  ";
	const char* delim = " ";

	char *token = strtoken(text, delim);

	while (token != NULL) {
		printf("%s\n", token);
		token = strtoken(NULL, delim);
	}


	return 0;
}

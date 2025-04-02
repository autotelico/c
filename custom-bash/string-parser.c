#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parseCmd(char cmd[]) {
	if (strcmp(cmd, "ls") == 0) {
		printf("Listing items\n");
	}
}

void parseString(char text[]) {
	
	char* token = strtok(text, " ");
	parseCmd(token);
	printf("%s\n", token);
	while ((token = strtok(NULL, " "))) {
		printf("%s\n", token);
		parseCmd(token);
	}
}

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		parseCmd(argv[i]);
	}
	
	return 0;
}

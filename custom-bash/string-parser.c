#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void parseCmd(char cmd[]) {
	DIR* fd;
	struct dirent* in_file;

	if (strcmp(cmd, "ls") == 0) {
		printf("Listing items\n");
		fd = opendir(".");
		if (fd == NULL) {
			fprintf(stderr, "Error: failed to open directory");
			exit(1);
		}

		while ((in_file = readdir(fd))) {
			printf("%s\n", in_file->d_name);
		}
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

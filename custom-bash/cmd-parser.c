#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void runLs() {
	DIR* fd;
	struct dirent* in_file;
	fd = opendir(".");
	if (fd == NULL) {
		fprintf(stderr, "Error: failed to open directory");
		exit(1);
	}

	while ((in_file = readdir(fd))) {
		if (in_file->d_name[0] != '.') {
			printf("%s", in_file->d_name);
		}
	}
	closedir(fd);
}

void runCat(char* filename) {
	FILE *fptr;
	char content[100];
	fptr = fopen(filename, "r");
	while (fgets(content, 100, fptr)) {
		printf("%s\n", content);
	}
	fclose(fptr);
}

void parseCmd(char** cmd) {
	// ls
	if (strcmp(cmd[0], "ls") == 0) {
		runLs();
	}

	if (strcmp(cmd[0], "cat") == 0) {
		runCat(cmd[1]);
	}

	// cat

}

void parseTokens(char text[]) {
}

int main(int argc, char** argv) {
	parseCmd(&argv[1]);
	
	return 0;
}


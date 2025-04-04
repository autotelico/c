#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void runRm(char** filenames, int fileCount) {
	for (int i = 0; i < fileCount; i++) {
		int result = remove(filenames[i]);
		printf("%d\n", result);
	}
}

void runEcho(char** stringArray, int size) {
	for (int i = 1; i < size - 1; i++) {
		printf("%s ", stringArray[i]);
	}
	printf("\n");
}

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

void parseCmd(char** cmd, int size) {
	// echo
	if (strcmp(cmd[0], "echo") == 0) {
		
		runEcho(cmd, size);
	}
	
	// ls
	if (strcmp(cmd[0], "ls") == 0) {
		runLs();
	}

	// cat
	if (strcmp(cmd[0], "cat") == 0) {
		runCat(cmd[1]);
	}

	// rm
	if (strcmp(cmd[0], "rm") == 0) {
		runRm(cmd + 1, size - 2);
	}

}

void parseTokens(char text[]) {
}

int main(int argc, char** argv) {
	parseCmd(&argv[1], argc);
	
	return 0;
}


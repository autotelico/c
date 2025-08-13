#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

void runFind(char **args, int argSize) {
	DIR *dir;
	struct dirent *file;
	char *dirname = args[1];
	dir = opendir(dirname);

	if (dir == NULL) {
		fprintf(stderr, "Failed to open directory");
		exit(1);
	}	

	if (dirname == NULL) {
		fprintf(stderr, "No path was provided");
		exit(1);
	}

	char *fileToFind;
	
	for (int i = 1; i < argSize; i++) {
		char *currentArg = args[i];
		if (strcmp(currentArg, "-name") == 0) {
			fileToFind = args[i + 1];
			if (fileToFind != NULL) {
				break;
			}
		}
	}

	// if there is a file to find:
	if (fileToFind != NULL) {
		struct stat pathStat;
		char fullPath [PATH_MAX];
		while ((file = readdir(dir))) {
			printf("%s\t", file->d_name);
			char *rPath = realpath(file->d_name, fullPath);
			if (strcmp(fileToFind, file->d_name) == 0) {
				printf("%s\n", fullPath);
				return;
			}
			stat(fullPath, &pathStat);
			if (S_ISDIR(pathStat.st_mode) == 1) {
				// File is a directory. Recursively search it
				// Continue from here
				runFind(args, argSize);
			}
			
		}
	} else {
		fprintf(stderr, "No file to be searched was provided.");
		exit(1);
	}

	// in case nothing else works...
	perror("File not found error");
	printf("\n");
	closedir(dir);
}

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

void runLs(char* args[], int argsSize) {
	DIR* fd;
	struct dirent* in_file;
	fd = opendir(".");
	if (fd == NULL) {
		fprintf(stderr, "Error: failed to open directory");
		exit(1);
	}

	// if there are options
	int optAll = 0; // -a
	
	for (int i = 0; i < argsSize; i++) {
		if (strcmp(args[i], "-a") == 0) {
			optAll = 1;
			break;
		}
	}

	while ((in_file = readdir(fd))) {
		if (optAll == 0) {
			if (in_file->d_name[0] == '.') {
				continue;
			}
		}
		printf("%s\t", in_file->d_name);
	}
	printf("\n");

	closedir(fd);
}

void runCat(char* filename) {
	FILE *fptr;
	char content[100];
	fptr = fopen(filename, "r");
	while (fgets(content, 100, fptr)) {
		printf("%s", content);
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
		runLs(cmd, size - 1);
	}

	// cat
	if (strcmp(cmd[0], "cat") == 0) {
		runCat(cmd[1]);
	}

	// rm
	if (strcmp(cmd[0], "rm") == 0) {
		runRm(&cmd[1], size - 2);
	}

	if (strcmp(cmd[0], "find") == 0) {
		 runFind(cmd, size);
	}

}

int main(int argc, char** argv) {
	parseCmd(&argv[1], argc);
	
	return 0;
}


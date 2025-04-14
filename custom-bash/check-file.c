#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int isDirectory(char *path) {
	struct stat path_stat;
	stat(path, &path_stat);
	int result = S_ISDIR(path_stat.st_mode);
	printf("%d\n", (int)path_stat.st_mode);
	printf("%d\n", result);
	return result;
}

int main(int argc, char **argv) {
	isDirectory(argv[1]);
}

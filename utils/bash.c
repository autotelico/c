#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **runGrep(char **args, int argSize, char **text) {
	char *regex = args[1];
	
}

int main(int argc, char **argv) {
	char *command = argv[1];
	
	//*
	if (strcmp(command, "grep") == 0) {
		runGrep(argv, argc);
	}

	// */
	return 0;
}

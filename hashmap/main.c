#include <stdio.h>
#include "hashmap.h"

int main(int argc, char **argv) {
	char *text = "whatever";
	int hashVal = hash(text, 16);
	printf("%d\n", hashVal);

	HashMap *hashmap = create_hashmap();
	hashmap_put(hashmap, "paçoca", "é bom");

	printBucketKeys(hashmap);

	return 0;
}

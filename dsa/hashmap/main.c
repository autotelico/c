#include <stdio.h>
#include "hashmap.h"

int main(int argc, char **argv) {
	HashMap *hashmap = create_hashmap();
	hashmap_put(hashmap, "paçoca", "é bom");
	///*
	hashmap_put(hashmap, "outro", "valor");
	hashmap_put(hashmap, "a test", "to certify quality");
	hashmap_put(hashmap, "a cookie", "to certify quality");
	hashmap_put(hashmap, "a batter", "to certify quality");
	hashmap_put(hashmap, "a palindrome", "to certify quality");
	hashmap_put(hashmap, "awesomeness", "to certify quality");
	hashmap_put(hashmap, "a bazzoka boy", "to certify quality");
	hashmap_put(hashmap, "a crapper", "to certify quality");
	hashmap_put(hashmap, "a sniper", "to certify quality");
	hashmap_put(hashmap, "a ajsdiosjiofdshofs", "to certify quality");
	hashmap_put(hashmap, "what is this? a test", "to certify quality");
	//*/
	//char *val = hashmap_get(hashmap, "paçoca");
	//printf("val = %s\n", val);
	
	printBuckets(hashmap);

	return 0;
}

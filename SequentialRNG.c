#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int boundedRand(int min, int max);

int main(int argc, char* argv[]) {
	time_t t;
	unsigned int i = 0;
	unsigned int supersteps = 0;
	int currentInt = 0;
	int newInt = 0;
	int target = 10;
	srand(time(&t));
	for (i = 0; currentInt != target; i++) {
		newInt = boundedRand(1, target);
		if (newInt == currentInt + 1) {
			currentInt = newInt;
		}
		else {
			currentInt = 0;
		}
		if (i % 1000000 == 0 && i != 0) {
			printf("%u steps\n", i);
			if (supersteps > 0) {
				printf("%u supersteps\n", supersteps);
			}
		}
		if (i == 4294967295) {
			i = 0;
			supersteps++;
		}
		if (currentInt == target) {
			printf("Complete. Total steps: %u\n", i);
			if (supersteps > 0) {
				printf("Total supersteps: %u", supersteps);
			}
		}
	}
	return 0;
}

int boundedRand(int min, int max) {
	int output;
	output = ((rand() % max) + min);
	return output;
}
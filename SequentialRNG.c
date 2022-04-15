#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int boundedRand(int min, int max);

int main(int argc, char* argv[]) {
	int target = 10;
	int loops = 100;
	int l;
	time_t t;
	long long i = 0;
	//unsigned int supersteps = 0;
	int currentInt = 0;
	int newInt = 0;
	FILE* out;
	//long long test = 2;
	out = fopen("output.txt", "a");
	if (out == NULL) {
		printf("Failed to open output file.\n");
		exit(1);
	}
	srand(time(&t));
	/*for (i = 0; i < 62; i++) {
		test = pow(2, i);
		printf("%lld\n", test);
	}*/
	for (l = 0; l < loops; l++) {
		for (i = 0; currentInt != target; i++) {
			newInt = boundedRand(1, target);
			if (newInt == currentInt + 1 && newInt != 1) {
				currentInt = newInt;
				//printf("%d\n", currentInt);
			}
			else if (newInt == 1) {
				currentInt = 1;
				//printf("%d\n", currentInt);
			}
			else {
				currentInt = 0;
			}
			if (i % 1000000 == 0 && i != 0) {
				printf("%lld steps\n", i);
				/*if (supersteps > 0) {
					printf("%u supersteps\n", supersteps);
				}*/
			}
			/*if (i == 4294967295) {
				i = 0;
				supersteps++;
			}*/
			if (currentInt == target) {
				printf("Complete. Total steps: %lld\n", i + 1);
				/*if (supersteps > 0) {
					printf("Total supersteps: %u", supersteps);
				}*/
			}
		}
		currentInt = 0;
		fprintf(out, "%lld\n", i);
	}
	fclose(out);
	return 0;
}

int boundedRand(int min, int max) {
	int output;
	output = ((rand() % max) + min);
	return output;
}

/*
 * Generate a frequency table based on a given input file
 * Pipe it to some output file of your choice
 * ./freq my_file >> my_frequency.txt
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Usage: ./freq file_to_analyze\n");
		return -1;
	}

	FILE *pInputFile;
	int c, c2;
	long long total = 0;
	long long count[256];
	char line[71];

	//initialize everything to 0
	for(c = 0; c < 256; c++) {
		count[c] = 0;
	}

	if((pInputFile = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File Not Found!!!1\n");
		exit(-1);
	}
	
	while((c = fgetc(pInputFile)) != EOF) {
		total++;
		count[c]++;
	}

	for(c = 0; c < 256; c++) {
		snprintf(line, 70, "%.70lf\n", ((float)count[c] / (float)total));
		for(c2 = 68; c2; c2--) {
			if(line[c2] != '0' && line[c2] != '.') {
				break;
			}
		}
		line[++c2] = 0;
		printf("%s\n", line);
	}

	fclose(pInputFile);
	return 0;

}
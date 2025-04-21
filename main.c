/*
 * kilobyte-disk 2025
 * hex-generator
 *
 * Purpose:
 * A simple utility to list all hex numbers in between
 * two given hex numbers.
 *
 * ARGUMENTS:
 * hex-generate 0x0000 0x0010 filetowrite
 */

#define MAX_ARG_LEN 100
#define MAX_FILENAME 250

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if (argc < 4) {
		printf("ERROR: Expected 3 arguments (hex_start, hex_end, file_to_write), got %i.\n", (argc - 1));
		return 1;
	}

	/* Read args */
	char hex_start[MAX_ARG_LEN];
	char hex_end[MAX_ARG_LEN];
	char filename[MAX_FILENAME];
	
	memset(hex_start, 0, MAX_ARG_LEN);
	memset(hex_end, 0, MAX_ARG_LEN);
	memset(filename, 0, MAX_FILENAME);

	int arg_len = strlen(argv[1]);
	if (arg_len > MAX_ARG_LEN) {
		printf("ERROR: Maximum argument length for hex_start is 100 digits.\n");
		return 1;
	}

	strncpy(hex_start, argv[1], arg_len);
	hex_start[arg_len + 1] = '\0';


	arg_len = strlen(argv[2]);
	if (arg_len > MAX_ARG_LEN) {
		printf("ERROR: Maximum argument length for hex_end is 100 digits.\n");
		return 1;
	}

	strncpy(hex_end, argv[2], arg_len);
	hex_end[arg_len + 1] = '\0';


	arg_len = strlen(argv[3]);
	if (arg_len > MAX_ARG_LEN) {
		printf("ERROR: Maximum argument length for file_to_write is 250 chars.\n");
		return 1;
	}

	strncpy(filename, argv[3], arg_len);
	filename[arg_len + 1] = '\0';

	
	/* Convert hex_start, hex_end to hex long integers */
	char *endptr;

	long int start = strtol(hex_start, &endptr, 16);
	if (*endptr != '\0') {
		printf("ERROR: Invalid argument #1. Expected hexadecimal.\n");
		return 1;
	}

	long int end = strtol(hex_end, &endptr, 16);
	if (*endptr != '\0') {
		printf("ERROR: Invalid argument #2. Expected hexadecimal.\n");
		return 1;
	}

	printf("Got range: %X -> %X\n", start, end);

	int count_direction = 1;
	if (start > end) {
		printf("Counting backwards!\n");
		count_direction = -1;
	}

	/* Flush file if it already exists */
	printf("%s\n", filename);
	
	FILE *check_file = fopen(filename, "w");
	if (check_file == NULL) {
		printf("ERROR: Could not open file.\n");
	}
	fclose(check_file);

	FILE *file = fopen(filename, "a");
	if (file == NULL) {
		printf("ERROR: Could not open %s!\n", filename);
	}

	fprintf(file, "# Hex digits from 0x%X -> 0x%X.", start, end);

	/* Begin counting */
	long int lines = 0;
	while (start != end) {
		fprintf(file, "\n%X", start);
		
		start += count_direction;
		lines++;
	}

	fprintf(file, "\n%X", end);

	fclose(file);

	printf("Wrote %d lines.\n", lines);

	return 0;
}

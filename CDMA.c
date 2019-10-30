#include <stdio.h>
#define CHIP_SEQUENCE 8
#define PROCESS 4

int t[PROCESS][CHIP_SEQUENCE];
int r[PROCESS][CHIP_SEQUENCE];

int main() {
	int i, j;
	int num[PROCESS] = { 0,0,0,0 };
	char temp = 'q';

	printf("Enter the chip sequence\n");
	for (i = 0; i < PROCESS; i++) {
		for (j = 0; j < CHIP_SEQUENCE; j++) {
			scanf("%d", &t[i][j]);
			r[i][j] = t[i][j];
		}
	}

	for (i = 0; i < PROCESS; i++) {
		printf("Do you want to transmit %d ? (y/n)\n", i);
		scanf("%c", &temp);
		if (temp) {
			num[i] = 1;
		}
	}

	for (int i = 0; i < PROCESS; i++) {
		printf("%d\n", num[i]);
	}
}
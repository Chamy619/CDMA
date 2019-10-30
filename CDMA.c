#include <stdio.h>
#define CHIP_SEQUENCE 8
#define PROCESS 4

int t[PROCESS][CHIP_SEQUENCE];
int r[PROCESS][CHIP_SEQUENCE];
int trans[PROCESS] = { 0,0,0,0 };
int recei[PROCESS] = { 0,0,0,0 };


//join ��� ����
void join(int transmit[]) {
	int i, j;
	
	for (i = 0; i < PROCESS; i++) {
		if (trans[i] == 1) {
			for (j = 0; j < CHIP_SEQUENCE; j++) {
				transmit[j] += t[i][j];
			}
		}
	}
}

//join�� chip sequence�� r0,r1,r2,r3�� ���� �ش� ���� ���ԵǾ����� �ƴ��� ����
//-1�̸� �ݴ� ��, 0�̸� ���� �Ǿ� ���� ����, 1�̸� ���� �Ǿ� ����
int receiver(int transmit[], int num) {
	int i;
	int temp[CHIP_SEQUENCE];
	int sum = 0;
	int result = 0;

	for (i = 0; i < CHIP_SEQUENCE; i++) {
		temp[i] = transmit[i] * r[num][i];
		sum += temp[i];
	}

	result = sum / CHIP_SEQUENCE;

	return result;
}

int main() {
	int i, j;
	char temp = 'q';
	int transmit[CHIP_SEQUENCE];

	//chip sequence �Է�
	printf("Enter the chip sequence\n");
	for (i = 0; i < PROCESS; i++) {
		for (j = 0; j < CHIP_SEQUENCE; j++) {
			scanf("%d", &t[i][j]);
			r[i][j] = t[i][j];
			transmit[j] = 0;
		}
	}
	getchar();

	//�������� �ϴ� ��ȣ ����
	for (i = 0; i < PROCESS; i++) {
		printf("Do you want to transmit %d ? (y/n)\n", i);
		scanf("%c", &temp);
		if (temp == 'y') {
			trans[i] = 1;
		}
		while (temp = getchar() != '\n' && temp != EOF);
	}
	printf("\n");

	//join ���� ���
	join(transmit);
	
	printf("receive number : ");
	//recei �迭�� ���� ���� �� � ���� ����ִ��� ���
	for (i = 0; i < PROCESS; i++) {
		recei[i] = receiver(transmit, i);
		if (recei[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");


}
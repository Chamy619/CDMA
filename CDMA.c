#include <stdio.h>
#define CHIP_SEQUENCE 8
#define PROCESS 4

int t[PROCESS][CHIP_SEQUENCE];
int r[PROCESS][CHIP_SEQUENCE];
int trans[PROCESS] = { 0,0,0,0 };
int recei[PROCESS] = { 0,0,0,0 };


//join 기능 수행
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

//join한 chip sequence를 r0,r1,r2,r3를 통해 해당 값이 포함되었는지 아닌지 검출
//-1이면 반대 값, 0이면 포함 되어 있지 않음, 1이면 포함 되어 있음
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

	//chip sequence 입력
	printf("Enter the chip sequence\n");
	for (i = 0; i < PROCESS; i++) {
		for (j = 0; j < CHIP_SEQUENCE; j++) {
			scanf("%d", &t[i][j]);
			r[i][j] = t[i][j];
			transmit[j] = 0;
		}
	}
	getchar();

	//보내고자 하는 번호 선택
	for (i = 0; i < PROCESS; i++) {
		printf("Do you want to transmit %d ? (y/n)\n", i);
		scanf("%c", &temp);
		if (temp == 'y') {
			trans[i] = 1;
		}
		while (temp = getchar() != '\n' && temp != EOF);
	}
	printf("\n");

	//join 값을 계산
	join(transmit);
	
	printf("receive number : ");
	//recei 배열에 전송 받은 후 어떤 값이 들어있는지 계산
	for (i = 0; i < PROCESS; i++) {
		recei[i] = receiver(transmit, i);
		if (recei[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");


}
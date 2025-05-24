#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int get_avg(int scores[], int n);

void get_square(int scores[], int n);


void printSeats(int seats[SIZE][SIZE]);
int reserve(int seats[SIZE][SIZE], int row, int col);
int isValid(int row, int col);

int main() {
    // int scores[5] = {1,2,3,4,5};
    // printf("%d",get_avg(scores,5));

    // int s[5][5];
    // srand((unsigned)time(NULL));
    //
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         s[i][j] = rand() % 100;
    //         printf("%02d ", s[i][j]);
    //     }
    //     printf("\n");
    // }
    //
    // int max = s[0][0], min = s[0][0];
    // int max_i = 0, max_j = 0, min_i = 0, min_j = 0;
    //
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         if (s[i][j] > max) {
    //             max = s[i][j];
    //             max_i = i;
    //             max_j = j;
    //         }
    //         if (s[i][j] < min) {
    //             min = s[i][j];
    //             min_i = i;
    //             min_j = j;
    //         }
    //     }
    // }
    //
    // printf("\n최댓값: %d (index: [%d][%d])\n", max, max_i, max_j);
    // printf("최솟값: %d (index: [%d][%d])\n", min, min_i, min_j);

    // int arr[5][5] = {
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 1, 0, 1},
    //     {1, 1, 0, 1, 1},
    //     {1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1},
    // };
    //
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         printf("%d ",arr[j][i]);
    //     }
    //     printf("\n");
    // }
    //
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         printf("%d ", arr[j][i] == 0 ? 1 : 0);
    //     }
    //     printf("\n");
    // }

    int seats[SIZE][SIZE] = {0}; // 0: 빈 자리, 1: 예약된 자리
    int row, col;
    char answer;

    while (1) {
        printf("좌석을 예약하시겠습니까?(y 또는 n) ");
        scanf(" %c", &answer);

        if (answer == 'n' || answer == 'N') {
            break;
        }

        printSeats(seats);

        printf("몇 행 몇 열 좌석을 예약하시겠습니까? (예: 1 1) ");
        scanf("%d %d", &row, &col);

        if (!isValid(row, col)) {
            printf("잘못된 입력입니다. 1부터 10까지 입력하세요.\n");
            continue;
        }

        int result = reserve(seats, row - 1, col - 1);
        if (result == 1) {
            printf("예약되었습니다.\n");
            printSeats(seats);
        } else {
            printf("이미 예약된 자리입니다.\n");
        }
    }

    printf("프로그램을 종료합니다.\n");
    return 0;
}

int get_avg(int scores[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }

    return sum / n;
}

void get_square(int scores[], int n) {
    for (int i = 0; i < n; i++) {
        scores[i] = scores[i] * scores[i];
    }
}

void printSeats(int seats[SIZE][SIZE]) {
    printf("-----------------------------------------\n");
    printf("    ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
}

int reserve(int seats[SIZE][SIZE], int row, int col) {
    if (seats[row][col] == 0) {
        seats[row][col] = 1;
        return 1;
    }
    return 0;
}

int isValid(int row, int col) {
    return row >= 1 && row <= SIZE && col >= 1 && col <= SIZE;
}

/*
 * 본 코드는 2025591010 김현민 작성하였습니다.
 */

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // p263 구구단
    // int n;
    // while 구구단 출력
    // int i = 1;
    // scanf("%d",&n);
    // while (i <= 9) {
    //     printf("%d x %d = %d\n", n, i, n * i);
    //     i++;
    // }

    // do {
    //     printf("2에서 9까지 숫자만 입력하세요. 종료시 0 : ");
    //     scanf("%d",&n);
    //
    //     if (n <= 9 && n >= 2) {
    //         printf("%d단 입니다.\n", n);
    //         for (int i = 1; i <= 9; i++) {
    //             printf("%d x %d = %d\n", n, i, n * i);
    //         }
    //     }
    //     else
    //         printf("잘못되었습니다. 다시 입력하세요\n");
    // }while (n != 0);
    //
    //
    // // 홀수의 합
    // int num, sum = 0;
    //
    // printf("정수를 입력하세요: ");
    // scanf("%d", &num);
    //
    // for (int i = 1; i <= num; i++) {
    //     if (i % 2 != 0) {
    //         sum += i;
    //     }
    // }
    //
    // printf("1부터 %d까지의 홀수의 합: %d\n", num, sum);

    // int n = 0, grade = 0;
    // double sum = 0 , average;
    //
    // while (grade >= 0) {
    //     scanf("%d", &grade);
    //     sum += grade;
    //     n++;
    // }
    // sum = sum / n;
    // n--;
    // average = sum / n;
    // printf("성적의 평균 %f",average);


    // int hour = 10, num = 1;
    //
    // while (hour <= 7) {
    //     num = num * 4;
    //     hour++;
    // }
    // printf("세균수 : %d", num);
    //

    // srand((unsigned)time(NULL));
    // int answer = rand() % 100;
    // int guess;
    // int tries = 0;
    //
    // do {
    //     scanf("%d", &guess);
    //     if (guess > answer) printf("High\n");
    //     else if (guess < answer) printf("Low\n");
    //     tries++;
    //
    // }while (answer != guess);
    // printf("축하합니다. 시도횟수 = %d",tries);

    // do {
    //     printf("2에서 9까지 숫자만 입력하세요. 종료시 0 : ");
    //     scanf("%d",&n);
    //
    //     if (n <= 9 && n >= 2) {
    //         printf("%d단 입니다.\n", n);
    //         for (int i = 1; i <= 9; i++) {
    //             printf("%d x %d = %d\n", n, i, n * i);
    //         }
    //     }
    //     else
    //         printf("잘못되었습니다. 다시 입력하세요\n");
    // }while (n != 0);

    // int n, factorial = 1;
    //
    // scanf("%d", &n);
    //
    // printf("%d! = ", n);
    // for (int i = n; i > 0; i--) {
    //     factorial *= i;
    //     printf("%d", i);
    //     if (i > 1) {
    //         printf(" * ");
    //     }
    // }
    // printf(" = %d\n", factorial);

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 1; j < 10; j++) {
    //         printf(j % 2 == 0 ? "*" : "-");
    //     }
    //     printf("\n");
    // }


    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 2; j <= 9; j++) {
    //         printf("%2d\t", j * i);
    //     }
    //     printf("\n");
    // }

    int i, j;

    printf("    ");
    for (j = 2; j <= 9; j++) {
        printf("%4d", j);
    }
    printf("\n");

    for (i = 1; i <= 9; i++) {
        printf("%2d ", i);
        for (j = 2; j <= 9; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}

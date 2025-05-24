#include <stdio.h>
#include <stdlib.h>
#define print printf

void sub() {
    static int scnt = 0;
    int acnt = 0;
    print("%d", scnt);
    print("%d", acnt);

    scnt++;
    acnt++;
}


int fect(int n) {
    if (n == 1)
        return 1;
    else
        return n * fect(n - 1);
}


int main() {
    // sub();sub();sub();
    // print("%d",fect(5));

    // int scores[5];
    // int temp = 10;
    //
    // for (int i = 0; i < 5; i++) {
    //     scores[i] = temp;
    //     temp += 10;
    // }
    //
    // for (int i = 0; i < 5; i++) {
    //     print("%d\n",scores[i]);
    // }

    // int scores[5];
    // int sum = 0;
    // int avg = 0;
    //
    // for (int i = 0; i < 5; i++) {
    //     scanf("%d", &scores[i]);
    // }
    //
    // for (int i = 0; i < 5; i++)
    //     sum += scores[i];
    //
    //
    // // 버블 정렬
    // int temp = 0;
    // for (int i = 0; i < sizeof(scores) / 4 - 1; i++) {
    //     for (int j = 0; j < sizeof(scores) / 4 - 1 - i; j++) {
    //         if (scores[j] > scores[j + 1]) {
    //             temp = scores[j];
    //             scores[j] = scores[j + 1];
    //             scores[j + 1] = temp;
    //         }
    //     }
    // }
    //
    // for (int i = 0; i < 5; i++) {
    //     print("%d ",scores[i]);
    // }
    //
    // print("최고 점수 %d\n", scores[5-1]);
    // print("최저 점수 %d\n", scores[0]);
    // avg = sum / 5;
    // print("평균 %d\n", avg);
    // print("평균 %d\n", avg);

    // int arr[2] = {0};
    //
    // for (int i = 0; i < 10000; i++) {
    //     ++arr[rand()% 3];
    // }
    //
    // for (int i = 0; i < 2; i++) {
    //     print("%3d %3d\n", i, arr[i]);
    // }


    char ans1;
    int ans2;
    int seats[10] = {0};

    while (1) {
        print("좌석을 예약하시겠습니까? y or n");

        scanf("%c", &ans1);

        if (ans1 =='n') break;

        print("-------------------------\n");
        for (int i = 1; i <= 10; i++) {
            print(" %d ", i);
        }
        print("\n-------------------------\n");

        for (int i = 0; i < 10; i++) {
            print("  %d",seats[i]);
        }
        print("\n");

        print("몇 번쨰 좌석을 예약하시겠습니까?");
        scanf("%d", &ans2);

        if (seats[ans2-1] == 0) {
            seats[ans2-1] = 1;
            print("예약되었습니다.");
        }else print("이미 예약된 자리입니다.");
    }

    return 0;
}

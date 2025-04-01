/*
 * 본 코드는 2025591010 김현민 작성하였습니다.
 */

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // p230
    // int n = 0;
    // scanf("%d",&n);
    // printf("홀짝 판별\n");
    //
    // if (n % 2 == 0) printf("짝수\n");
    // else printf("홀수\n");
    //
    // int s = 0;
    // scanf("%d", &s);
    //
    // // else if
    // if (s >= 90)
    //     printf("A\n");
    // else if (s >= 80)
    //     printf("B\n");
    //
    // else if (s >= 70)
    //     printf("C\n");
    //
    // else if (s >= 60)
    //     printf("D\n");
    //
    // else printf("F\n");
    //
    // // 삼항연산자
    // printf("%c\n", s >= 90 ? 'A' : s >= 80 ? 'B' : s >= 70 ? 'C' : s >= 60 ? 'D' : 'F');
    //
    // // switch case
    // switch (s / 10) {
    //     case 10:
    //     case 9:
    //         printf("A\n");
    //         break;
    //     case 8:
    //         printf("B\n");
    //         break;
    //     case 7:
    //         printf("C\n");
    //         break;
    //     case 6:
    //         printf("D\n");
    //         break;
    //     default: printf("F\n");
    // }

    // int x, y, res = 0;
    // char op;
    //
    // scanf("%d %c %d", &x, &op, &y);
    //
    // switch (op) {
    //     case '+':
    //         res = x + y;
    //     break;
    //
    //     case '-':
    //         res = x - y;
    //     break;
    //
    //     case '*':
    //         res = x * y;
    //     break;
    //
    //     case '/':
    //         if (y != 0) {
    //             res = x / y;
    //             int temp = x % y;
    //             if (temp != 0) {
    //                 printf("%d %c %d = %d, 나머지 = %d\n", x, op, y, res, temp);
    //             }
    //         }
    //     break;
    //
    //     case '%':
    //         res = x % y;
    //     break;
    //
    //     default:
    //         printf("지원되지 않음\n");
    // }
    // printf("%d %c %d = %d\n", x, op, y, res);

    // 가위바위보
    // int n;
    //
    // srand(time(NULL));
    //
    // printf("(1: 가위, 2: 바위, 3: 보) 중에서 하나를 선택하시오: ");
    // scanf("%d", &n);
    //
    // int computer = rand() % 3 + 1;
    //
    // if (computer == 1)
    //     printf("컴퓨터는 가위를 선택하였습니다.\n");
    // else if (computer == 2)
    //     printf("컴퓨터는 바위를 선택하였습니다.\n");
    // else
    //     printf("컴퓨터는 보를 선택하였습니다.\n");
    //
    // if ((n == 1 && computer == 3) || (n == 2 && computer == 1) || (n == 3 && computer == 2))
    //     printf("사용자가 이겼습니다!\n");
    // else if (n == computer)
    //     printf("비겼습니다.\n");
    // else
    //     printf("사용자가 졌습니다.\n");

    // 복권
    int n, l, u_tens, u_units, l_tens, l_units;

    srand(time(NULL));

    l = rand() % 92 + 8;

    printf("복권 번호를 입력하시오 (0에서 99 사이): ");
    scanf("%d", &n);

    u_tens = n / 10, u_units = n % 10,l_tens = l / 10,l_units = l % 10;

    printf("당첨번호는 %d 입니다.\n", l);

    if (n == l)
        printf("상금은 100만원입니다.\n");
    else if (u_tens == l_tens || u_tens == l_units || u_units == l_tens || u_units == l_units)
        printf("상금은 50만원입니다.\n");
    else
        printf("상금은 없습니다.\n");

    return 0;
}

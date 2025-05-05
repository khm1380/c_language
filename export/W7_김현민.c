#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // int x,y,ans;
    // srand(time(NULL));
    //
    //
    // while (1) {
    //     x = rand() % 100;
    //     y = rand() % 100;
    //     printf("%d %d\n", x, y);
    //     scanf("%d", &ans);
    //
    //     if (x + y == ans) {
    //         printf("정답\n");
    //         break;
    //     } else {
    //         printf("틀렸습니다.\n");
    //     }
    //
    // }


    // int n, m, gcd = 1, lcm;
    //
    // printf("두 정수를 입력하세요: ");
    // scanf("%d %d", &n, &m);
    //
    // // 최대공약수
    // for (int i = 1; i <= (n < m ? n : m); i++) {
    //     if (n % i == 0 && m % i == 0) {
    //         gcd = i;
    //     }
    // }
    //
    // // 최소공배수
    // for (int i = (n > m ? n : m);; i++) {
    //     if (i % n == 0 && i % m == 0) {
    //         lcm = i;
    //         break;
    //     }
    // }
    //

    // for (int i = 1; i <= n / 2; i++) {
    //     if (n % i == 0 && m % i == 0) {
    //         gcd = i;
    //     }
    // }
    // if (m % n == 0) {
    //     gcd = n;
    // }
    //
    // // 최소공배수
    // lcm = (n * m) / gcd;

    // printf("최대공약수: %d\n", gcd);
    // printf("최소공배수: %d\n", lcm);
    //
    // int n;
    //
    // printf("숫자를 입력하세요: ");
    // scanf("%d", &n);
    //
    // printf("%d의 약수: ", n);
    // for (int i = 1; i <= n; i++) {
    //     if (n % i == 0) {
    //         printf("%d ", i);
    //     }
    // }
    // printf("\n");

//     int n = 0;
//     scanf("%d", &n);
//
//     if (n <= 1) {
//         printf("소수가 아님\n");
//     } else {
//         int is_prime = 1;
//         for (int i = 2; i * i <= n; i++) {
//             if (n % i == 0) {
//                 is_prime = 0;
//                 break;
//             }
//         }
//         if (is_prime) {
//             printf("소수\n");
//         } else {
//             printf("소수가 아님\n");
//         }
// }
    // 피보나치수열

    // int n;
    //
    // scanf("%d", &n);
    //
    //
    // int a = 0, b = 1, c;
    //
    // printf("피보나치 수열: ");
    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", a);
    //     c = a + b;
    //     a = b;
    //     b = c;
    // }
    // printf("\n");

    // 팰린드롬 나올 가능성도 있음.

    // int n, rev = 0;
    //
    // printf("정수를 입력하세요: ");
    // scanf("%d", &n);
    //
    // do {
    //     rev = rev * 10 + n % 10;
    //     n /= 10;
    // }while (n != 0);
    //
    // printf("%d\n", rev);

    // p 310
    int sum = 0;
    int n = 1;
    int target;
    if (scanf("%d", &target) != 1 || target <= 0) {
            printf("유효한 양의 정수를 입력하세요.\n");
        }

        while (sum < target) {
            sum += n * n;
            if (sum == target) {
                printf("n = %d %d 입니다.\n", n, target);

            }
            n++;
        }

        printf("합이 %d인 정확한 제곱 합은 존재하지 않습니다.\n", target);
}

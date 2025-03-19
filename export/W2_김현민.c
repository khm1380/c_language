#define _CRT_SECURE_NO_WARNINGS // vs에서만 사용, clion 및 기타 IDE 불 필요 (헤더 위에 선언할 것)
#include <stdio.h>

int sum(int x, int y) {
    return x + y;
}

int dil(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

double div(double x, double y) {
    return (y != 0) ? x / y : 0.0;
}

double mod(double x, double y) {
    return (y != 0) ? x - (y * (int)(x / y)) : 0.0;
}

int main() {
    printf("Hello, World!\n");

    // int x,y,sum;
    // x = 100, y = 300, sum = x+y;
    // printf("두 수의 합 %d\n",sum);

    int x, y;
    scanf("%d %d", &x, &y);
    printf("두 수의 합 %d\n", sum(x, y));

    // int dil,mul,div,mod;
    // dil = x - y;
    // mul = x * y;
    // div = (y != 0) ? x / y : 0;
    // mod = (y != 0) ? x % y : 0;
    // printf("%d"\n,sum);
    // printf("%d\n",dil);
    // printf("%d\n",mul);
    // printf("%d\n",div);
    // printf("%d\n",mod);

    printf("두 수의 합 %d\n", sum(x, y));
    printf("두 수의 차 %d\n", dil(x, y));
    printf("두 수의 곱 %d\n", mul(x, y));
    printf("두 수의 몫 %.2f\n", div(x, y));
    printf("두 수의 나머지 %.2f\n", mod(x, y));

    int user_input;
    scanf("%d", &user_input);
    printf("값 %d\n", user_input);

    double sal;
    const double target = 1000000000.0;

    printf("연봉: ");
    scanf("%lf", &sal);

    int months = (int)(target / (sal / 12));

    printf("필요한 개월 수: %d\n", months);

    return 0;
}
/*
 * 본 코드는 2025591010 김현민 작성하였습니다.
 */

#include <stdio.h>
#include <limits.h>
#define TAX_RATE 0.2
#define SEC_PER_MINUTE 60

int main() {
    // p129 sizeof
    // printf("char: %d, short: %d, int: %d, float: %d, double: %d, long: %d, long long: %d\n",
    //        sizeof(char), sizeof(short), sizeof(int), sizeof(float), sizeof(double), sizeof(long), sizeof(long long));
    //
    // short s_money = SHRT_MAX;
    // unsigned short u_money = USHRT_MAX;
    //
    // s_money = s_money + 1;
    // printf("%d\n", s_money);
    // u_money = u_money + 1;
    // printf("%d\n", u_money);

    // p137 const, define의 차이점
    // const int MONTHS = 12;
    // int m_sal, y_sal;
    //
    // printf("월급을 입력하시오: ");
    // scanf("%d", &m_sal);
    //
    // y_sal = MONTHS * m_sal;
    //
    // printf("연봉은 %d입니다.\n", y_sal);
    // printf("세금은 %f입니다.\n", TAX_RATE * y_sal);

    // p157 태양 도달 시간 계산
    // double light_speed = 300000;
    // double dist = 146900000;
    // double time = dist / light_speed;
    //
    // printf("빛의 속도는 %lfkm/s \n", light_speed);
    // printf("태양과 지구와의 거리 %lfkm/s \n", dist);
    // printf("도달 시간은 %lf초\n", time);

    // p163 08번
    // double pyeong, square_meters;
    // printf("평을 입력하시오: ");
    // scanf("%lf", &pyeong);
    // square_meters = pyeong * 3.3058;
    // printf("%.2f 평은 %.2f 제곱미터입니다.\n", pyeong, square_meters);


    // p163 08번
    // char asc;
    // printf("아스키 코드값을 입력하시오 : ");
    // scanf("%d", &asc);
    //
    // printf("문자 : %c입니다. ", asc);

    // p169 res 없이 사칙연산

    // int x, y = 0;
    // scanf("두개의 정수를 입력하세요\n%d %d", &x, &y);
    // printf("%d + %d = %d\n", x, y, x + y);
    // printf("%d - %d = %d\n", x, y, x - y);
    // printf("%d * %d = %d\n", x, y, x * y);
    // printf("%d / %d = %.2f\n",  x, y, (float) x / y);
    // printf("%d %% %d = %d\n", x, y, x % y);


    // p171 만시간 몇분 몇초

    int input, hours, min, sec;
    printf("초를 입력하세요: ");
    scanf("%d", &input);

    hours = input / 3600;
    min = (input % 3600) / SEC_PER_MINUTE;
    sec = input % SEC_PER_MINUTE;

    printf("%d초는 %d시간 %d분 %d초입니다.\n", input, hours, min, sec);

    return 0;
}

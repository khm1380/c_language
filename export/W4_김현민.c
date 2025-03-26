/*
 * 본 코드는 2025591010 김현민 작성하였습니다.
 */
#include<stdio.h>

int main() {
    // int x = 10, y = 10;
    //
    // printf("x =  %d\n", x);
    // printf("++x의 값 = %d\n", ++x);
    // printf("x =  %d\n", x);
    //
    // printf("y =  %d\n", y);
    // printf("++y의 값 = %d\n", y++);
    // printf("y =  %d\n", y);
    //
    // int amount;
    // printf("거스름돈을 입력하세요: ");
    // scanf("%d", &amount);
    //
    // int fifty_thousand = amount / 50000;
    // amount %= 50000;
    // int ten_thousand = amount / 10000;
    // amount %= 10000;
    // int five_thousand = amount / 5000;
    // amount %= 5000;
    // int one_thousand = amount / 1000;
    // amount %= 1000;
    // int one_hundred = amount / 100;
    // amount %= 100;
    // int one = amount;
    //
    // printf("5만원권: %d장\n", fifty_thousand);
    // printf("1만원권: %d장\n", ten_thousand);
    // printf("5천원권: %d장\n", five_thousand);
    // printf("1천원권: %d장\n", one_thousand);
    // printf("100원: %d개\n", one_hundred);
    // printf("1원: %d개\n", one);

    /*
     * 물건가격, 문건 개수, 지불금액 입력 (문건개수 : 세금(10%), 봉사료 (5%))
     * 총액 계산 출력
     * 지불금액 입력
     * 총 거스름돈 1만원권에서 100원 까지 몇개인지 출력
     */


        // double price, total_price, paid_amount;
        // int quantity;
        // double tax_rate = 0.10;
        // double service_charge_rate = 0.05;
        //
        // printf("물건 가격을 입력하세요: ");
        // scanf("%lf", &price);
        //
        // printf("문건 개수를 입력하세요: ");
        // scanf("%d", &quantity);
        //
        //
        // printf("세금(10%%)\n");
        // printf("봉사료 (5%%)\n");
        //
        // total_price = price * quantity * (1 + tax_rate + service_charge_rate);
        // printf("총액: %.2f\n", total_price);
        //
        // printf("지불 금액을 입력하세요: ");
        // scanf("%lf", &paid_amount);
        //
        // double change = paid_amount - total_price;
        // printf("거스름돈: %.2f\n", change);
        //
        // int ten_thousand = (int)change / 10000;
        // change = (int)change % 10000;
        //
        // int five_thousand = (int)change / 5000;
        // change = (int)change % 5000;
        //
        // int one_thousand = (int)change / 1000;
        // change = (int)change % 1000;
        //
        // int one_hundred = (int)change / 100;
        // change = (int)change % 100;
        // int one = (int)change;
        //
        // printf("1만원권: %d장\n", ten_thousand);
        // printf("5천원권: %d장\n", five_thousand);
        // printf("1천원권: %d장\n", one_thousand);
        // printf("100원: %d개\n", one_hundred);
        // printf("1원: %d개\n", one);
        //
        //
        //

  //   int x = 0, y = 0;
  //
  //   scanf("%d %d", &x, &y);
  //   printf("%d",x == y);
  //   printf("%d",x != y);
  //   printf("%d",x > y);
  //   printf("%d",x < y);
  //   printf("%d",x %= y);
  //
  //
  //   int year;
  //   printf("연도를 입력하시오.");
  //   scanf("%d",&year);
  //
  //   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) printf("%d년은 윤년입니다.\n", year);
  //
  //   else printf("%d년은 윤년이 아닙니다.",year);
  //
  //
  // unsigned int num;
  // printf("십진수: ");
  // scanf("%d", &num);
  //
  // unsigned int mask = 1 << 31;
  // printf("이진수: ");
  // while (mask > 0) {
  //     printf("%d", (num & mask) ? 1 : 0);
  //     mask >>= 1;
  // }
  // printf("\n");


    // double f_temp;
    // double c_temp;
    //
    // printf(" 화씨온도를 입력하시오 : ");
    // scanf ("%lf", &f_temp);
    // c_temp = 5 / 9 * (f_temp - 32);
    //
    // printf(" 섭씨온도는 %f 입니다 In", c_temp);

    // int n,m;
    // scanf("%d %d",&n,&m);
    //
    // printf("몫 : %d 나머지 : %d",n/m, n%m);

    // // 기본 3자리 min, max
    // int a, b, c;
    // scanf("%d %d %d", &a, &b, &c);
    //
    // int min = a;
    // int max = a;
    //
    // if (b < min) min = b;
    // if (c < min) min = c;
    //
    // if (b > max) max = b;
    // if (c > max) max = c;
    //
    // printf("min : %d\n", min);
    // printf("max : %d\n", max);


    // 배열을 통한 min, max
    int arr[3], min, max;


    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    min = max = arr[0];

    for (int i = 1; i < 3; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("min : %d\n", min);
    printf("max : %d\n", max);

    return 0;
}

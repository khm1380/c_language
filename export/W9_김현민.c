#define print printf
#include <stdio.h>

int star(int x, int y);
int fect(int n);
double round(double num);
double ceil(double num);
double floor(double num);
int main() {
    // star(30,20);print("\nHell0\n");star(10,20);

    // int n = 0;
    // int res;
    // scanf("%d",&n);
    // res = fect(n);
    // print("%d",res);

    double num;
    scanf("%lf", &num);

    printf("반올림 결과: %.0f\n", round(num));
    printf("올림 결과: %.0f\n", ceil(num));
    printf("내림 결과: %.0f\n", floor(num));



    return 0;
}

int star(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            print("*");
            cnt++;
        }
        print("\n");
    }
    return cnt;
}


int fect(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fect(n - 1);
}

double round(double num) {
    if (num >= 0) {
        return (int)(num + 0.5);
    } else {
        return (int)(num - 0.5);
    }
}

double floor(double num) {
    if (num >= 0) {
        return (int)num;
    } else {
        return (int)(num - 1);
    }
}

double ceil(double num) {
    if (num >= 0) {
        return (int)(num + 1) - 1;
    } else {
        return (int)num;
    }
}

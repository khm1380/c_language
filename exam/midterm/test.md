## 기초 구현 유형 분석
> C/C++ , Python 포함



## 공통
> 프로그래밍 언어를 시작할 때, 매번 나오는 문제 (또는 응용)

### 평균 구하기
> 보통 3개 이상의 수를 제시하고 합과 평균, 이외에 사칙연산을 요구<br>
ex) 사용자로부터 3개의 정수를 입력받고 그 수의 합과 평균을 구하시오.
<br>

예시 코드

```c++
#include<stdio.h>

int main() {
    int a,b,c,sum,avg;
    a=b=c=sum=avg = 0;
    
    scanf("%d %d %d", &a, &b, &c);
    sum = (a+b+c);
    avg = sum / 3; // 문제에서 제시한 수가 정해져 있기 때문에 하드코딩
    
    printf("세 수의 합 : %d\n", sum);
    printf("세 수의 평균 : %d\n", avg);
    
    return 0;
}

```

```python
a=b=c = 0

# a,b,c = map(int,input().split())
a = int(input())
b = int(input())
c = int(input())

_sum = (a+b+c)
avg = _sum / 3

print(f"세 수의 합 : {_sum}\n세수의 평균 : {avg}")
```

코드는 간단하게 작성할 수 있다. 하지만 이를 함수로 작성할 경우 여러 방법이 존재한다.
<br>
일반적인 함수 사용

```c
#include<stdio.h>

int sum(int a,int b, int c);
int avg(int sum, int len);

int main() {
    int a,b,c;
    a=b=c = 0;

    scanf("%d %d %d", &a, &b, &c);

    printf("세 수의 합 : %d\n", sum(a,b,c));
    printf("세 수의 평균 : %d\n", avg(sum(a,b,c),3));

    return 0;
}

int sum(int a, int b, int c){
    return a+b+c;
}

int avg(int sum, int len){
    return sum / len;
}
```



C언어도 가변 인자를 통해 구현할 수 있다.
```c
#include <stdio.h>
#include <stdarg.h>

int getSum(int cnt, ...) {
    va_list args;
    va_start(args, cnt);

    int sum = 0;

    for (int i = 0; i < cnt; i++) {
        int val = va_arg(args, int);
        sum += val;
    }

    va_end(args);
    return sum;
}

float getAvg(int cnt, ...) {
    va_list args;
    va_start(args, cnt);

    int sum = 0;

    for (int i = 0; i < cnt; i++) {
        int value = va_arg(args, int);
        sum += value;
    }

    va_end(args);
    return (float)sum / cnt;
}

int main() {
    int a,b,c;
    a=b=c = 0;
    printf("정수 세 개를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("세 수의 합 : %d\n", getSum(3, a, b, c););
    printf("세 수의 평균 : %.2f\n", getAvg(3, a, b, c););

    return 0;
}

```

### 정리
기본적으로 간단한 구현 문제 임으로, 코드를 작성하는데 문제는 없다.<br>
하지만 다른 방법도 고려해 보길 권장한다.


### 시험 성적 문제
> if-eles 또는 switch-case 연습문제로 많이 사용.<br>
조건 :  90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F <br>
조건문 처리로 0보다 작은 값 처리 하는 등등.. (do-while 등등 다시 입력받기)

기본 if, switch로 구현
```c
#include <stdio.h>

int main() {
    int num = 0;
    char res = ' ';

    do {
        printf("시험 점수를 입력하세요. : ");
        scanf("%d", &num);

        if (num >= 90) {
            res = 'A';
        } else if (num >= 80) {
            res = 'B';
        } else if (num >= 70) {
            res = 'C';
        } else if (num >= 60) {
            res = 'D';
        } else {
            res = 'F';
        }
    } while (num < 0 || num > 100);

    printf("%c\n", res);
    return 0;
}

```

switch-case
```c
#include <stdio.h>

int main() {
    int num = 0;
    char res = ' ';

    do {
        printf("시험 점수를 입력하세요. : ");
        scanf("%d", &num);

        if (num >= 0 && num <= 100) {
            switch (num / 10) {
                case 10:
                case 9:
                    res = 'A';
                    break;
                case 8:
                    res = 'B';
                    break;
                case 7:
                    res = 'C';
                    break;
                case 6:
                    res = 'D';
                    break;
                default:
                    res = 'F';
                    break;
            }
        }

    } while (num < 0 || num > 100);

    printf("%c\n", res);
    return 0;
}
```

Python 3.10 버전에서는 match-case 문법으로 C/C++, Java와 같이 구현할 수 있다.
```python
# match-case
 match num // 10:
        case 10 | 9:
            return 'A'
        case 8:
            return 'B'
        case 7:
            return 'C'
        case 6:
            return 'D'
        case _:
            return 'F'
```


Python iterabel 요소 (str) 사용하면 list와 동일하게 트릭을 이용해서 풀수 있다.
```python
print('FFFFFFDCBAA'[int(input())//10])
```

### 약수 구하기
> 보통 약수를 모두 찾는 문제나, 몇개인지 요구하는 문제들이 많다.

약수 : 어떤 수를 나누었을 때 나머지 없이 떨어지는 수 <br> <br>
보통 약수를 구하는 코드는 다음과 같이 표현한다.

```py
n = int(input())

for i in range(1, n+1): # range는 초기값 0부터 시작함으로 +1로 맞춰준다.
    if n % i == 0:
        print(i)

# print([i for i in range(1, n+1) if n % i == 0])
```
이런 방식으로 코드를 작성할 수있다.<br>
하지만 이 코드는 하나씩 다 판별하는, brute force 방식이다.<br>
n이 커지면 커질수록 속도가 느려진다.<br>
이를 해결하기 위해 다른 방식으로 알고리즘을 구현한다.<br>

어떤수 n의 약수는 항상 짝을 이루어 낸다.<br>
예를 들어 n = 36일때, (1,36), (2,18), (3,12), (4,9), (6,6)<br>
즉, i가 약수면, n /i 도 무조건 약수이다. i를 1~√n 까지만 확인해도, 그 이후의 약수를 자동으로 구할 수 있다.
```py
def divisor(n : int) -> list[int]:
    res = set()

    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            res.add(i) # list 사용시 append()
            res.add(n//i)
    return sorted(res)
```

C언어로 구현할시

```c
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            printf("%d ",i);
        }
    }

    return 0;    
}
```

while문을 통한 구현

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        if (n % i == 0) {
            printf("%d ", i);
        }
        i++;
    }

    return 0;
}
```


### 소수 구하기
> 프로그램을 접하면, 항상 나오는 문제! <br>쉽게 구현하는 것 부터 어려운거까지


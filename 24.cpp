//Sharan.B(192210486//
#include <stdio.h>

int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num)
                sum = sum + i + num / i;
            else
                sum = sum + i;
        }
    }
    return (sum == num && num != 1);
}

int main() {
    int num = 28;
    if (isPerfect(num))
        printf("%d is a perfect number", num);
    else
        printf("%d is not a perfect number", num);
    return 0;
}

//Sharan.B(192210486//
#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int original = num, sum = 0, digits = 0;
    while (num != 0) {
        digits++;
        num /= 10;
    }
    num = original;
    while (num != 0) {
        sum += pow(num % 10, digits);
        num /= 10;
    }
    return (sum == original);
}

int main() {
    int num = 153;
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}

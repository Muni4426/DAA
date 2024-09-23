//Sharan.B(192210486//
#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num = 12345;
    printf("Sum of digits of %d is %d", num, sumOfDigits(num));
    return 0;
}

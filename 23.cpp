//Sharan.B(192210486//
#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num = 12345;
    printf("Reversed number of %d is %d", num, reverseNumber(num));
    return 0;
}

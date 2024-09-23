//Sharan.B(192210486//
#include <stdio.h>

void stringCopy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char src[] = "Hello, World!";
    char dest[20];
    stringCopy(dest, src);
    printf("Copied string: %s\n", dest);
    return 0;
}


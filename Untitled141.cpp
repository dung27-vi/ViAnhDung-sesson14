#include <stdio.h>

int sum(int a, int b);

int main() {
    int num1 = 5;
    int num2 = 10;
    int result;

    result = sum(num1, num2);

    printf("Tong cua %d và %d la: %d\n", num1, num2, result);

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

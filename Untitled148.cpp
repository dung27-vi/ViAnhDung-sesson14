#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int n) {
    if (n <= 1) {
        return false;
    }
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main() {
    int num1, num2;

    printf("Nhap so thu nhat: ");
    scanf("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf("%d", &num2);

    printf("Ket qua kiem tra:\n");
    if (isPerfect(num1)) {
        printf("%d la so hoan hao.\n", num1);
    } else {
        printf("%d khong la so hoan hao.\n", num1);
    }

    if (isPerfect(num2)) {
        printf("%d la so hoan hao.\n", num2);
    } else {
        printf("%d khong la so hoan hao.\n", num2);
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num = 36;
    if (isPrime(num)) {
        printf("%d la so nguyen to.\n", num);
    } else {
        printf("%d khong la so nguyen to.\n", num);
    }
    return 0;
}

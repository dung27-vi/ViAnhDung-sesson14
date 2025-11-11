#include <stdio.h>

long long giaiThua(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long ketQua = 1;
    for (int i = 2; i <= n; i++) {
        ketQua *= i;
    }
    return ketQua;
}

int main() {
    int soNguyen;
    printf("Nhap mot so nguyen: ");
    scanf("%d", &soNguyen);

    long long ketQua = giaiThua(soNguyen);
    if (ketQua == -1) {
        printf("Khong the tinh giai thua cho so am.\n");
    } else {
        printf("Giai thua cua %d la: %lld\n", soNguyen, ketQua);
    }
    return 0;
}

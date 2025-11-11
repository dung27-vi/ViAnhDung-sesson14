#include <stdio.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numbers[] = {10, 5, 20, 15, 30, 25};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    int maxNumber = findMax(numbers, n);
    
    printf("So lon nhat trong mang la: %d\n", maxNumber);
    
    return 0;
}

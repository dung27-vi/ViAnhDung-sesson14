#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int myArray[] = {10, 20, 30, 40, 50};
    int n = sizeof(myArray) / sizeof(myArray[0]);
    
    printf("Cac phan tu trong mang la: ");
    printArray(myArray, n);
    
    return 0;
}

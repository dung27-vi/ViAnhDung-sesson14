#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int current_size = 0;
void nhapMang() {
    cout << "Nhap so phan tu can nhap (toi da 100): ";
    cin >> current_size;
    if (current_size > MAX_SIZE) {
        cout << "So phan tu vuot qua kich thuoc toi da." << endl;
        current_size = 0;
        return;
    }
    for (int i = 0; i < current_size; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}
void inMang() {
    if (current_size == 0) {
        cout << "Mang rong." << endl;
        return;
    }
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < current_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void themPhanTu() {
    if (current_size >= MAX_SIZE) {
        cout << "Mang da day, khong the them." << endl;
        return;
    }
    int value, position;
    cout << "Nhap gia tri can them: ";
    cin >> value;
    cout << "Nhap vi tri can them (0 den " << current_size << "): ";
    cin >> position;
    if (position < 0 || position > current_size) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    for (int i = current_size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    current_size++;
    cout << "Da them phan tu thanh cong." << endl;
}
void suaPhanTu() {
    if (current_size == 0) {
        cout << "Mang rong, khong the sua." << endl;
        return;
    }
    int value, position;
    cout << "Nhap vi tri can sua (0 den " << current_size - 1 << "): ";
    cin >> position;
    if (position < 0 || position >= current_size) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    cout << "Nhap gia tri moi: ";
    cin >> value;
    arr[position] = value;
    cout << "Da sua phan tu thanh cong." << endl;
}
void xoaPhanTu() {
    if (current_size == 0) {
        cout << "Mang rong, khong the xoa." << endl;
        return;
    }
    int position;
    cout << "Nhap vi tri can xoa (0 den " << current_size - 1 << "): ";
    cin >> position;
    if (position < 0 || position >= current_size) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    for (int i = position; i < current_size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    current_size--;
    cout << "Da xoa phan tu thanh cong." << endl;
}
void sapXep() {
    if (current_size <= 1) {
        cout << "Khong can sap xep." << endl;
        return;
    }
    int choice;
    cout << "Chon kieu sap xep:" << endl;
    cout << "a. Giam dan" << endl;
    cout << "b. Tang dan" << endl;
    cout << "Lua chon cua ban: ";
    char sub_choice;
    cin >> sub_choice;

    if (sub_choice == 'a') {
        sort(arr, arr + current_size, greater<int>());
        cout << "Da sap xep giam dan." << endl;
    } else if (sub_choice == 'b') {
        sort(arr, arr + current_size);
        cout << "Da sap xep tang dan." << endl;
    } else {
        cout << "Lua chon khong hop le." << endl;
    }
}
void timKiem() {
    if (current_size == 0) {
        cout << "Mang rong, khong the tim kiem." << endl;
        return;
    }
    int value;
    cout << "Nhap gia tri can tim: ";
    cin >> value;

    int choice;
    cout << "Chon kieu tim kiem:" << endl;
    cout << "a. Tim kiem tuyen tinh" << endl;
    cout << "b. Tim kiem nhi phan" << endl;
    cout << "Lua chon cua ban: ";
    char sub_choice;
    cin >> sub_choice;

    if (sub_choice == 'a') {
        bool found = false;
        for (int i = 0; i < current_size; i++) {
            if (arr[i] == value) {
                cout << "Tim thay gia tri " << value << " tai vi tri " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay gia tri " << value << " trong mang." << endl;
        }
    } else if (sub_choice == 'b') {
        // Tim kiem nhi phan yeu cau mang da duoc sap xep
        sort(arr, arr + current_size);
        int left = 0, right = current_size - 1;
        bool found = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value) {
                cout << "Tim thay gia tri " << value << " tai vi tri " << mid << " (sau khi sap xep)." << endl;
                found = true;
                break;
            }
            if (arr[mid] < value) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!found) {
            cout << "Khong tim thay gia tri " << value << " trong mang." << endl;
        }
    } else {
        cout << "Lua chon khong hop le." << endl;
    }
}
int main() {
    int choice;
    do {
        cout << "\nMENU" << endl;
        cout << "1. Nhap so phan tu can nhap va gia tri cac phan tu" << endl;
        cout << "2. In ra gia tri cac phan tu dang quan ly" << endl;
        cout << "3. Them mot phan tu vao vi tri chi dinh" << endl;
        cout << "4. Sua mot phan tu o vi tri chi dinh" << endl;
        cout << "5. Xoa mot phan tu o vi tri chi dinh" << endl;
        cout << "6. Sap xep cac phan tu" << endl;
        cout << "7. Tim kiem phan tu nhap vao" << endl;
        cout << "8. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                nhapMang();
                break;
            case 2:
                inMang();
                break;
            case 3:
                themPhanTu();
                break;
            case 4:
                suaPhanTu();
                break;
            case 5:
                xoaPhanTu();
                break;
            case 6:
                sapXep();
                break;
            case 7:
                timKiem();
                break;
            case 8:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}

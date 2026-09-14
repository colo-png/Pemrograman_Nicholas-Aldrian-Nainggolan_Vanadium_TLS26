#include <iostream>

using namespace std;

int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char toUpperManual(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int main() {
    char pesan[1000];
    
    cout << "Masukkan pesan asli (huruf A-Z tanpa spasi): ";
    cin >> pesan;

    int len = hitungPanjang(pesan);

    for (int i = 0; i < len; i++) {
        pesan[i] = toUpperManual(pesan[i]);
    }

    for (int i = 1; i < len; i++) {
        char prevChar = pesan[i - 1];
        int shift = (prevChar - 'A') + 1;
        int currPos = pesan[i] - 'A';
        int newPos = (currPos + shift) % 26;

        pesan[i] = 'A' + newPos;
    }

    cout << "Pesan terenkripsi: " << pesan << endl;

    return 0;
}
#include <iostream>

using namespace std;

void hapusElemen(int arr[], int &size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int S, N; 
    
    cout << "Masukkan jumlah astronot (S) : ";
    cin >> S;
    cout << "Masukkan nilai hitungan awal (N) : ";
    cin >> N;

    int astronot[1000];
    
    for (int i = 0; i < S; i++) {
        astronot[i] = i + 1;
    }

    int size = S;
    int currentIndex = 0;

    cout << "\nUrutan astronot yang tereliminasi :" << endl;

    while (size > 1) {
        currentIndex = (currentIndex + (N - 1) % size) % size;
        int eliminated = astronot[currentIndex];

        cout << "Astronot " << eliminated << " tereliminasi..... ";

        hapusElemen(astronot, size, currentIndex);

        if (eliminated % 2 == 0) {
            N += 2;
        } else {
            N -= 1;
        }

        if (N < 2) {
            N = 2;
        }

        cout << "(Nilai N yang baru :" << N << ")\n";
    }

    cout << "\nNomor urut astronot yang bertahan sampai akhir : " << astronot[0] << endl;

    return 0; 
}
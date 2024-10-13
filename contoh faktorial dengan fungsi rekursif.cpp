#include <iostream>

using namespace std;

long int faktorial(int A) {
    if (A == 1)
        return A;
    else
        return A * faktorial(A-1);
}

int main() {
    int r, hasil;

    cout << "MENGHITUNG NILAI FAKTORIAL DENGAN REKURSIF" << endl;
    cout << "Masukkan Nilai = ";
    cin >> r;

    hasil = faktorial(r);
    cout << "Faktorial " << r << "! = " << hasil << endl;

    return 0;
}

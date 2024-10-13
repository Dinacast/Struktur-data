#include <iostream>

using namespace std;

int F(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return F(n-1) + F(n-2); // rekursif
}

int main() {
    // rumus: Fn = F(n-1) + F(n-2)
    // deret fibonacci: 0, 1, 1, 2, 3, 5, 8, dst.
    int n;

    cout << "Program C++ Deret Fibonacci" << endl << endl;
    cout << "Fungsi Rekursif" << endl << endl;
    cout << "Berapa jumlah deret? ";
    cin >> n;
    cout << endl << "Fibonacci " << n << " deret: " << endl << endl;

    // perulangan untuk memanggil fungsi F = fibonacci sebanyak n
    for (int i = 0; i < n; i++) {
        cout << F(i) << " ";
    }

    cout << endl << endl;
    return 0;
}

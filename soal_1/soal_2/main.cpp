#include <iostream>
#include <limits>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    do {
        cout << "\n===== MENU STACK (POINTER) =====" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka 1-4." << endl;
            pilihan = 0;
            continue;
        }

        switch (pilihan) {
        case 1: {
            int x;
            cout << "Masukkan bilangan bulat: ";
            if (!(cin >> x)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid, penambahan dibatalkan." << endl;
                break;
            }
            pushAscending(S, x);
            cout << x << " berhasil ditambahkan." << endl;
            printInfo(S);
            break;
        }
        case 2: {
            int x;
            if (pop(S, x)) {
                cout << "Nilai yang di-Pop: " << x << endl;
            } else {
                cout << "Pop gagal: stack kosong." << endl;
            }
            break;
        }
        case 3:
            printInfo(S);
            break;
        case 4:
            clearStack(S);
            cout << "Semua node dilepas. Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
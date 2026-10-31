#include <iostream>
#include <limits>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);

    int pilihan;
    do {
        cout << "\n===== MENU STACK (ARRAY) =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid, masukkan angka 1-5." << endl;
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
                cout << "Input tidak valid, push dibatalkan." << endl;
                break;
            }
            if (push(S, x)) {
                cout << x << " berhasil di-Push." << endl;
            } else {
                cout << "Push gagal: stack penuh (maksimal "
                     << MAX_STACK << " elemen)." << endl;
            }
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
            if (isEmpty(S)) {
                cout << "Stack kosong, tidak ada yang dibalik." << endl;
            } else {
                balikStack(S);
                cout << "Stack berhasil dibalik." << endl;
                printInfo(S);
            }
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
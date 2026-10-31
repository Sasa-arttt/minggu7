#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(const Stack &S) {
    return S.Top == 0;
}

bool isFull(const Stack &S) {
    return S.Top == MAX_STACK;
}

// Gagal (false) jika stack penuh; Top dan isi tidak berubah
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

// Gagal (false) jika stack kosong; Top dan isi tidak berubah
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

// Menampilkan isi mulai dari TOP
void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

// Membalik isi stack dengan SATU stack bantu (hanya lewat push & pop).
// Setiap putaran: elemen TOP diambil, sisa elemen (di atas bagian yang
// sudah final) dipindah ke stack bantu, elemen tadi di-push kembali,
// lalu stack bantu dikembalikan. Akibatnya elemen TOP "tenggelam" tepat
// di atas bagian yang sudah final. Duplikat dan jumlah elemen tetap.
void balikStack(Stack &S) {
    int n = S.Top;
    if (n < 2) {
        return;
    }

    Stack bantu;
    createStack(bantu);
    int x, y;

    for (int i = 0; i < n - 1; i++) {
        pop(S, x);                       // elemen TOP disimpan sementara
        for (int j = 0; j < n - 1 - i; j++) {
            pop(S, y);
            push(bantu, y);              // pindah ke stack bantu
        }
        push(S, x);                      // letakkan di atas bagian final
        while (!isEmpty(bantu)) {
            pop(bantu, y);
            push(S, y);                  // kembalikan sisa elemen
        }
    }
}
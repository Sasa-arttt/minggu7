#include <iostream>
#include <new>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(const Stack &S) {
    return S.Top == nullptr;
}

address alokasi(int x) {
    address P = new (nothrow) Node;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

// Menambah elemen pada TOP
bool push(Stack &S, int x) {
    address P = alokasi(x);
    if (P == nullptr) {
        return false;
    }
    P->next = S.Top;
    S.Top = P;
    return true;
}

// Mengambil nilai TOP lalu melepas (dealokasi) node tersebut
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    address P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);
    return true;
}

// Menampilkan isi mulai dari TOP
void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP: ";
    address P = S.Top;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menyisipkan x sehingga urutan menaik dari bawah ke TOP (terbesar di TOP).
// Elemen yang lebih besar dari x dipindah sementara ke stack bantu,
// x di-push, lalu semua elemen dari stack bantu dikembalikan.
// Duplikat disimpan sebagai elemen terpisah (x diletakkan di atas yang sama).
void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);
    int y;

    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, y);
        push(bantu, y);
    }

    push(S, x);

    while (!isEmpty(bantu)) {
        pop(bantu, y);
        push(S, y);
    }
}

// Melepas seluruh node dan mengembalikan Top menjadi nullptr
void clearStack(Stack &S) {
    int x;
    while (pop(S, x)) {
        // terus pop sampai kosong
    }
    S.Top = nullptr;
}
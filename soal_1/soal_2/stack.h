#ifndef STACK_H
#define STACK_H

struct Node {
    int info;
    Node *next;
};

typedef Node *address;

// Stack hanya menyimpan pointer Top; kosong jika Top = nullptr
struct Stack {
    address Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
address alokasi(int x);
void dealokasi(address &P);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif
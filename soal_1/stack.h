#ifndef STACK_H
#define STACK_H

const int MAX_STACK = 20;

// Stack array: indeks data 1..20, Top = 0 -> kosong, Top = 20 -> penuh
struct Stack {
    int info[MAX_STACK + 1];
    int Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
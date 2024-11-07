#include <iostream>

using namespace std;


// Mendefinisikan struktur Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Mendefinisikan struktur Stack
typedef struct Stack {
    int count;
    struct Node* top;
    const int MAX_SIZE = 10;
} Stack;

Stack stack;

void createStack() {
    stack.count = 0;
    stack.top = NULL;
}

bool isEmpty() {
    return stack.count == 0;
}

bool isFull() {
    return stack.count >= stack.MAX_SIZE;
}

// Push
void push(int data) {
    if (isFull()) {
        cout << "Stack penuh.\n";
        return;
    }

    Node* newPtr = new Node;
    if (newPtr == NULL) {
        cout << "Alokasi memori gagal!";
        return;
    }

    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
    cout << "Data " << data << " berhasil ditambahkan.\n";
}

// Pop
void pop() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
        return;
    }

    Node* dltPtr = stack.top;
    stack.top = stack.top->next;
    stack.count--;
    delete dltPtr;
    cout << "Data berhasil dihapus.\n";
}

// Stack Top
void stackTop() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data pada top.\n";
        return;
    }
    cout << "Nilai pada top: " << stack.top->data << endl;
}

// Empty Stack
void emptyStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
    } else {
        cout << "Stack tidak kosong.\n";
    }
}

// Fungsi untuk mengecek apakah stack penuh
void fullStack() {
    if (isFull()) {
        cout << "Stack penuh.\n";
    } else {
        cout << "Stack belum penuh.\n";
    }
}

// Stack Count
int stackCount() {
    return stack.count;
}

// Destroy Stack
void destroyStack() {
    while (!isEmpty()) {
        pop();
    }
    cout << "Stack berhasil di hapus.\n";
}

// Print Stack
void printStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
        return;
    }
    Node* current = stack.top;
    cout << "Isi stack: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    int pilihan, value;
    createStack();

    do {
        cout << "\nMenu Stack:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Stack Top\n";
        cout << "4. Empty Stack\n";
        cout << "5. Full Stack\n";
        cout << "6. Stack Count\n";
        cout << "7. Destroy Stack\n";
        cout << "8. Print Stack\n";
        cout << "0. Exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                stackTop();
                break;
            case 4:
                emptyStack();
                break;
            case 5:
                fullStack();
                break;
            case 6:
                cout << "Ukuran stack: " << stackCount() << endl;
                break;
            case 7:
                destroyStack();
                break;
            case 8:
                printStack();
                break;
            case 0:
                cout << "keluar dari program.\n";
                break;
            default:
                cout << "Input tidak valid!.\n";
        }
    } while (pilihan != 0);

    return 0;
}


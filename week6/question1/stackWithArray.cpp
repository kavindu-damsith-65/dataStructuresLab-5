#include <iostream>
using namespace std;

class Stack {
    private:
        int* arr;
        int top;
        int capacity;

    public:
        Stack(int size) {
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        void push(int x) {
            if (isFull()) {
                cout << "Stack Overflow\n";
                return;
            }
            arr[++top] = x;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return -1;
            }
            return arr[top--];
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == capacity - 1);
        }

        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }
            return arr[top];
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return;
            }
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    s.push(6); // Stack Overflow
    s.display(); // 5 4 3 2 1
    cout << s.pop() << endl; // 5
    cout << s.stackTop() << endl; // 4
    s.display(); // 4 3 2 1
    return 0;
}

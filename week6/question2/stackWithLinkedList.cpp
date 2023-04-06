#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        ~Stack() {
            Node* temp;
            while (top != NULL) {
                temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(int x) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return -1;
            }
            int x = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return x;
        }

        bool isEmpty() {
            return (top == NULL);
        }


        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;
            }
            return top->data;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return;
            }
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display(); // 6 5 4 3 2 1
    cout << s.pop() << endl; // 6
    cout << s.stackTop() << endl; // 5
    s.display(); // 5 4 3 2 1
    return 0;
}

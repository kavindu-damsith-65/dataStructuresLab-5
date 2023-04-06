#include <iostream>
#include <chrono>

using namespace std;

class StackArray {
    private:
        int* arr;
        int top;
        int capacity;

    public:
        StackArray(int size) {
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~StackArray() {
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


class Node {
    public:
        int data;
        Node* next;
};

class StackLinkedList {
    private:
        Node* top;

    public:
        StackLinkedList() {
            top = NULL;
        }

        ~StackLinkedList() {
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
    cout<<endl;
    srand(time(NULL));
    int size=25;
    int push1=20;
    int pop1=10;
    int push2=12;

    // stack using array time taken
    StackArray stack1(size);
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < push1; i++){
      stack1.push(rand() % 1000);
    }
    stack1.display();

    for (int i = 0; i < pop1; i++){
      stack1.pop();
    }
    
    stack1.display();

    for (int i = 0; i < push2; i++){
      stack1.push(rand()%1000);
    }
    stack1.display(); 

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken stack(array): " << duration.count() << " milliseconds" << endl;



    cout<<endl;
    //  stack using linked list time taken
    StackLinkedList stack2;
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < push1; i++){
      stack2.push(rand() % 1000);
    }
    stack2.display();

    for (int i = 0; i < pop1; i++){
      stack2.pop();
    }
    
    stack2.display();

    for (int i = 0; i < push2; i++){
      stack2.push(rand()%1000);
    }
    stack2.display(); 

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    cout << "Time taken stack(linked list): " << duration2.count() << " milliseconds" << endl;


    return 0;
}
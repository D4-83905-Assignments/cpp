#include<iostream>
using namespace std;

class Stack {
private:
    int size;       
    int top;        
    int *arr;       
public:
    Stack(int SIZE = 5) : size(SIZE), top(-1) {
        arr = new int[size];           
    }

    ~Stack() {                      
        delete[] arr;     
    }

    int isFull() {
        return top == size - 1; 
    }

    int isEmpty() {
        return top == -1;   
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack is full !" << endl;
            return;
        }
        arr[++top] = data;
        cout << data << " element pushed into the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty !" << endl;
            return;
        }
        cout << arr[top--] << " element pop out from stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        return arr[top];
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5); 
    int choice, data;

    do {
        cout << "0. Exit" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Print" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting. Thank You." << endl;
                break;

            case 1:
                cout << "Enter element to push: ";
                cin >> data;
                stack.push(data);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;

            case 4:
                stack.print();
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}




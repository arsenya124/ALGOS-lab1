#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int listLength;

public:
    LinkedList() {
        head = nullptr;
        listLength = 0;
    }
    void push(int value) { //добавл€ет элемент в начало списка
        Node* newValue = new Node;
        newValue->data = value;
        if (listLength > 0)
            newValue->next = head;
        else
            newValue->next = nullptr;
        head = newValue;
        listLength++;
    }
    void pop() { //удал€ет элемент из начала списка 
        //ѕроверка на дурачка добавить
        if (listLength > 0) {
            Node* currValue = head;
            head = currValue->next;
            delete currValue;
            listLength--;
        }
        else {
            cout << "List is empty, you can't delete value!";
        }
        
    }
    int isEmpty() {
        return listLength == 0;

    }
    int peek() {  //возвращает значение первого элемента без его удалени€
        return head->data;

    }
    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next;
        }

    }
    ~LinkedList() {
        if (listLength > 0) {
            for (int i = 0; i < listLength; i++) {
                Node* currValue = head;
                head = head->next;
                delete currValue;

            }
        }
    }
};

int main()
{
    setlocale(0, "");
    LinkedList st;
    cout << st.isEmpty() << "\n";
    st.push(5);
    st.push(6);
    st.printList();
    st.pop();
    cout << st.peek();
    
}
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int listLength;

public:
    LinkedList() {
        head = nullptr; // Убираем Node*, чтобы инициализировать член класса
        listLength = 0;
    }

    void push(int value) { // добавляет элемент в начало списка
        Node* newValue = new Node;
        newValue->data = value;
        if (listLength > 0)
            newValue->next = head;
        else
            newValue->next = nullptr;
        head = newValue;
        listLength++;
    }

    void pop() { // удаляет элемент из начала списка
        if (listLength > 0) {
            Node* currValue = head;
            head = currValue->next;
            delete currValue;
            listLength--; // Уменьшение длины списка внутри проверки
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }
    }

    int isEmpty() {
        return listLength == 0;
    }

    string peek() { // возвращает значение первого элемента без его удаления
        if (head != nullptr)
            return head->data;
        throw runtime_error("List is empty");
    }

    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next; // Продвигаем указатель на следующий элемент
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* currValue = head;
            head = head->next;
            delete currValue;
        }
    }
};

int main() {
    setlocale(0, "");
    LinkedList st;
    cout << st.isEmpty() << "\n";
    st.push('5');
    st.push('6');
    st.printList();
    st.pop();
    cout << st.peek() << "\n";

    return 0;
}

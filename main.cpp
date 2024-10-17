#include <iostream>
using namespace std;
#include <string>

struct Node {
    string data;
    Node* next;
};
struct DoublyNode {
    string data;
    DoublyNode* prev;
    DoublyNode* next;
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

    void push(string value) { // добавл€ет элемент в начало списка
        Node* newValue = new Node;
        newValue->data = value;
        if (listLength > 0)
            newValue->next = head;
        else
            newValue->next = nullptr;
        head = newValue;
        listLength++;
    }

    void pop() { // удал€ет элемент из начала списка
        if (listLength > 0) {
            Node* currValue = head;
            head = currValue->next;
            delete currValue;
            listLength--; // ”меньшение длины списка внутри проверки
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }
    }

    int isEmpty() {
        return listLength == 0;
    }

    string peek() {  // возвращает значение первого элемента без его удалени€
        if (head != nullptr) {
            return head->data;
        }
        else 
        {
            cout << "List is empty!" << endl;
            return "-1"; // ¬озвращаем специальное значение, указывающее на ошибку
        }
    }

    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next; // ѕродвигаем указатель на следующий элемент
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

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* back;
    int listLength;

public:
    DoublyLinkedList() {
        head = nullptr; 
        back = nullptr;
        listLength = 0;
    }

    void pushFront(string value) { //ѕочему head - это чисто указатель типа DoublyNode, и его можно использовать как обычный указатель, без -> prev or next, а с newNode так сделать не получитс€?
        if (listLength == 0) {
            DoublyNode* newNode = new DoublyNode;
            head = newNode;
            back = head;
            head->prev = nullptr;
            head->next = nullptr;
            head->data = value;
        }
        else {
            DoublyNode* newNode = new DoublyNode;
            newNode->prev = nullptr;
            newNode->data = value;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listLength++;
    }

    void pushBack(string value) {
        if (listLength == 0) {
            DoublyNode* newNode = new DoublyNode;
            head = newNode;
            back = head;
            head->prev = nullptr;
            head->next = nullptr;
            head->data = value;
        }
        else {
            DoublyNode* newNode = new DoublyNode;
            newNode->prev = back;
            newNode->data = value;
            newNode->next = nullptr;
            back->next = newNode;
            back = newNode;
        }
        listLength++;

    }

    void popFront() {
        if (listLength > 0) {
            DoublyNode* currNode = head;
            head = head->next;
            head->prev = nullptr;
            delete currNode;
            listLength--;
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }
        
    }

    void popBack() {
        if (listLength > 0) {
            DoublyNode* currNode = back;
            back = back->prev;
            back->next = nullptr;
            delete currNode;
            listLength--;
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }

    }


    string getFront() {
        if (listLength > 0) return head->data;
        else return "-1";
    }

    string getBack() {
        if (listLength > 0) return back->data;
        else return "-1";
       

    }
    string getAt(int index) {
        if (listLength != 0 and index >= 0 and index < listLength) {
            DoublyNode* currnode = head;
            for (int i = 0; i < index; i++) {
                currnode = currnode->next;
            }
            return currnode->data;
        }
        else return "-1";
    }
    void insertAt(int index, string value) {
        
        DoublyNode* newNode = new DoublyNode;
        if (index == 0) {
            newNode->data = value;
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
            if (listLength > 0) head->prev = newNode;
            else back = head;
            listLength++;
        }
        else {
            if (index == listLength) {
                newNode->data = value;
                newNode->next = nullptr;
                newNode->prev = back;
                back->next = newNode;
                back = newNode;
                listLength++;
            }
            else {
                if ((index > 0) and (index < listLength)) {
                    DoublyNode* currNode = head;
                    for (int i = 0; i < index; i++) {
                        currNode = currNode->next;
                    }
                    newNode->data = value;
                    newNode->prev = currNode->prev;
                    newNode->next = currNode;
                    currNode->prev->next = newNode;
                    currNode->prev = newNode;
                    listLength++;
                }
                else cout << "Index is wrong, try again!" << endl;
            }
        }

    }

    /*void deleteAt(int index) {
        if ((index >= 0) and (index < listLength)) {
            DoublyNode* currNode = head;
            for (int i = 0; i++; i < listLength) {
                currNode = currNode->next;
            }
            if (currNode->prev != nullptr) {
                currNode->prev = currNode
            }
        }
        else cout << "Index is wrong, try again!" << endl;

    }

    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next; // ѕродвигаем указатель на следующий элемент
        }
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* currValue = head;
            head = head->next;
            delete currValue;
        }
    }
    */
};

int main() {
    setlocale(0, "");
    DoublyLinkedList st;
    st.pushBack("0");
    st.pushBack("2");
    st.insertAt(1, to_string(1));
    cout << st.getAt(0) << endl;
    cout << st.getAt(1) << endl;
    cout << st.getAt(2) << endl;
    /*st.push("5");
    st.push("6");
    st.printList();
    st.pop();
    cout << st.peek() << "\n";*/

    return 0;
}

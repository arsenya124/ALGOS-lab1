#include <iostream>
#include <sstream>
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

    void push(string value) { // ��������� ������� � ������ ������
        Node* newValue = new Node;
        newValue->data = value;
        if (listLength > 0)
            newValue->next = head;
        else
            newValue->next = nullptr;
        head = newValue;
        listLength++;
    }

    void pop() { // ������� ������� �� ������ ������
        if (listLength > 0) {
            Node* currValue = head;
            head = currValue->next;
            delete currValue;
            listLength--; // ���������� ����� ������ ������ ��������
        }
        else {
            cout << "List is empty, you can't delete value!" << endl;
        }
    }

    bool isEmpty() {
        return listLength == 0;
    }

    string peek() {  // ���������� �������� ������� �������� ��� ��� ��������
        if (head != nullptr) {
            return head->data;
        }
        else 
        {
            cout << "List is empty!" << endl;
            return "-1"; // ���������� ����������� ��������, ����������� �� ������
        }
    }

    void printList() {
        cout << "Stack contains " << listLength << " element(s):\n";
        Node* currValue = head;
        for (int i = 0; i < listLength; i++) {
            cout << i + 1 << " - " << currValue->data << "\n";
            currValue = currValue->next; // ���������� ��������� �� ��������� �������
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

    void pushFront(string value) { //������ head - ��� ����� ��������� ���� DoublyNode, � ��� ����� ������������ ��� ������� ���������, ��� -> prev or next, � � newNode ��� ������� �� ���������?
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
            if(head != nullptr) head->prev = nullptr;
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
            if (back != nullptr) back->next = nullptr;
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
    bool isEmpty() {
        return listLength == 0;
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
            currValue = currValue->next; // ���������� ��������� �� ��������� �������
        }
    }
    */
    ~DoublyLinkedList() {
        while (head != nullptr) {
            DoublyNode* currValue = head;
            head = head->next;
            delete currValue;
        }
    }
    
};

class DynamicArray {
private:
    int* data;         // ��������� �� ������
    int currentSize;   // ������� ������ �������
    int currentCapacity; // ������� ������� �������

    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) return; // �� ����� �����������, ���� ����� ������� ������ ��� ����� �������

        int* newData = new int[newCapacity]; // ��������� ����� ������
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i]; // �������� ������ ������ � ����� ������
        }
        delete[] data; // ����������� ������ ������
        data = newData; // ��������� �� ����� ������
        currentCapacity = newCapacity; // ��������� ������� �������
    }

public:
    DynamicArray() {
        currentSize = 0;
        currentCapacity = 2; // ��������� �������
        data = new int[currentCapacity]; // �������� ������
    }

    void pushBack(int value) {
        if (currentSize == currentCapacity) { // ���� ������ ��������, ����������� �������
            resize(currentCapacity * 2);
        }
        data[currentSize++] = value; // ��������� ����� �������
    }

    void popBack() {
        if (currentSize == 0) {
            throw std::out_of_range("Array is empty, cannot pop!");
        }
        currentSize--; // ��������� ������ �������
    }

    int getAt(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index]; // ���������� ������� �� �������
    }

    void setAt(int index, int value) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value; // ������������� �������� �� �������
    }

    int size() {
        return currentSize; // ���������� ������� ������
    }

    int capacity() {
        return currentCapacity; // ���������� ������� �������
    }

    ~DynamicArray() {
        delete[] data; // ����������� ������ ��� �����������
    }
};

// ����� ��� ��������� ������������� �������
class ShuntingYard {
private:
    DoublyLinkedList input;      // ������� ������
    string output;     // �������� ������ (����������� ������)
    LinkedList operators;  // ���� ���������� � �������

    // ��������, �������� �� ������ ������
    bool isNumber(const string& s) {
        for (char c : s) {
            if (!isdigit(c)) {  // ���� �� �����, ���������� false
                return false;
            }
        }
        return !s.empty(); // ���������, ��� ������ �� ������
    }


    // ����������� ���������� ���������
    int getPrecedence(const string& op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        if (op == "^") return 3;
        if (op == "sin" || op == "cos") return 4;
        return 0;
    }

    // ��������, �������� �� ����� ����������
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos";
    }


    // ������ ��������� ������������� �������
    void process() {
        while (!input.isEmpty()) {
            string token = input.getFront();
            input.popFront();  // ������� ������� �� �������� ������

            if (isNumber(token)) {
                output += token + " ";  // ����� ��������� � �������� ������
            }

            else if (isOperator(token)) {
                // ��������� ��������� ���������� � ��������� ���� �����
                while (!operators.isEmpty() && isOperator(operators.peek()) &&
                    getPrecedence(operators.peek()) >= getPrecedence(token)) {
                    output += operators.peek() + " ";
                    operators.pop();  // ������� �������� �� �����
                }
                operators.push(token);  // �������� ������� �������� � ����
            }
            else if (token == "(") {
                operators.push(token);  // ����������� ������ �������� � ����
            }
            else if (token == ")") {
                // ��������� ��������� �� ����������� ������
                while (!operators.isEmpty() && operators.peek() != "(") {
                    output += operators.peek() + " ";
                    operators.pop();
                }
                operators.pop();  // ������� ����������� ������ �� �����
              
            }
        }

        // ��������� ���������� ��������� �� �����
        while (!operators.isEmpty()) {
            output += operators.peek() + " ";
            operators.pop();
        }
    }

    void parseExpression(const string& expression) {
        stringstream ss(expression);
        string token;
        while (ss >> token) {
            if (token == "sin" || token == "cos") {
                input.pushBack(token);
            }
            else {
                input.pushBack(token);
            }
        }
    }

public:
    // ����� ��� ���������� ������ � ������� ������
    void setInputExpression(const string& expression) {
        parseExpression(expression);
    }

    // ����� ��� ������� ���������
    void convertToPostfix() {
        process(); // ��������� ��������������
    }

    // ����� ��� ������ ����������� ������
    string getPostfix() {
        return output;
    }
};

// ������� �������
int main() {
    setlocale(0, "");
    ShuntingYard sy;

    // ������: ��������� ������ ��������� 3 + sin 30
    
    sy.setInputExpression("2 + sin 30 + 2 * 6 * ( 3 - 3 / 3 )");
    // ����������� � ����������� �������
    sy.convertToPostfix();

    // ����� ����������
    cout << "����������� ������: ";
    cout << sy.getPostfix();

    return 0;
}




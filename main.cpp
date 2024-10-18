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

    void push(string value) { // добавляет элемент в начало списка
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

    bool isEmpty() {
        return listLength == 0;
    }

    string peek() {  // возвращает значение первого элемента без его удаления
        if (head != nullptr) {
            return head->data;
        }
        else 
        {
            cout << "List is empty!" << endl;
            return "-1"; // Возвращаем специальное значение, указывающее на ошибку
        }
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

    void pushFront(string value) { //Почему head - это чисто указатель типа DoublyNode, и его можно использовать как обычный указатель, без -> prev or next, а с newNode так сделать не получится?
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
            currValue = currValue->next; // Продвигаем указатель на следующий элемент
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
    int* data;         // Указатель на массив
    int currentSize;   // Текущий размер массива
    int currentCapacity; // Текущая емкость массива

    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) return; // Не нужно увеличивать, если новая емкость меньше или равна текущей

        int* newData = new int[newCapacity]; // Выделение новой памяти
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i]; // Копируем старые данные в новый массив
        }
        delete[] data; // Освобождаем старую память
        data = newData; // Указываем на новый массив
        currentCapacity = newCapacity; // Обновляем текущую емкость
    }

public:
    DynamicArray() {
        currentSize = 0;
        currentCapacity = 2; // Начальная емкость
        data = new int[currentCapacity]; // Выделяем память
    }

    void pushBack(int value) {
        if (currentSize == currentCapacity) { // Если массив заполнен, увеличиваем емкость
            resize(currentCapacity * 2);
        }
        data[currentSize++] = value; // Добавляем новый элемент
    }

    void popBack() {
        if (currentSize == 0) {
            throw std::out_of_range("Array is empty, cannot pop!");
        }
        currentSize--; // Уменьшаем размер массива
    }

    int getAt(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index]; // Возвращаем элемент по индексу
    }

    void setAt(int index, int value) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value; // Устанавливаем значение по индексу
    }

    int size() {
        return currentSize; // Возвращаем текущий размер
    }

    int capacity() {
        return currentCapacity; // Возвращаем текущую емкость
    }

    ~DynamicArray() {
        delete[] data; // Освобождаем память при уничтожении
    }
};

// Класс для алгоритма сортировочной станции
class ShuntingYard {
private:
    DoublyLinkedList input;      // Входной список
    string output;     // Выходной список (постфиксная запись)
    LinkedList operators;  // Стек операторов и функций

    // Проверка, является ли строка числом
    bool isNumber(const string& s) {
        for (char c : s) {
            if (!isdigit(c)) {  // Если не цифра, возвращаем false
                return false;
            }
        }
        return !s.empty(); // Проверяем, что строка не пустая
    }


    // Определение приоритета оператора
    int getPrecedence(const string& op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        if (op == "^") return 3;
        if (op == "sin" || op == "cos") return 4;
        return 0;
    }

    // Проверка, является ли токен оператором
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos";
    }


    // Логика алгоритма сортировочной станции
    void process() {
        while (!input.isEmpty()) {
            string token = input.getFront();
            input.popFront();  // Удаляем элемент из входного списка

            if (isNumber(token)) {
                output += token + " ";  // Число добавляем в выходную строку
            }

            else if (isOperator(token)) {
                // Учитываем приоритет операторов и проверяем верх стека
                while (!operators.isEmpty() && isOperator(operators.peek()) &&
                    getPrecedence(operators.peek()) >= getPrecedence(token)) {
                    output += operators.peek() + " ";
                    operators.pop();  // Удаляем оператор из стека
                }
                operators.push(token);  // Помещаем текущий оператор в стек
            }
            else if (token == "(") {
                operators.push(token);  // Открывающую скобку помещаем в стек
            }
            else if (token == ")") {
                // Выгружаем операторы до открывающей скобки
                while (!operators.isEmpty() && operators.peek() != "(") {
                    output += operators.peek() + " ";
                    operators.pop();
                }
                operators.pop();  // Убираем открывающую скобку из стека
              
            }
        }

        // Выгружаем оставшиеся операторы из стека
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
    // Метод для добавления токена в входной список
    void setInputExpression(const string& expression) {
        parseExpression(expression);
    }

    // Метод для запуска алгоритма
    void convertToPostfix() {
        process(); // Запускаем преобразование
    }

    // Метод для вывода постфиксной записи
    string getPostfix() {
        return output;
    }
};

// Главная функция
int main() {
    setlocale(0, "");
    ShuntingYard sy;

    // Пример: добавляем токены выражения 3 + sin 30
    
    sy.setInputExpression("2 + sin 30 + 2 * 6 * ( 3 - 3 / 3 )");
    // Преобразуем в постфиксную нотацию
    sy.convertToPostfix();

    // Вывод результата
    cout << "Постфиксная запись: ";
    cout << sy.getPostfix();

    return 0;
}




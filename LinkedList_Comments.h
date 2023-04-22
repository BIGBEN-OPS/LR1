#include <iostream>

class LinkedList {
public: // Определение публичных методов класса
    // Конструктор по умолчанию, создает пустой список
    LinkedList();

    // Деструктор, освобождает память, занятую элементами списка
    ~LinkedList();

    // Добавляет элемент в конец списка
    void append(int value);

    // Добавляет элемент в начало списка
    void prepend(int value);

    // Добавляет элемент на заданную позицию
    void insert(int value, int pos);

    // Удаляет элемент по значению
    void remove(int value);

    // Удаляет элемент по номеру позиции
    void removeAt(int pos);

    // Ищет элемент по значению
    int find(int value);

    // Возвращает элемент в заданной позиции
    int get(int pos);

    // Выводит все элементы списка
    void print();

private:
    // Структура, представляющая узел списка
    struct Node {
        int data; // Значение элемента
        Node* next; // Указатель на следующий элемент
    };

    Node* head; // Указатель на начало списка
    int size; // Размер списка
};
// Конструктор по умолчанию, создает пустой список
LinkedList::LinkedList() {
    head = nullptr; // Устанавливаем указатель на начало списка равным nullptr, т.е. указывающим на нулевой адрес
    size = 0; // Устанавливаем размер списка в 0, т.к. список пока пустой
}

// Деструктор, освобождает память, занятую элементами списка
LinkedList::~LinkedList() {
    Node* current = head; // Инициализация указателя на начало списка
    while (current != nullptr) { // Пока указатель на текущий элемент не достигнет конца списка
        Node* next = current->next; // Создаем указатель на следующий элемент списка
        delete current; // Освобождаем память, занятую текущим элементом списка
        current = next; // Переходим к следующему элементу списка
    }
}

// Добавляет элемент в конец списка
void LinkedList::append(int value) {
    Node* newNode = new Node; // Создаем новый узел списка
    newNode->data = value; // Присваиваем ему значение
    newNode->next = nullptr; // Устанавливаем указатель на следующий элемент списка равным nullptr, т.к. добавляемый элемент последний

    if (head == nullptr) { // Если список пустой
        head = newNode;  // Устанавливаем указатель на начало списка на новый элемент
    } else { // Если список не пустой
        Node* current = head; // Создаем указатель на начало списка
        while (current->next != nullptr) { // Пока не достигнут конец списка
            current = current->next; // Перемещаем указатель на следующий элемент списка
        }
        current->next = newNode; // Добавляем новый элемент в конец списка
    }
    size++; // Увеличиваем размер списка на 1
}

// Добавляет элемент в начало списка
void LinkedList::prepend(int value) {
    Node* newNode = new Node; // Создаем новый узел списка.
    newNode->data = value; // Присваиваем значение элемента списка
    newNode->next = head;  // Устанавливаем указатель на следующий элемент списка на текущее начало списка

    head = newNode; // Устанавливаем указатель на начало списка на новый элемент.
    size++; // Увеличиваем размер списка на 1.
}

// Добавляет элемент на заданную позицию
void LinkedList::insert(int value, int pos) {
    if (pos < 0 || pos > size) { // Проверка на корректность введенной позиции
        throw std::out_of_range("Invalid position"); // Вывод сообщения об ошибке, если позиция вне диапазона
    }

    if (pos == 0) { // Если позиция находится в начале списка, используем метод prepend
        prepend(value);
    } else { // Иначе добавляем элемент в середину списка
        Node* newNode = new Node; // Создаём новый узел
        newNode->data = value; // Присваиваем ему значение
        Node* current = head; // Создаем указатель на текущий элемент списка
        for (int i = 0; i < pos - 1; i++) { // Поиск элемента, перед которым нужно вставить новый узел
            current = current->next;
        }

        newNode->next = current->next; // Установка связи между новым узлом и следующим элементом
        current->next = newNode; // Установка связи между текущим элементом и новым узлом
        size++; // Увеличиваем размер списка на 1
    }
}

// Удаляет элемент по значению
void LinkedList::remove(int value) {
    if (head == nullptr) { // Если список пуст, ничего не делаем
        return;
    }

    if (head->data == value) { // Если элемент находится в начале списка
        Node* oldHead = head; // Сохраняем указатель на текущий элемент
        head = head->next; // Устанавливаем указатель на начало списка на следующий элемент
        delete oldHead; // Удаляем текущий элемент
        size--; // Уменьшаем размер списка на 1
        return;
    }

    Node* current = head;// Создаем указатель на начало списка
    while (current->next != nullptr && current->next->data != value) { // Ищем элемент, предшествующий удаляемому элементу
        current = current->next; // Переходим к следующему элементу
    }

    if (current->next != nullptr) { // Если элемент найден
        Node* toDelete = current->next; // Сохраняем указатель на удаляемый элемент
        current->next = current->next->next; // Устанавливаем указатель на следующий элемент текущего элемента на следующий элемент удаляемого элемента
        delete toDelete; // Удаляем удаляемый элемент
        size--; // Уменьшаем размер списка на 1
    }
}

// Удаляет элемент по номеру позиции
void LinkedList::removeAt(int pos) {
    if (pos < 0 || pos >= size) { // Если позиция находится вне границ списка
        throw std::out_of_range("Invalid position"); // Вывод сообщения об ошибке, если позиция вне диапазона
    }

    if (pos == 0) { // Если удаляем первый элемент списка
        Node* oldHead = head; // Сохраняем указатель на текущий первый элемент списка
        head = head->next; // Переустанавливаем указатель на начало списка на следующий элемент
        delete oldHead; // Освобождаем память, занятую удаленным элементом
        size--; // Уменьшаем размер списка на 1
        return;
    }

    Node* current = head; // Создаем указатель на начало списка
    for (int i = 0; i < pos - 1; i++) { // Двигаемся по списку до элемента, предшествующего удаляемому
        current = current->next;
    }

    Node* toDelete = current->next; // Создаем указатель на удаляемый элемент
    current->next = current->next->next; // Устанавливаем указатель на следующий элемент после удаляемого
    delete toDelete; // Удаляем узел из памяти
    size--; //Уменьшаем размер списка на 1
}

// Ищет элемент по значению
int LinkedList::find(int value) {
    Node* current = head; // Создаем указатель на начало списка
    int pos = 0; // Инициализируем номер позиции нулем
    while (current != nullptr && current->data != value) { // Пока указатель на текущий элемент не достигнет конца списка
        current = current->next; // Перемещаем указатель на следующий элемент списка
        pos++; // Увеличиваем номер позиции
    }
    if (current == nullptr) { // Если найден элемент со значением value
        return -1; // Если элемент со значением value не найден, возвращаем -1
    } else {
        return pos; // Возвращаем номер позиции
    }
}

// Возвращает элемент в заданной позиции
int LinkedList::get(int pos) {
    if (pos < 0 || pos >= size) { // Если позиция находится вне границ списка
        throw std::out_of_range("Invalid position"); // Выводим сообщение об ошибке
    }

    Node* current = head; // Создаем указатель на начало списка

    for (int i = 0; i < pos; i++) { // Перемещаем указатель на элемент с номером pos
        current = current->next;
    }

    return current->data; // Возвращаем значение элемента
}

// Выводит все элементы списка
void LinkedList::print() {
    Node* current = head; // Создаем указатель на начало списка

    while (current != nullptr) { // Пока указатель на текущий элемент не достигнет конца списка
        std::cout << current->data << " "; // Выводим значение текущего элемента списка
        current = current->next;  // Перемещаем указатель на следующий элемент списка
    }

    std::cout << std::endl;
}
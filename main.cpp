#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;
    int choice = 0;
    int value, position;

    while (choice != 9) {
        std::cout << std::endl;
        std::cout << "1. Append element" << std::endl;
        std::cout << "2. Prepend element" << std::endl;
        std::cout << "3. Insert element at position" << std::endl;
        std::cout << "4. Remove element by value" << std::endl;
        std::cout << "5. Remove element by position" << std::endl;
        std::cout << "6. Find element by value" << std::endl;
        std::cout << "7. Find element at position" << std::endl;
        std::cout << "8. Print all elements" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to append: ";
                std::cin >> value;
                list.append(value);
                break;
            case 2:
                std::cout << "Enter value to prepend: ";
                std::cin >> value;
                list.prepend(value);
                break;
            case 3:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                std::cout << "Enter position to insert: ";
                std::cin >> position;
                list.insert(value, position);
                break;
            case 4:
                std::cout << "Enter value to remove: ";
                std::cin >> value;
                list.remove(value);
                break;
            case 5:
                std::cout << "Enter position to remove: ";
                std::cin >> position;
                list.removeAt(position);
                break;
            case 6:
                std::cout << "Enter value to find: ";
                std::cin >> value;
                std::cout << "Element found at position: " << list.find(value) << std::endl;
                break;
            case 7:
                std::cout << "Enter position to find: ";
                std::cin >> position;
                std::cout << "Element at position: " << list.get(position) << std::endl;
                break;
            case 8:
                std::cout << "All elements: ";
                list.print();
                break;
            case 9:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice, try again." << std::endl;
                break;
        }
    }

    return 0;
}


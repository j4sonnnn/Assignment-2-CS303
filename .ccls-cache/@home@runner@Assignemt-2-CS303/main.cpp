#include <iostream>
#include "Single_header.h"
#include "Stack_header.h"

int main() {
    
    Stack myStack;

    // Push some numbers onto stack
    myStack.push(1);
    myStack.push(33);
    myStack.push(66);
    myStack.push(88);

    std::cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Top element: " << myStack.top() << std::endl;

    myStack.pop();
    std::cout << "After pop, top element: " << myStack.top() << std::endl;

    std::cout << "Average of stack elements: " << myStack.findAverage() << std::endl;

    // Test Single Linkedlist class
    SingleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    std::cout << "Front element of list: " << list.front() << std::endl;
    std::cout << "Back element of list: " << list.back() << std::endl;

    list.remove(2);
    std::cout << "After removing index 2, back element: " << list.back() << std::endl;

    return 0;
}

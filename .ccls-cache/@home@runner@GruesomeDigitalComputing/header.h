#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <iostream>

template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    bool empty() const;
    void insert(size_t index, const T& item);
    bool remove(size_t index);
    size_t find(const T& item) const;
};

#include "func.cpp" // Include implementation file
#endif

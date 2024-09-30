#ifndef SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_CPP

#include "header.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleLinkedList<T>::push_front(const T& item) {
    Node* new_node = new Node{item, head};
    head = new_node;
    if (!tail) tail = head;
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::push_back(const T& item) {
    Node* new_node = new Node{item, nullptr};
    if (tail) tail->next = new_node;
    tail = new_node;
    if (!head) head = tail;
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::pop_front() {
    if (head) {
        Node* old_head = head;
        head = head->next;
        delete old_head;
        num_items--;
        if (!head) tail = nullptr;
    }
}

template <typename T>
void SingleLinkedList<T>::pop_back() {
    if (head) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        num_items--;
    }
}

template <typename T>
T SingleLinkedList<T>::front() const {
    if (head) return head->data;
    throw std::out_of_range("List is empty");
}

template <typename T>
T SingleLinkedList<T>::back() const {
    if (tail) return tail->data;
    throw std::out_of_range("List is empty");
}

template <typename T>
bool SingleLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void SingleLinkedList<T>::insert(size_t index, const T& item) {
    if (index > num_items) return;
    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i)
            temp = temp->next;
        temp->next = new Node{item, temp->next};
        num_items++;
    }
}

template <typename T>
bool SingleLinkedList<T>::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
    } else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i)
            temp = temp->next;
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
        num_items--;
        if (temp->next == nullptr) tail = temp;
    }
    return true;
}

template <typename T>
size_t SingleLinkedList<T>::find(const T& item) const {
    Node* temp = head;
    size_t index = 0;
    while (temp) {
        if (temp->data == item) return index;
        temp = temp->next;
        index++;
    }
    return num_items;
}

#endif

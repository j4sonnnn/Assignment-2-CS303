#include "Stack_header.h"
#include <stdexcept> // Include this header for std::runtime_error

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

int Stack::top() const {
    if (!data.empty()) {
        return data.back();
    }
    throw std::runtime_error("Stack is empty");
}

bool Stack::isEmpty() const {
    return data.empty();
}

double Stack::findAverage() const {
    if (data.empty()) return 0.0;
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

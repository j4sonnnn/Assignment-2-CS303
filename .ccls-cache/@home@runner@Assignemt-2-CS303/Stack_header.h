#ifndef STACK_H
#define STACK_H

#include <vector>
#include <numeric> // For accumulate function

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    double findAverage() const;
};

#endif

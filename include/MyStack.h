// Copyright 2021 ch2oh
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <cstddef>
#include <vector>

template<typename T>
class MyStack {
private:
    std::vector<T> *stack;
    size_t size;

public:
    explicit MyStack(size_t t) : stack(new std::vector<T>()), size(t) {}

    MyStack(const MyStack<T> &toCopy) : size(toCopy.size) {
        stack = new std::vector<T>();
        for (T t : *toCopy.stack) stack->push_back(t);
    }

    ~MyStack() {
        delete stack;
    }

    T get() const {
        return stack->back();
    }

    T pop() {
        if (!isEmpty()) {
            T t = get();
            stack->pop_back();
            return t;
        }
        return 0;
    }

    void push(T x) {
        if (!isFull()) stack->push_back(x);
    }

    bool isFull() const {
        return stack->size() == size;
    }

    bool isEmpty() const {
        return stack->empty();
    }
};

#endif  // INCLUDE_MYSTACK_H_

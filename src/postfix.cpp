// Copyright 2021 ch2oh
#include "postfix.h"

std::string infix2postfix(const std::string &in) {
    MyStack<char> local(in.length() * 2);
    MyStack<char> out(in.length() * 2);
    bool flag = false;
    for (char token : in) {
        if (token == ' ') continue;
        if (token >= '0' && token <= '9' || token == '.') {
            if (flag) {
                out.push(' ');
                flag = false;
            }
            out.push(token);
            continue;
        } else {
            flag = true;
        }
        if (token == '(') {
            local.push(token);
            continue;
        }
        if (token == ')') {
            while (local.get() != '(') {
                out.push(' ');
                out.push(local.pop());
            }
            local.pop();
            continue;
        }
        if (token == '/' || token == '*' || token == '+' || token == '-') {
            if (token == '+' || token == '-') {
                while (!local.isEmpty() && local.get() != '(') {
                    out.push(' ');
                    out.push(local.pop());
                }
                local.push(token);
                continue;
            }
            while (!local.isEmpty() && local.get() != '(' &&
                    local.get() != '+' && local.get() != '-') {
                out.push(' ');
                out.push(local.pop());
            }
            local.push(token);
            continue;
        }
    }
    while (!local.isEmpty()) {
        out.push(' ');
        out.push(local.pop());
    }
    std::vector<char> a(1);
    while (!out.isEmpty()) {
        a.emplace(a.cbegin(), out.pop());
    }
    a.erase(a.cbegin());
    std::string out1 = &a[0];
    return out1;
}

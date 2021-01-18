// Copyright 2021 ch2oh
#include "postfix.h"

int main() {
    std::string c = "(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4";
    std::string polska = infix2prefix(c);
    std::cout << polska << std::endl;
    std::string c2 = "2 + 6 * 3 / (4 - 2)";
    std::string polska2 = infix2prefix(c2);
    std::cout << polska2 << std::endl;
    std::string c3 = "(1.1111 + 2.2222) / (3.3333 + 4.4444 * 6.7) - 5.3 * 4.4";
    std::string polska3 = infix2prefix(c3);
    std::cout << polska3 << std::endl;
}

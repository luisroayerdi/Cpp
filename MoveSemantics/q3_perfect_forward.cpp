// Question 3: std::forward and perfect forwarding
//
// `process` is overloaded on lvalue-ref vs rvalue-ref so we can observe,
// at runtime, whether an lvalue or rvalue argument reached it.
//
// `logAndProcess` should forward its argument to `process` such that:
//   logAndProcess(x)            -> calls process(lvalue)
//   logAndProcess(std::move(x)) -> calls process(rvalue)
//
// Fill in the TODO. Think about: what happens if you just pass `param`
// through unchanged (Item 25 -- why is that wrong even though param
// was bound to an rvalue)? What if you use std::move instead of
// std::forward here?

#include <iostream>
#include <utility>

void process(int& lvalArg) {
    std::cout << "process(lvalue)\n";
}

void process(int&& rvalArg) {
    std::cout << "process(rvalue)\n";
}

template <typename T>
void logAndProcess(T&& param) {
    std::cout << "calling process...\n";
    process(/* TODO: forward param correctly */);
}

int main() {
    int x = 5;
    logAndProcess(x);            // expect: process(lvalue)
    logAndProcess(std::move(x)); // expect: process(rvalue)
}

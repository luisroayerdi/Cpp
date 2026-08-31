// Question 1: Rvalue Reference vs. Universal Reference
//
// For EACH parameter declaration below, write a comment stating:
//   (a) is it a "universal reference" (aka forwarding reference) or a plain "rvalue reference"?
//   (b) WHY — what's the rule you're using to tell the difference? (Item 24)
//
// Do not run/compile this to find the answer — reason it out first from the
// type-deduction context of each declaration.

#include <vector>

// 1.
void f1(std::vector<int>&& v) {
    // your answer:
}

// 2.
template <typename T>
void f2(T&& param) {
    // your answer:
}

// 3.
template <typename T>
void f3(std::vector<T>&& param) {
    // your answer:
}

// 4.
auto f4 = [](auto&& param) {
    // your answer:
};

// 5.
template <typename T>
class Widget {
public:
    void f5(T&& param) {
        // your answer:
    }
};

// 6.
template <typename T>
void f6(const T&& param) {
    // your answer:
}

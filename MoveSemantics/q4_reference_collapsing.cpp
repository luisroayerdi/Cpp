// Question 4: Reference Collapsing (Item 28)
//
// Reference collapsing happens in four contexts: template instantiation,
// auto type deduction, typedef/using alias creation, and decltype.
//
// For each case below, write a comment giving:
//   (a) what T is deduced/set to
//   (b) what `param`'s actual type collapses down to (an lvalue ref or rvalue ref)
//
// Reminder of the two collapsing rules -- there are only two, state them
// yourself in a comment at the top before you start:
//   rule 1: & + anything -> ?
//   rule 2: && + && -> ?

// rule 1:
// rule 2:

#include <utility>

template <typename T>
void f(T&& param) {}

int main() {
    int x = 10;
    int& rx = x;
    int&& rrx = 10; // rrx itself is an lvalue with type int&&

    f(x);        // (a) T = ?   (b) param's type = ?
    f(rx);       // (a) T = ?   (b) param's type = ?
    f(std::move(x)); // (a) T = ?   (b) param's type = ?
    f(10);       // (a) T = ?   (b) param's type = ?

    // trickier: auto deduction follows the same rules as T&& template params
    auto&& a1 = x;          // (a) auto = ?  (b) a1's type = ?
    auto&& a2 = std::move(x); // (a) auto = ? (b) a2's type = ?
}

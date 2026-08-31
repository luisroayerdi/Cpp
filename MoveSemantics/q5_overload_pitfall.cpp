// Question 5: The danger of overloading on universal references (Item 26/27)
//
// Person has two constructors: one templated on a universal reference
// (meant for "construct from a name"), and one taking an int (meant for
// "construct from an index lookup").
//
// Part A: Before running anything, predict in a comment which constructor
// each call in main() invokes, and WHY (think about how overload
// resolution ranks an exact/template match vs. a call requiring a
// standard conversion).
//
// Part B: One of your predictions is almost certainly not what the class
// author intended. Fix Person so that `short` (and anything else
// implicitly convertible to int) reliably calls the int constructor,
// while string-ish arguments still go to the universal-reference
// constructor -- WITHOUT just removing the templated constructor.
// (Item 27 lists several techniques: pick one and implement it.)

#include <iostream>
#include <string>
#include <utility>

class Person {
public:
    template <typename T>
    explicit Person(T&& n) : name(std::forward<T>(n)) {
        std::cout << "templated ctor\n";
    }

    explicit Person(int idx) {
        std::cout << "int ctor (index lookup)\n";
    }

    // Part B: add whatever you need here (a deleted overload,
    // enable_if/concept constraint, tag dispatch, etc.)

private:
    std::string name;
};

int main() {
    Person p1("Nancy");   // prediction: ?
    short s = 5;
    Person p2(s);         // prediction: ?  <-- is this the one that surprises you?
    Person p3(5);         // prediction: ?
}

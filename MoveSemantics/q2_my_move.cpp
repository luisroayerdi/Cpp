// Question 2: Implement your own std::move
//
// std::move doesn't move anything -- it's an unconditional cast to an rvalue
// reference. Implement it yourself (Item 23 walks through std::move's
// actual implementation -- don't peek, derive it).
//
// Fill in the TODOs. You'll need <type_traits> for std::remove_reference.

#include <type_traits>
#include <iostream>
#include <utility> // only for the test harness's use of std::string, not for cheating via std::move

template <typename T>
/* TODO: return type */ myMove(T&& param) {
    // TODO: cast `param` to an rvalue of the correct type and return it.
}

// --- test harness, do not modify ---
struct Tracked {
    Tracked() { std::cout << "construct\n"; }
    Tracked(const Tracked&) { std::cout << "copy\n"; }
    Tracked(Tracked&&) noexcept { std::cout << "move\n"; }
};

int main() {
    Tracked a;
    Tracked b = myMove(a); // should print "move", not "copy"
}

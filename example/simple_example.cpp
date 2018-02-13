#include <iostream>

#include "lcsc.hpp"

int main() {
    auto r = lcsc::lcrng();
    for (int i = 0; i < 100; ++i) {
        std::cout << r.next() << "\n";
    }
}

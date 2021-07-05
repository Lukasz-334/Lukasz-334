#include <cmath>
#include <iostream>

typedef unsigned long long ull;

ull NWW(ull& lhs, ull& rhs) {
    ull a = std::max(lhs, rhs);
    ull b = std::min(lhs, rhs);

    ull c = a;

    if ((a == 0) || (b == 0)) {
        return 0;
    } else {
        while (a % b != 0) {
            a = a + c;
        }
        return a;
    }
}

int main() {
    ull numberOfTests = 0;
    ull numberOfNumbers = 0;
    ull numberX = 0;
    ull numberY = 0;
    ull nww = 0;
    std::cin >> numberOfTests;

    while (numberOfTests--) {

        std::cin >> numberOfNumbers;
        numberOfNumbers -= 2;
        std::cin >> numberX >> numberY;
        nww = NWW(numberX, numberY);

        while (numberOfNumbers--) {

            std::cin >> numberX;
            nww = NWW(nww, numberX);
        }
        std::cout<<nww<<'\n';
    }

    return 0;
}
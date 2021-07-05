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

void test(ull& sideX, ull& sideY, ull& sideZ) {
    if ((sideX < sideY + sideZ) && (sideY < sideZ + sideX) && (sideZ < sideX + sideY)) {
        std::cout << "TAK" << std::endl;
    } else {
        std::cout << "NIE" << std::endl;
    }
}

int main() {
    ull a, b, c, d, e, f;
    int numberOfTests = 0;
    char sign;
    ull nwwX = 0;
    ull nww = 0;
    ull sideA = 0;
    ull sideB = 0;
    ull sideC = 0;

    std::cin >> numberOfTests;
    while (numberOfTests--) {
        std::cin >> a >> sign >> b >> c >> sign >> d >> e >> sign >> f;
        if ((a % b == 0) && (c % d == 0) && (e % f == 0)) {
            sideA = a / b;
            sideB = c / b;
            sideC = e / f;
            test(sideA, sideB, sideC);
        } else if ((a % b == 0) && (c % d == 0)) {
            sideA = (a / b) * f;
            sideB = (c / b) * f;
            sideC = e;
            test(sideA, sideB, sideC);
        } else if ((a % b == 0) && (e % f == 0)) {
            sideA = (a / b) * d;
            sideC = (e / f) * d;
            sideB = c;
            test(sideA, sideB, sideC);
        } else if ((c % d == 0) && (e % f == 0)) {
            sideB = (c / d) * b;
            sideC = (e / f) * b;
            sideA = a;
            test(sideA, sideB, sideC);
        } else if (a % b == 0) {
            nww = NWW(d, f);
            sideB = (nww / d) * c;
            sideC = (nww / f) * e;
            sideA = (a / b) * nww;
            test(sideA, sideB, sideC);
        } else if (c % d == 0) {
            nww = NWW(b, f);
            sideA = (nww / b) * a;
            sideC = (nww / f) * e;
            sideB = (c / d) * nww;
            test(sideA, sideB, sideC);
        } else if (e % f == 0) {
            nww = NWW(b, d);
            sideA = (nww / b) * a;
            sideB = (nww / d) * c;
            sideC = (e / f) * nww;
            test(sideA, sideB, sideC);

        } else {
            nwwX = NWW(b, d);
            nww = NWW(nwwX, f);
            sideA = (nww / b) * a;
            sideB = (nww / d) * c;
            sideC = (nww / f) * e;
            test(sideA, sideB, sideC);
        }
    }
    return 0;
}

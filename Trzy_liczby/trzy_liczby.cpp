#include <cmath>
#include <iostream>
#include <vector>
typedef unsigned long long ull;

ull NWD(ull lhs, ull rhs) {
    ull r = 0;
    while (rhs > 0) {
        r = lhs % rhs;
        lhs = rhs;
        rhs = r;
    }
    return lhs;
}

ull NWW(ull lhs, ull rhs) {
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

struct Triangle {
    ull sideA = 0;
    ull sideB = 0;
    ull sideC = 0;

    Triangle(void);
    Triangle(ull x1, ull x2, ull x3) {
        sideA = x1;
        sideB = x2;
        sideC = x3;
    }

    bool triangleTest() {
        return ((sideA < sideB + sideC) && (sideB < sideC + sideA) && (sideC < sideA + sideB));
    }
};

void shorteningAFraction(std::vector<ull>& fract) {
    ull nwd = 0;
    nwd = NWD(fract[0], fract[1]);
    fract[0] = fract[0] / nwd;
    fract[1] = fract[1] / nwd;
    nwd = NWD(fract[2], fract[3]);
    fract[2] /= nwd;
    fract[3] /= nwd;
    nwd = NWD(fract[4], fract[5]);
    fract[4] /= nwd;
    fract[5] /= nwd;
}

int main() {
    std::vector<ull> side;
    side.reserve(6);
    int numberOfTests = 0;
    char sign;
    ull value = 0;
    ull nwwX = 0;
    ull nww = 0;
    ull sideX = 0;
    ull sideY = 0;
    ull sideZ = 0;

    std::cin >> numberOfTests;
    while (numberOfTests--) {
        for (int i = 0; i < 3; i++) {
            std::cin >> value >> sign;
            side.push_back(value);
            std::cin >> value;
            side.push_back(value);
        }

        if ((side[0] == 0) || (side[1] == 0) || (side[2] == 0) || (side[3] == 0) || (side[4] == 0) || (side[5] == 0)) {
            std::cout << "NIE" << std::endl;
        } else {
            shorteningAFraction(side);

            nwwX = NWW(side[1], side[3]);
            nww = NWW(nwwX, side[5]);
            sideX = (nww / side[1]) * side[0];
            sideY = (nww / side[3]) * side[2];
            sideZ = (nww / side[5]) * side[4];

            Triangle Test(sideX, sideY, sideZ);

            if (Test.triangleTest()) {
                std::cout << "TAK" << std::endl;
            } else {
                std::cout << "NIE" << std::endl;
            }
        }
        side.clear();
    }
    return 0;
}

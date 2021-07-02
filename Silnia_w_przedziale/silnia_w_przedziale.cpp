#include <algorithm>
#include <iostream>
#include <vector>
constexpr void fStrong(size_t* wi) {
    size_t silnia = 1;
    for (int i = 1; i <= 13; i++) {
        silnia = silnia * i;
        *(wi++) = silnia;
    }
}

int findA(const std::vector<size_t>& vec, size_t part) {
    int result = -1;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == part) {
            result = i;
            break;
        }
    }
    if (result != -1) {
        return result;
    }

    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > part) {
            result = i;
            break;
        }
    }
    return result;
}
int findB(const std::vector<size_t>& vec, size_t part) {
    int result = -1;
    int j = vec.size() - 1;

    for (int i = j; i >= 0; i--) {
        if (vec[i] == part) {
            result = i;
            break;
        }
    }
    if (result != -1) {
        return result;
    }
    for (int i = j; i >= 0; i--) {
        if (vec[i] < part) {
            result = i;
            break;
        }
    }
    return result;
}
int main() {
    std::vector<size_t> strong(14);
    size_t partingA = 0;
    size_t partingB = 0;
    int rangeX = 0;
    int rangeY = 0;
    int score = 0;
    strong[0] = 1;
    fStrong(&strong[1]);

    std::cin >> partingA;
    std::cin >> partingB;
    rangeX = findA(strong, partingA);
    rangeY = findB(strong, partingB);
    score = (rangeY - rangeX) + 1;
    std::cout << score << std::endl;

    return 0;
}
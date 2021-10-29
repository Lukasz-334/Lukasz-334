#include <bitset>
#include <iostream>
#include <string>

bool modulo(const std::string& bit_string) {
    std::bitset<1010> bit(bit_string);
    if (bit[0] == 1) {
        return false;
    }

    int sum = 0;

    for (int i = bit_string.size() - 1; i >= 0; i--) {
        sum = 2 * sum + bit[i];
        if (sum >= 5) {
            sum -= 5;
        }
    }
    return sum == 0;
}

int main() {
    int test = 0;
    std::string binary_num;
    std::cin >> test;

    while (test--) {
        std::cin >> binary_num;
        if (modulo(binary_num)) {
            std::cout << "Tak" << std::endl;
        } else {
            std::cout << "Nie" << std::endl;
        }
    }
}
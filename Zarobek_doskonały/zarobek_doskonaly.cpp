#include <algorithm>
#include <iostream>

void rangeFromZero(long long& value) {
    if (value < 0) {
        value = 0;
    }
}

int main() {
    int numberOfTest = 0;
    int numberOfDays = 0;
    std::cin >> numberOfTest;

    while (numberOfTest--) {
        std::cin >> numberOfDays;

        long long value;
        long long sum = 0;
        long long max_value = -20000;

        for (int i = 1; i <= numberOfDays; i++) {
            std::cin >> value;
            sum += value;

            max_value = std::max(sum, max_value);
            rangeFromZero(sum);
        }

        std::cout << max_value << std::endl;
    }
    return 0;
}

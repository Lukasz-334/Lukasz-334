#include <iostream>
#include <vector>

bool middleLargest(int a, int b, int c) {
    return (a < b && b > c);
}

int numberOfLargestMiddleNumbers() {
    int n;
    int counter = 0;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    for (int i = 1; i < n - 1; i++) {
        if (middleLargest(numbers[i - 1], numbers[i], numbers[i + 1])) {
            counter++;
        }
    }
    return counter;
}

int main() {
    std::cout << numberOfLargestMiddleNumbers() << std::endl;

    return 0;
}

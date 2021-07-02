#include <iostream>
#include <string>
#include <vector>

struct Jumper {
    std::string coordinateLetter = "x";
    int coordinateNumber{};
    using chess = std::vector<std::pair<std::string, int>>;
    chess coordinates_;

    Jumper() = default;
    Jumper(std::string coordinateX) {
        if (coordinateX.size() >= 2) {
            coordinateLetter = coordinateX[0];
            coordinateNumber = coordinateX[1] - 48;
        }
    }
    bool testLetter(std::string x) {
        return x[0] >= 97 && x[0] <= 104;
    }
    bool testNumer(int x) {
        return x >= 1 && x <= 8;
    }

    std::string modifycoordinateLetter(int size) {
        int sModify = static_cast<int>(coordinateLetter[0]);
        std::string value;
        if (size >= 0) {
            sModify += size;
        } else {
            sModify = sModify + size;
        }
        value = static_cast<char>(sModify);
        return value;
    }

    void createVector(std::string x1, int y1) {
        if ((testLetter(x1)) && (testNumer(y1))) {
            coordinates_.push_back(std::make_pair(x1, y1));
        }
    }

    void coordinates_jumper() {
        std::string letter;
        int number1 = coordinateNumber;
        int number2 = 0;

        createVector(coordinateLetter, coordinateNumber);

        letter = modifycoordinateLetter(1);
        number2 = number1 + 2;
        createVector(letter, number2);

        letter = modifycoordinateLetter(1);
        number2 = number1 - 2;
        createVector(letter, number2);

        letter = modifycoordinateLetter(2);
        number2 = number1 + 1;
        createVector(letter, number2);

        letter = modifycoordinateLetter(2);
        number2 = number1 - 1;
        createVector(letter, number2);

        letter = modifycoordinateLetter(-1);
        number2 = number1 + 2;
        createVector(letter, number2);

        letter = modifycoordinateLetter(-1);
        number2 = number1 - 2;
        createVector(letter, number2);

        letter = modifycoordinateLetter(-2);
        number2 = number1 + 1;
        createVector(letter, number2);

        letter = modifycoordinateLetter(-2);
        number2 = number1 - 1;
        createVector(letter, number2);
    }
    void print() {
        std::cout << coordinateLetter << coordinateNumber << std::endl;
    }
};

int main() {
    std::string coordinateX;
    std::string coordinateY;
    std::cin >> coordinateX;
    std::cin >> coordinateY;

    Jumper first(coordinateX);
    Jumper second(coordinateY);
    first.coordinates_.reserve(9);
    second.coordinates_.reserve(2);
    first.coordinates_jumper();
    second.createVector(second.coordinateLetter, second.coordinateNumber);

    bool judge = true;
    for (auto x : first.coordinates_) {
        if ((x.first == second.coordinateLetter) && (x.second == second.coordinateNumber)) {
            std::cout << "TAK" << std::endl;
            judge = false;
            break;
        }
    }
    if (judge) {
        std::cout << "NIE" << std::endl;
    }

    return 0;
}
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void changeToBig(std::string& word) {
    for (auto& sign : word) {
        sign = toupper(sign);
    }
}

int main() {
    std::map<std::string, int> base;
    std::vector<std::pair<std::string, int>> base2;
    base2.reserve(100'001);

    std::string nr;
    std::string surname;
    std::string name;

    while (std::cin >> nr) {
        std::cin >> surname;
        std::cin >> name;
        changeToBig(name);
        base[name]++;
    }
    for (auto x : base) {
        base2.push_back(make_pair(x.first, x.second));
    }
    sort(base2.begin(), base2.end(), [](const std::pair<std::string, int>& x, const std::pair<std::string, int>& y) {
        if (x.second != y.second)
            return x.second > y.second;
        else
            return x.first < y.first;
    });

    for (auto x : base2) {
        std::cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}

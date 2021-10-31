#include <iostream>
#include <iterator>
#include <set>

void edgeGenerator(std::set<int>& edgeSet) {
    for (int i = 1; i <= 14143; i++) {
        int x = ((i * i) - i) / 2;

        edgeSet.insert(x);
    }
}

bool graftest(const std::set<int>& edgeSet, int numberCon) {
    auto it = edgeSet.find(numberCon);
    return it != edgeSet.end();
}

int main() {
    std::set<int> Connections;
    edgeGenerator(Connections);
    int numberOfConnections = 0;
    int numberOfTest = 0;
    std::cin >> numberOfTest;

    while (numberOfTest--) {
        std::cin >> numberOfConnections;
        if (graftest(Connections, numberOfConnections)) {
            std::cout << "TAK" << '\n';
        } else {
            std::cout << "NIE" << '\n';
        }
    }

    return 0;
}

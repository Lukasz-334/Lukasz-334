    #include <algorithm>
    #include <iostream>
    #include <vector>
     
    std::vector<unsigned long long> theLargestSide(
        const std::vector<unsigned long long>& side) {
        std::vector<unsigned long long> results;
        unsigned long long temp = 0;
     
        for (size_t i = 0; i < side.size(); i++) {
            if (i + 1 < side.size()) {
                temp = side[i + 1] - side[i];
                results.push_back(temp);
            }
        }
        std::sort(results.rbegin(), results.rend());
        return results;
    }
     
    unsigned long long numberOfMax(const std::vector<unsigned long long>& A) {
        unsigned long long max = 1;
        unsigned long long el = A[0];
     
        for (size_t i = 1; i < A.size(); i++) {
            if (A[i] == el) {
                max++;
            } else {
                break;
            }
        }
        return max;
    }
     
    int main() {
        unsigned long long sideA = 0;
        unsigned long long sideB = 0;
        long long cuts = 0;
        std::vector<unsigned long long> cutsA(1, 0);
        std::vector<unsigned long long> cutsB(1, 0);
        int numberOfCuts = 0;
     
        std::cin >> sideA >> sideB >> numberOfCuts;
        cutsA.push_back(sideA);
        cutsB.push_back(sideB);
     
        while (numberOfCuts--) {
            std::cin >> cuts;
     
            if (cuts < 0) {
                cutsA.push_back(-cuts);
            } else {
                cutsB.push_back(cuts);
            }
        }
        std::sort(cutsA.begin(), cutsA.end());
        std::sort(cutsB.begin(), cutsB.end());
     
        cutsA = theLargestSide(cutsA);
        cutsB = theLargestSide(cutsB);
        std::cout << cutsA[0] * cutsB[0] << ' ';
        std::cout << numberOfMax(cutsA) * numberOfMax(cutsB) << std::endl;
     
        return 0;
    } 
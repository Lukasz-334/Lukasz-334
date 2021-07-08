#include <string.h>
#include <iostream>
#include <set>
#include <string>

int main() {
    std::multiset<std::string> set[2];
    int number_of_test = 0;
    int number_of_words = 0;
    char word[7];

    std::cin >> number_of_words;
    std::cin >> number_of_test;

    while (number_of_words--) {
        scanf("%s", word);

        if (strlen(word) == 6) {
            set[0].insert(word);
        } else {
            set[1].insert(word);
        }
    }

    while (number_of_test--) {
        scanf("%s", word);

        if (strlen(word) == 6) {
            int s = set[0].count(word);
            if (s == 0) {
                printf("BRAK \n");
            } else {
                printf("%d \n", s);
            }
        } else {
            int s = set[1].count(word);
            if (s == 0) {
                printf("BRAK \n");
            } else {
                printf("%d \n", s);
            }
        }
    }

    return 0;
}

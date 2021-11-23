#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class GildiaMember {
public:
    std::string name_;
    int level_;
    float factor_;

    GildiaMember(std::string name, int level, float factor)
        : name_(name), level_(level), factor_(factor){};
};

class Gildia {
public:
    std::string name_;
    int numberPoints_;
    int numberOfPlayers_;

    Gildia(std::string name, int point, int nPlayers)
        : name_(name), numberPoints_(point), numberOfPlayers_(nPlayers){};
    std::vector<std::shared_ptr<GildiaMember>> gildiaMember;

    void sortGildiaMember() {
        std::sort(gildiaMember.begin(), gildiaMember.end(),
                  [](std::shared_ptr<GildiaMember>& first,
                     std::shared_ptr<GildiaMember>& second) {
                      if (first->level_ != second->level_) {
                          return first->level_ > second->level_;
                      }
                      if (first->factor_ != second->factor_) {
                          return first->factor_ > second->factor_;
                      }
                      return first->name_ < second->name_;
                  });
    }

    void print() {
        std::cout << name_ << ':' << std::endl;
        for (auto ptr : gildiaMember) {
            std::cout << ptr->name_ << std::endl;
        }
    }
};

void sortGildiaMem(std::vector<Gildia>& Gild) {
    for (size_t i = 0; i < Gild.size(); i++) {
        Gild[i].sortGildiaMember();
    }
}

void sortGildie(std::vector<Gildia>& Gild) {
    std::sort(Gild.begin(), Gild.end(), [](Gildia& first, Gildia& second) {
        if (first.numberPoints_ != second.numberPoints_) {
            return first.numberPoints_ > second.numberPoints_;
        }

        if (first.numberOfPlayers_ != second.numberOfPlayers_) {
            return first.numberOfPlayers_ > second.numberOfPlayers_;
        }

        return first.name_ < second.name_;
    });
}

void Print(const std::vector<Gildia>& Gild) {
    for (auto g : Gild) {
        g.print();
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Gildia> Gildie;
    int numberOfGildia = 0;
    std::string name_gildia;
    int pkt = 0;
    int gildiaMem = 0;
    std::string name;
    int level;
    float factor;

    std::cin >> numberOfGildia;
    for (int i = 0; i < numberOfGildia; i++) {
        std::cin >> name_gildia >> pkt >> gildiaMem;

        Gildie.push_back(Gildia(name_gildia, pkt, gildiaMem));

        while (gildiaMem--) {
            std::cin >> name >> level >> factor;
            Gildie[i].gildiaMember.push_back(
                std::make_shared<GildiaMember>(name, level, factor));
        }
    }

    sortGildiaMem(Gildie);
    sortGildie(Gildie);
    Print(Gildie);

    return 0;
}

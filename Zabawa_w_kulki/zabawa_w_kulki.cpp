#include <cmath>
#include <iostream>
const long double EPS = 10e-9;

class Point {
public:
    long double coordinateX;
    long double coordinateY;

    Point(int x1 = 0, int y1 = 0)
        : coordinateX(x1),
          coordinateY(y1) {}
};

class Player {
public:
    std::string name;
    int hit_throws;

    Player(std::string n = "", int ht = 0);
    void print() {
        std::cout << name << ' ' << hit_throws;
    }
};

Player::Player(std::string n, int ht)
    : name(n), hit_throws(ht) {}

bool PointInsideCircle(Point& target, long double radius2, Point& players) {
    long double a = sqrt(pow(target.coordinateX - players.coordinateX, 2) + pow(target.coordinateY - players.coordinateY, 2)) - EPS;

    return a < radius2;
}

int main() {
    long double coordinate_x = 0;
    long double coordinate_y = 0;
    long double radius = 0;
    long double coordinate_palyer_x;
    long double coordinate_palyer_y;
    int number_of_throws = 0;
    int number_of_players = 0;
    std::string player_name;
    int number_of_points = 0;
    int begin_point = -1;
    Player winner;

    std::cin >> coordinate_x;
    std::cin >> coordinate_y;
    std::cin >> radius;
    std::cin >> number_of_throws;
    std::cin >> number_of_players;

    Point Bowl(coordinate_x, coordinate_y);

    while (number_of_players--) {
        std::cin >> player_name;

        for (int i = 0; i < number_of_throws; i++) {
            std::cin >> coordinate_palyer_x;
            std::cin >> coordinate_palyer_y;

            Point player(coordinate_palyer_x, coordinate_palyer_y);

            if (PointInsideCircle(Bowl, radius, player) == true) {
                number_of_points++;
            }
        }
        if (number_of_points > begin_point) {
            winner.name = player_name;
            winner.hit_throws = number_of_points;
            begin_point = number_of_points;
        }
        number_of_points = 0;
    }

    winner.print();

    return 0;
}

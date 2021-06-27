#include <cmath>
#include <iostream>

const long double EPS = 10e-9;

class Point {
private:
    long double coordinateX;
    long double coordinateY;

public:
    Point(long double x1 = 0.0L, long double y1 = 0.0L)
        : coordinateX(x1),
          coordinateY(y1) {}

    void setcoordinateX(long double cx) {
        coordinateX = cx;
    }
    void setcoordinateY(long double cy) {
        coordinateY = cy;
    }

    long double getcoordinateX() {
        return coordinateX;
    }
    long double getcoordinateY() {
        return coordinateY;
    }
};

bool PointInsideCircle(Point& wiper, const long double& radius2, Point& Case) {
    long double el = sqrt(pow(wiper.getcoordinateX() - Case.getcoordinateX(), 2) + pow(wiper.getcoordinateY() - Case.getcoordinateY(), 2)) - EPS;

    return el < radius2;
}

int main() {
    long double theCenterX = 0.0L;
    long double theCenterY = 0.0L;
    long double radius = 0.0L;
    long double x = 0.0L;
    long double y = 0.0L;
    int numberOfCases = 0;
    int missedCases = 0;

    std::cin >> theCenterX;
    std::cin >> radius;
    std::cin >> numberOfCases;

    Point wiper(theCenterX, theCenterY);
    Point Case;

    while (numberOfCases--) {
        std::cin >> x;
        std::cin >> y;
        Case.setcoordinateX(x);
        Case.setcoordinateY(y);
        if (PointInsideCircle(wiper, radius, Case) == false) {
            missedCases++;
        }
    }

    std::cout << missedCases << std::endl;

    return 0;
}
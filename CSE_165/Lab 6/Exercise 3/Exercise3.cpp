#include <iostream>
#include <vector>
#include "Rect.h"
#include "Vec.h"

int main() {
    std::vector<Rect> rectangles;

    // Read rectangles
    std::cout << "Type 4 floats to define a rectangle: ";
    while (true) {
        float x, y, width, height;
        // std::cout << "Type 4 floats to define a rectangle: ";
        std::cin >> x >> y >> width >> height;
        if (x < 0 && y < 0 && width < 0 && height < 0) {
            break;
        }
        Rect rect(x, y, width, height);
        rectangles.push_back(rect);
        std::cout << "Type 4 floats to define the next rectangle: ";
    }

    // Read points
    float x, y;
    std::cout << "\nType 2 floats to define a point: ";
    bool first_point = true;
    while (std::cin >> x >> y) {
        if (x == -99.0f && y == -99.0f) {
            break;
        }

        bool is_inside = true;
        for (int i = 0; i < rectangles.size(); i++) {
            if (!rectangles[i].contains(Vec(x, y))) {
                is_inside = false;
                std::cout << "The point is OUTSIDE of rectangle " << i << std::endl;
            } else {
                std::cout << "The point is INSIDE of rectangle " << i << std::endl;
            }
        }
        if (first_point) {
            std::cout << "\nType 2 floats to define the next point: ";
            first_point = false;
        } else {
            std::cout << "\nType 2 floats to define the next point: ";
        }
    }

    std::cout << "Finished!" << std::endl;
    return 0;
}

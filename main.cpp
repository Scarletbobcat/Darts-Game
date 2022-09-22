#include <iostream>
#include <vector>
#include "point.h"
#include "fraction.h"
using namespace std;

//This will take the polygons as a parameter and calculate the area of the polygon through cross product
Fraction areaOfPolygon(std::vector<std::vector<Point>> &polygons, int poly){
    Fraction temp(1, 2);
    Fraction total;
    int i;
    Point k, j;
    for (i = 0; i < polygons[poly].size() - 1; i++){
        k = polygons[poly][i];
        j = polygons[poly][i+1];
        total = total + k * j;
    }
    total = total + polygons[poly].back() * polygons[poly][0];
    return (temp * (total));
}

bool intersect(Point p1, Point p2, Point q1, Point q2, Point &x){
    Fraction t, u;
    Point r = p1 - p2;
    Point s = q1 - q2;

    Point v = q1 - p1;
    Fraction d = r * s;
    if (d != 0){
        t = (v * s)/(d);
        if ((t > 0 && t < 1) && (u > 0 && u < 1)){
            x = r * t;
            return true;
        }
    }
    return false;
}

bool isInside(Point p, Point c, std::vector<Point> &polygons[100]){
    int w = 0;
    Point v1 = new Point(p.x, 0);
    Point v2 = new Point (p.x, c.y);

    Point h1 = new Point(0, p.y);
    Point h2 = new Point (c.x, p.y);

    for (int i = 1; i < k; i++){

    }

}

int main() {

    //Declarations of all variables
    Point dartboard;
//    Fraction score;
    vector<Point> darts;
    int numDarts, numPolygons;
    int numVertices[100];
    vector<Point> polygons[100];

    //This code block gets the inputs from the user and saves them into variables
    cin >> dartboard;
    cin >> numPolygons;
    for (int k = 0; k < numPolygons; k++) {
        cin >> numVertices[k];

        for (int i = 0; i < numVertices[k]; i++) {
            Point temp;
            cin >> temp;
            polygons[k].emplace_back(temp);
        }
    }
    cin >> numDarts;
    for (int i = 0; i < numDarts; i++){
        Point temp;
        cin >> temp;
        darts.emplace_back(temp);
    }

    //Calculations


    return 0;
}

#include <iostream>
#include "point.h"
#include "fraction.h"
using namespace std;

//This will take the polygons as a parameter and calculate the area of the polygon through cross product
Fraction areaOfPolygon(Point (&polygons)[100][20], int poly, int vertices){
    Fraction temp(1, 2);
    Fraction total(0,1);
    int i;
    Point k, j;
    for (i = 0; i < vertices - 1; i++){
        k = polygons[poly][i];
        j = polygons[poly][i+1];
        total = total + k * j;
    }
    total = total + polygons[poly][vertices-1] * polygons[poly][0];
    return (temp * (total));
}

bool intersect(Point p1, Point p2, Point q1, Point q2, Point &x){
    Fraction t, u, zero1;
    Point zero;
    Point r = p2 - p1;
    Point s = q2 - q1;
    x = zero;
    Point v = q1 - p1;
    Fraction d = r * s;
    if (d != zero1){
        t = (v * s)/(d);
        u = (v * r)/(d);
        if ((t > 0 && t < 1) && (u > 0 && u < 1)){
            x = p1 + r * t;
            return true;
        }
    }
    return false;
}

bool isInside(Point dart, Point c, Point (&polygons)[100][20], int numVertices, int poly){
    int w = 0;
    Fraction zero;
    Point below(dart.getX(), zero);
    Point above(dart.getX(), c.getY());

    Point left(0, dart.getY());
    Point right(c.getX(), dart.getY());
    Point z1, z2, x;

    for (int i = 0; i < numVertices; i++){
        if (i == numVertices - 1) {
            if(intersect(below, above, polygons[poly][i], polygons[poly][0], x)) {
                z1 = x - dart;
                z2 = polygons[poly][0] - polygons[poly][i];
                if ((z1.getY() * z2.getX()) < zero){
                    w += 1;
                }else {
                    w -= 1;
                }
            }
            if(intersect(left, right, polygons[poly][i], polygons[poly][0], x)) {
                z1 = x - dart;
                z2 = polygons[poly][0] - polygons[poly][i];
                if ((z1.getX() * z2.getY()) > zero) {
                    w += 1;
                }else{
                    w -= 1;
                }
            }
        }else {
            if(intersect(below, above, polygons[poly][i], polygons[poly][i+1], x)) {
                z1 = x - dart;
                z2 = polygons[poly][i+1] - polygons[poly][i];
                if ((z1.getY() * z2.getX()) < zero){
                    w += 1;
                }else {
                    w -= 1;
                }
            }
            if(intersect(left, right, polygons[poly][i], polygons[poly][i+1], x)) {
                z1 = x - dart;
                z2 = polygons[poly][i+1] - polygons[poly][i];
                if ((z1.getX() * z2.getY()) > zero) {
                    w += 1;
                }else{
                    w -= 1;
                }
            }
        }
    }
    if (w == 0){
        return false;
    }else {
        return true;
    }
}

int main() {

    //Declarations of all variables
    Point dartboard, darts;
    Fraction score;
    bool ifDartScore[10][100];
    int numDarts, numPolygons;
    int numVertices[100];
    Point polygons[100][20];

    for (int i=0; i<10; i++) {
        for (int k=0; k<100; k++) {
            ifDartScore[i][k] = false;
        }
    }

    //This code block gets the inputs from the user and saves them into variables
    cin >> dartboard;
    Fraction dartboardArea(dartboard.getX() * dartboard.getY());
    cin >> numPolygons;
    for (int k = 0; k < numPolygons; k++) {
        cin >> numVertices[k];
        for (int i = 0; i < numVertices[k]; i++) {
            Point temp;
            cin >> temp;
            polygons[k][i] = temp;
        }
    }
    cin >> numDarts;
    for (int i = 0; i < numDarts; i++) {
        cin >> darts;
        cout << "Dart: " << darts;
        for (int k = 0; k < numPolygons; k++) {
            ifDartScore[i][k] = isInside(darts, dartboard, polygons, numVertices[k], k);
        }
    }

    for (int i = 0; i < numDarts; i++) {
        for (int h = 0; h < sizeof(ifDartScore[i]); h++) {
            while (int j = 1 < numDarts){
                if (ifDartScore[i][h] && ifDartScore[i][h] == ifDartScore[j][h]) {
                    ifDartScore[i][h] = false;
                }
                j++;
            }
            if (ifDartScore[i][h]) {
                score = score + (dartboardArea/areaOfPolygon(polygons, h, numVertices[h]));
            }
        }
    }
    cout << "Score: " << score << endl;
    return 0;
}
#ifndef GEOMETRY_H
#define GEOMETRY_H

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
// SQUARE(2) 2*2 --> 4
// SQUARE(2+2) 2+2 * 2+2 --> 8

typedef struct Point
{
    float x;
    float y;
} Point;

typedef struct Circle
{
    Point center;
    float radius;
} Circle;

Point createPoint(float x, float y);
Circle createCircle(float centerX, float centerY, float radius);

float calculateDistance(Point p1, Point p2);
float calculateCircleArea(Circle c);
float calculateCirclePerimeter(Circle c);

int checkPointCirclePosition(Point p, Circle c);

#endif
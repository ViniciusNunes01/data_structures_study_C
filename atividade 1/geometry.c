#include "geometry.h"
#include <math.h>

Point createPoint(float x, float y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Circle createCircle(float centerX, float centerY, float radius)
{
    Circle c;
    c.center = createPoint(centerX, centerY);
    c.radius = radius;
    return c;
}

float calculateDistance(Point p1, Point p2)
{
    return sqrt(SQUARE(p1.x - p2.x) + SQUARE(p1.y - p2.y));
}

float calculateCircleArea(Circle c)
{
    return PI * SQUARE(c.radius);
}

float calculateCirclePerimeter(Circle c)
{
    return 2 * PI * c.radius;
}

int checkPointCirclePosition(Point p, Circle c)
{
    float distance = calculateDistance(p, c.center);

    // Margem de tolerância
    float epsilon = 0.0001;

    if (distance < (c.radius - epsilon))
    {
        return -1; // Ponto interno
    }
    else if (distance > (c.radius + epsilon))
    {
        return 1; // Ponto externo
    }
    else
    {
        return 0; // Ponto pertencente à circunferência
    }
}
#include "vector2d.h"

void Vector2D::add(const Vector2D& right)
{
    x+=right.x;y+=right.y;
}

void Vector2D::multiple(int s)
{
    x*=s;y*=s;
}

int Vector2D::skalar(const Vector2D& a)
{
    return x*a.x+y*a.y;
}

bool Vector2D::isMeroleges(const Vector2D& a)
{
    return !skalar(a);
}
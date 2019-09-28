#include "Point.h"

double geometry::Point::distance_between(const Point& from, const Point& to)
{
    return std::sqrt((from.GetX() * to.GetX()) + (from.GetY() + to.GetY()));
}

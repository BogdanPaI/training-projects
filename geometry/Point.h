#ifndef POINT_H
#define POINT_H

#include <cmath>

namespace geometry 
{
    class Point 
    {
    private:
        double _x;
        double _y;
    public:
        inline Point() { _x = 0.0; _y = 0.0; }
        inline Point(double x, double y) { _x = x; _y = y; }
        inline double GetX() const { return _x; }
        inline double GetY() const { return _y; }
        inline void SetX(double x) { _x = x; }
        inline void SetY(double y) { _y = y; }
        double distance_between(const Point& from, const Point& to);
    };
}
#endif // #ifndef POINT_H
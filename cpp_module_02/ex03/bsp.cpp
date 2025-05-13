#include "Point.hpp"

static Fixed    cross(const Point& a, const Point& b, const Point& c)   {
    return (b.getX() - a.getX()) * (c.getY() - a.getY())
         - (b.getY() - a.getY()) * (c.getX() - a.getX());
}
// 2D cross product (b - a) x (c - a)

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed   d1 = cross(point, a, b);
    Fixed   d2 = cross(point, b, c);
    Fixed   d3 = cross(point, c, a);
    bool    has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool    has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
    return !(has_neg && has_pos) && (d1 != Fixed(0) && d2 != Fixed(0) && d3 != Fixed(0));
}
// point is inside only if all cross products have same non-zero sign
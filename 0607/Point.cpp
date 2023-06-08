#include "Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y)
{
}

void Point::ShowPosition() const
{
    cout << '[' << xpos << ", " << ypos << ']' << endl;
}

ostream& operator<<(ostream& os, const Point& pos)
{
    os << '[' << pos.xpos << ", "<< pos.ypos << ']' << endl;
    return os;
}

istream& operator>>(istream& is, Point& pos)
{
    is >> pos.xpos >> pos.ypos;
    fflush(stdin);
    return is;
}

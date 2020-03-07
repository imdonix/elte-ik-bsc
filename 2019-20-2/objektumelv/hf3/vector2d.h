#ifndef V2D_INCLUDED
#define V2D_INCLUDED

#include <iostream>

class Vector2D
{
    private:
        int x;
        int y;
    public:
        Vector2D(int _x, int _y){ x = _x; y = _y;}
        friend std::ostream& operator<< (std::ostream &s, const Vector2D &v)
        {
        s << "(" << v.x << " , " << v.y << ")";
        return s;
        }
        int skalar(const Vector2D& a);
        void multiple(int s);
        void add(const Vector2D& right);
        bool isMeroleges(const Vector2D& a);
};

#endif
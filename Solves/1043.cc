// https://acm.timus.ru/problem.aspx?space=1&num=1043 

#include <iostream>
#include <cmath>

using ld = long double;
const ld eps = 1e-9;

struct point {
    ld x, y;
    point operator-(const point& p) const { return { x-p.x, y-p.y }; };
    bool operator%(const point& p) const { return x*p.y - p.x*y > 0; }
};

int main() {
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int A = 2*(x1-x2), B = 2*(y1-y2), C = 2*(x1-x3), D = 2*(y1-y3);
    int E = x1*x1 - x2*x2 + y1*y1 - y2*y2, F = x1*x1 - x3*x3 + y1*y1 - y3*y3;

    ld cy = (A*F - C*E)/ld(A*D-B*C), cx = (D*E - B*F)/ld(A*D-B*C);
    ld r = std::sqrt((x1-cx)*(x1-cx) + (y1-cy)*(y1-cy));

    point c { cx, cy };
    point v1 = { x1-cx, y1-cy };
    point v2 = { x2-cx, y2-cy };
    point v3 = { x3-cx, y3-cy };

    bool inside = (v1 % v3) == (v1 % v2) && (v3 % v2) == (v1 % v2);

    point pts[4] = { { cx, cy+r }, { cx, cy-r }, { cx-r, cy }, { cx+r, cy } };
    point m { static_cast<ld>(std::min(x1, x2)), static_cast<ld>(std::min(y1, y2)) },
          M { static_cast<ld>(std::max(x1, x2)), static_cast<ld>(std::max(y1, y2)) };

    for(int i = 0; i < 4; i++) {
        point diff = pts[i] - c;
        if((v1 % diff == v1 % v2 && diff % v2 == v1 % v2) == inside) {
            m.x = std::min(m.x, pts[i].x);
            m.y = std::min(m.y, pts[i].y);
            M.x = std::max(M.x, pts[i].x);
            M.y = std::max(M.y, pts[i].y);
        }
    }

    auto W = std::ceil(M.x-eps) - std::floor(m.x+eps);
    auto H = std::ceil(M.y-eps) - std::floor(m.y+eps);
    std::cout << int(W) * int(H);
}

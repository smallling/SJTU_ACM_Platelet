#include <cmath>

using num = long double;
const num eps = 1e-4;

num sqr(num x) {
    return x * x;
}

int sgn(num x) {
    return (x > eps) - (x < -eps);
}

int sgn(num x, num y) {
    return sgn(x - y);
}

struct point {
    num x, y;

    explicit point(num x = 0, num y = 0) : x(x), y(y) {}
    
    num len2() {
        return sqr(x) + sqr(y);
    }
    num len() {
        return std::sqrt(len2());
    }

    // counterclockwise
    point turn90() {
        return point(-y, x);
    }

    point norm() {
        return point(x / len(), y / len());
    }

    friend bool operator ==(const point &a, const point &b) {
        return !sgn(a.x, b.x) && !sgn(a.y, b.y);
    }
    friend point operator +(const point &a, const point &b) {
        return point(a.x + b.x, a.y + b.y);
    }
    friend point operator -(const point &a, const point &b) {
        return point(a.x - b.x, a.y - b.y);
    }
    friend point operator *(const point &a, const num &b) {
        return point(a.x * b, a.y * b);
    }
    friend point operator /(const point &a, const num &b) {
        return point(a.x / b, a.y / b);
    }
    // det
    friend num operator *(const point &a, const point &b) {
        return a.x * b.y - a.y * b.x;
    }
    // dot
    friend num operator ^(const point &a, const point &b) {
        return a.x * b.x + a.y * b.y;
    }
};

// AB * AC
num det(point a, point b, point c) {
    return (b - a) * (c - a);
}

// AB dot AC
num dot(point a, point b, point c) {
    return (b - a) ^ (c - a);
}

num dis2(point a, point b) {
    return (b - a).len2();
}

num dis(point a, point b) {
    return (b - a).len();
}

struct line {
    point a, b;

    explicit line(point a = point(), point b = point()) : a(a), b(b) {}

    point v() {
        return b - a;
    }
};

bool onLine(point p, line l) {
    return sgn((l.a - p) * (l.b - p)) == 0;
}

bool onSeg(point p, line l) {
    return onLine(p, l) && sgn((l.b - l.a) ^ (p - l.a)) >= 0 && sgn((l.a - l.b) ^ (p - l.b)) >= 0;
}

bool parallel(line a, line b) {
    return sgn(a.v() * b.v()) == 0;
}

point intersection(line a, line b) {
    num s1 = det(a.a, a.b, b.a);
    num s2 = det(a.a, a.b, b.b);
    return (b.a * s2 - b.b * s1) / (s2 - s1);
}

// projection of p on l
point project(point p, line l) {
    return l.a + l.v() * ((p - l.a) ^ l.v()) / l.v().len2();
}

num dis(point p, line l) {
    return std::abs((p - l.a) * l.v()) / l.v().len();
}

// unchecked
int main() {
    return 0;
}

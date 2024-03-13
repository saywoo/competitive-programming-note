
typedef long long int ll;

// Fraction(a, b) = a / b    (b != 0)
struct Fraction {
    ll x, y;
    Fraction(ll x = 0, ll y = 1) { this->x = x; this->y = y; }
    Fraction operator+(const Fraction &f) const {
        ll temp = lcm(y, f.y);
        Fraction res = {temp / y * x + temp / f.y * f.x, temp};
        temp = gcd(res.x, res.y);
        res = {res.x / temp, res.y / temp};
        return res;
    }
    Fraction operator-(const Fraction &f) const {
        ll temp = lcm(y, f.y);
        Fraction res = {temp / y * x - temp / f.y * f.x, temp};
        temp = gcd(res.x, res.y);
        res = {res.x / temp, res.y / temp};
        return res;
    }
    Fraction operator*(const Fraction &f) const {
        Fraction res = {x * f.x, y * f.y};
        ll temp = gcd(res.x, res.y);
        res = {res.x / temp, res.y / temp};
        return res;
    }
    Fraction operator/(const Fraction &f) const {
        Fraction res = {x * f.y, y * f.x};
        ll temp = gcd(res.x, res.y);
        res = {res.x / temp, res.y / temp};
        return res;
    }
    bool operator<(const Fraction &f) const {
        __int128_t a = x * f.y, b = y * f.x;
        return a < b;
    }
    bool operator>(const Fraction &f) const {
        __int128_t a = x * f.y, b = y * f.x;
        return a > b;
    }
    bool operator<=(const Fraction &f) const {
        __int128_t a = x * f.y, b = y * f.x;
        return a <= b;
    }
    bool operator>=(const Fraction &f) const {
        __int128_t a = x * f.y, b = y * f.x;
        return a >= b;
    }
    bool operator==(const Fraction &f) const {
        __int128_t a = x * f.y, b = y * f.x;
        return a == b;
    }
};